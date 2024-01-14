#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_game.h"

class game : public QMainWindow
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr);
    ~game();

private:
    Ui::gameClass ui;
};
