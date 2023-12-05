#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cmath>




using std::srand;
using std::rand;
using std::cout;
using std::cin;
using std::endl;
using std::tolower;
using std::abs;

int main()
{
    srand(static_cast<unsigned int>(std::time(nullptr)));

    const int GeneratingRange = 50;
    int record = INT_MAX;

    cout << "WELCOME TO THE GUESS NUMBER GAME" << endl;
    cout << "ONLY BRAVE HUMANS CAN BEAT THIS GAME" << endl;

    char playagain;

    do
    {
        const int generatedNum = rand() % (GeneratingRange + 1);
        cout << generatedNum << endl;
        cout << "Generating random number (0-50)..." << endl;
        cout << "Enter -1 to give up!!!" << endl;

        int guess = 0;
        int attempt = 0;

        while (true)
        {
            cout << endl << "Make your guess: ";
            cin >> guess;

            if (guess == -1)
            {
                cout << "See you later noob" << endl;
                break;
            }
            else if (guess < 0 || guess > 50)
            {
                cout << "Hey bro, the game has limits, I know you humans are not so clever!" << endl;
            }
            else
            {
                int difference = abs(generatedNum - guess);

                if (difference > 20)
                    cout << "Hint: The number is more than 20 units away from your guess" << endl;
                else if (difference > 10)
                    cout << "Hint: The number is more than 10 units away from your guess" << endl;
                else if (difference < 10)
                    cout << "Hint: The number is less than 10 units away from your guess" << endl;
                else if (difference < 20)
                    cout << "Hint: The number is less than 20 units away from your guess" << endl;
                ++attempt;

                if (guess < generatedNum)
                    cout << "Lower! Try higher" << endl;
                else if (guess > generatedNum)
                    cout << "Too high! Try lower" << endl;
                else
                {
                    cout << "Yes! You did this!" << endl;
                    cout << "You spent " << attempt << " attempts to guess." << endl;

                    if (record > attempt)
                        record = attempt;

                    cout << "Your record is " << record << endl;
                    break;
                }
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playagain;
        playagain = tolower(playagain);

    } while (playagain == 'y');

    return 0;
}
