#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <winsock2.h>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

const int PORT = 12345;

class GuessMessage {
public:
    std::string word;
    int attemptsLeft;
};

class Server {
public:
    Server() {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "Failed to initialize Winsock." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == INVALID_SOCKET) {
            std::cerr << "Error creating socket." << std::endl;
            WSACleanup();
            std::exit(EXIT_FAILURE);
        }

        sockaddr_in serverAddress{};
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons(PORT);

        if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == SOCKET_ERROR) {
            std::cerr << "Error binding socket." << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            std::exit(EXIT_FAILURE);
        }

        if (listen(serverSocket, 5) == SOCKET_ERROR) {
            std::cerr << "Error listening on socket." << std::endl;
            closesocket(serverSocket);
            WSACleanup();
            std::exit(EXIT_FAILURE);
        }

        wordOfTheDay = getRandomWord();
        lastUpdateTime = std::chrono::steady_clock::now();

        std::cout << "Server started. Waiting for connections..." << std::endl;
    }

    ~Server() {
        closesocket(serverSocket);
        WSACleanup();
    }

    void run() {
        while (true) {
            sockaddr_in clientAddress{};
            int clientAddressLen = sizeof(clientAddress);

            SOCKET clientSocket = accept(serverSocket, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddressLen);
            if (clientSocket == INVALID_SOCKET) {
                std::cerr << "Error accepting connection." << std::endl;
                continue;
            }

            std::cout << "Client connected!" << std::endl;

            handleClient(clientSocket);


            if (shouldUpdateWordOfTheDay()) {
                updateWordOfTheDay();
            }
        }
    }

private:
    WSADATA wsaData;
    SOCKET serverSocket;

    std::vector<std::string> wordList = { "APPLE", "SMILE", "OCEAN", "AMBER", "GRASP" };

    std::string wordOfTheDay;
    std::chrono::steady_clock::time_point lastUpdateTime;

    std::string getRandomWord() {
        srand(static_cast<unsigned int>(time(nullptr)));
        return wordList[rand() % wordList.size()];
    }

    void sendResult(SOCKET clientSocket, const std::string& result) {
        send(clientSocket, result.c_str(), result.length(), 0);
    }

    void handleClient(SOCKET clientSocket) {
        GuessMessage guessMessage;
        guessMessage.word = wordOfTheDay;
        guessMessage.attemptsLeft = 5;

        std::string guessedLetters;

        send(clientSocket, reinterpret_cast<char*>(&guessMessage), sizeof(guessMessage), 0);

        while (guessMessage.attemptsLeft > 0) {
            const int BUFFER_SIZE = 1024;
            char buffer[BUFFER_SIZE];
            memset(buffer, 0, sizeof(buffer));

            int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
            if (bytesRead <= 0) {
                std::cerr << "Client disconnected." << std::endl;
                break;
            }

            std::string clientGuess(buffer);
            std::cout << "Word to guess: " << guessMessage.word << std::endl;
            std::cout << "Received guess from client: " << clientGuess << std::endl;


            if (clientGuess == guessMessage.word) {
                std::string result = "Client guessed the word!," + guessedLetters + "," + guessMessage.word;
                sendResult(clientSocket, result);
                break;
            }
            else {
                if (clientGuess.length() != guessMessage.word.length()) {
                    std::string result = "Error: Invalid word length.";
                    sendResult(clientSocket, result);
                    continue;
                }

                for (size_t i = 0; i < clientGuess.length(); ++i) {
                    if (guessedLetters.find(clientGuess[i]) != std::string::npos) {
                        std::string result = "Error: Letter '" + std::string(1, clientGuess[i]) + "' is already guessed.";
                        sendResult(clientSocket, result);
                        continue;
                    }
                }

                int correctPosition = 0;
                int correctLetter = 0;

                std::vector<int> guessedLetterCount(guessMessage.word.length(), 0);

                for (size_t i = 0; i < guessMessage.word.length(); ++i) {
                    if (guessMessage.word[i] == clientGuess[i]) {
                        ++correctPosition;
                        guessedLetters += clientGuess[i];
                    }
                    else if (guessMessage.word.find(clientGuess[i]) != std::string::npos &&
                        guessedLetterCount[i] < guessMessage.word.length()) {
                        ++correctLetter;
                        guessedLetters += clientGuess[i];
                        ++guessedLetterCount[i];
                    }
                }

                std::string result = "Result: " + std::to_string(correctPosition) +
                    " correct position(s), " + std::to_string(correctLetter) +
                    " correct letter(s) but wrong position.";
                std::cout << result << std::endl;

                result += "," + guessedLetters;

                --guessMessage.attemptsLeft;

                sendResult(clientSocket, result);

                if (correctPosition == guessMessage.word.length()) {
                    std::string result = "You guessed the word!," + guessedLetters + "," + guessMessage.word;
                    sendResult(clientSocket, result);
                    break;
                }
            }
        }

        closesocket(clientSocket);
    }
    bool shouldUpdateWordOfTheDay() {

        auto currentTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::hours>(currentTime - lastUpdateTime).count();

        return elapsedTime >= 24;
    }

    void updateWordOfTheDay() {
        wordOfTheDay = getRandomWord();
        lastUpdateTime = std::chrono::steady_clock::now();

        std::cout << "Word of the day updated: " << wordOfTheDay << std::endl;
    }
};

int main() {
    Server server;
    server.run();

    return EXIT_SUCCESS;
}
