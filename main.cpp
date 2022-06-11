#include "mainwindow.h"

#include <QApplication>

#include "piece_of_game.h"
#include "o_piece_of_game.h"
#include "x_piece_of_game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<piece_of_game*> playGround {
        new x_piece_of_game{ "X" },
        new o_piece_of_game{ "O" },

    };

    MainWindow w(playGround);
    w.show();
    return a.exec();
}
