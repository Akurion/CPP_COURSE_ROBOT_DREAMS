#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget* parent = nullptr);
    ~MyWidget();

private slots:
    void submitGuess();
    void readServerData();
    void connectToServer();
    void onConnected();

private:
    QLineEdit* inputLineEdit;
    QPushButton* submitButton;
    QLabel* resultLabel;
    QLabel* correctLettersLabel;

    QTcpSocket clientSocket;
    QString resultText; 
};

#endif // MYWIDGET_H