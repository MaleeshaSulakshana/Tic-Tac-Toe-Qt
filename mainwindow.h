#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPushButton>

#include "playgroundframe.h"
#include "piece_of_game.h"
#include "gamemenuwindow.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct Position
    {
        Position( const int &x = -1, const int &y = -1 )
        : x{ x }
        , y{ y }
        {
        }

        int x;
        int y;
    };

    explicit MainWindow(
            const QVector<piece_of_game*> &pieceOfGame,
            QWidget *parent = nullptr );

    ~MainWindow();

    void addButton( QPushButton *button, uint x, uint y );
    void moveTo( const uint &x, const uint &y );
    void computerMove();
    int nextBlockPosition( const uint &currentAthleteIndex ) const;

private:
    uint getFieldIndex( const uint &x, const uint &y ) const;
    Position getFieldCoordinate( const uint &index ) const;
    void checkWinner();

    Ui::MainWindow *ui;
    GameMenuWindow *gameMenuWindow;

    playGroundFrame *ground;

    uint nextPlayerIndex;
    QVector<piece_of_game*> pieceOfGame;
    QVector<QPushButton*> fieldButtons;

    uint placedCounter;
    bool hasWinner;
    bool gameFinished;
    bool computerFirst;
    bool versusComputer;
};
#endif // MAINWINDOW_H
