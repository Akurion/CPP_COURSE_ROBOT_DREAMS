#include "MyWidget.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent), resultText("")
{
    inputLineEdit = new QLineEdit(this);
    submitButton = new QPushButton("Submit", this);
    resultLabel = new QLabel("Result:", this);
    correctLettersLabel = new QLabel("Correct letters:", this);

    connect(submitButton, &QPushButton::clicked, this, &MyWidget::submitGuess);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(inputLineEdit);
    layout->addWidget(submitButton);
    layout->addWidget(resultLabel);
    layout->addWidget(correctLettersLabel);

    setLayout(layout);
    resize(800, 600);

    connectToServer();

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyWidget::readServerData);
    timer->start(100);
}

MyWidget::~MyWidget()
{

}

void MyWidget::submitGuess()
{
    if (inputLineEdit->text().isEmpty())
        return;

    QString guess = inputLineEdit->text().toUpper();

    clientSocket.write(guess.toUtf8());
    clientSocket.flush();

    inputLineEdit->clear();
}

void MyWidget::readServerData()
{
    QByteArray data = clientSocket.readAll();
    resultText = QString(data);

    qDebug() << "Received result from server: " << resultText;

    QStringList parts = resultText.split(',');
    if (parts.size() >= 3) {
        QString resultLabelText = "" + parts[0];
        QString correctLetters = parts[1];
        QString guessedLetters = parts[2];


        resultLabel->setText(resultLabelText);

        if (!correctLetters.isEmpty()) {
            correctLettersLabel->setText("Correct letters: " + correctLetters);
        }
        else {
            correctLettersLabel->clear();
        }

        
        if (!guessedLetters.isEmpty()) {
            
            static QString previousGuessedLetters;
            if (guessedLetters != previousGuessedLetters) {
                QMessageBox::information(this, "Guessed Letters", "Guessed Letters: " + guessedLetters);
                previousGuessedLetters = guessedLetters;
            }
        }
       
    }
}




void MyWidget::connectToServer()
{
    connect(&clientSocket, &QTcpSocket::connected, this, &MyWidget::onConnected);

    clientSocket.connectToHost("127.0.0.1", 12345);

    if (!clientSocket.waitForConnected(5000)) {
        qDebug() << "Error connecting to server: " << clientSocket.errorString();
    }
    // Remove the else block.
}

void MyWidget::onConnected()
{
    qDebug() << "Connected to server.";
}