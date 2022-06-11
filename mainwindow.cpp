#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>    // sort

#include <QDebug>
#include <QMessageBox>
#include <QVector>
#include <QSound>

MainWindow::MainWindow(
        const QVector<piece_of_game*> &pieceOfGame,
        QWidget *parent )
    : QMainWindow(parent)
    , ground{ nullptr }
    , ui(new Ui::MainWindow)
    , nextPlayerIndex{ 0 }
    , placedCounter{ 0 }
    , hasWinner{ false }
    , gameFinished{ false }
    , computerFirst{ false }
    , versusComputer{ true }
{

    ui->setupUi(this);

    this->fieldButtons.resize( playGroundFrame::NUMBER_FIELDS );

    this->ground = new playGroundFrame( this );

    for( auto &piece : pieceOfGame )
    {
        this->pieceOfGame.push_back( piece );
    }

    this->setFixedSize( this->ground->size() );

    if( this->versusComputer &&
        this->computerFirst )
    {
        this->computerMove();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

uint MainWindow::getFieldIndex( const uint &x, const uint &y ) const
{
    const uint numberOfFieldsPerRow = 3;
    return ((x-1) * numberOfFieldsPerRow + y) - 1;
}

MainWindow::Position MainWindow::getFieldCoordinate( const uint &index ) const
{
    const uint numberOfFieldsPerRow = 3;

    Position pos;
    pos.x = static_cast<uint>(index / 3) + 1;
    pos.y = index % 3 + 1;

    return pos;
}


void MainWindow::addButton( QPushButton *button, uint x, uint y )
{
    const uint index = this->getFieldIndex( x, y );

    this->fieldButtons[index] = button;
}

void MainWindow::moveTo( const uint  &x, const uint  &y )
{
    if( !this->hasWinner && !this->gameFinished )
    {
        const int actualPlayerIndex = this->nextPlayerIndex;
        const uint index = this->getFieldIndex( x, y );

        const QString drawer = this->pieceOfGame.at( this->nextPlayerIndex)->getGameFigureSign();

        if( this->fieldButtons.at(index)->text().isEmpty() )
        {
            this->fieldButtons.at(index)->setText( drawer );

            this->nextPlayerIndex = (nextPlayerIndex+1) % this->pieceOfGame.size();
            ++this->placedCounter;

            this->checkWinner();

            if( this->placedCounter > 8 || this->hasWinner )
            {
                this->gameFinished = true;

                QString gameText = "";
                QString player = "";

                if( this->hasWinner )
                {
                    if (this->pieceOfGame.at( actualPlayerIndex )->getGameFigureSign() == "X"){
                        player = "You";
                        QSound::play(":sounds/sounds/sfx-victory5.wav");
                    }
                    else {
                        player = "Computer";
                        QSound::play(":sounds/sounds/fail-buzzer-04.wav");
                    }

                    gameText = player + " win the game.";
                }
                else {
                    gameText = "The game is over. No Winner";
                    QSound::play(":sounds/sounds/fail-buzzer-04.wav");
                }

//                Open game menu window
                gameMenuWindow = new GameMenuWindow(this, gameText);
                if (!gameMenuWindow->isVisible()) {
                    this->hide();
                    gameMenuWindow->show();
                }

//                Play again
                this->nextPlayerIndex = 0;
                this->placedCounter = 0;
                this->hasWinner = false;
                this->gameFinished = false;
                this->computerFirst = false;
                this->versusComputer = true;
                this->ground = new playGroundFrame( this );

            }


            if( this->versusComputer )
            {
                if( !this->hasWinner &&
                    !this->gameFinished )
                {
                    int rest = 0;
                    if(this->computerFirst)
                    {
                        rest = 1;
                    }

                    if( this->placedCounter % 2 != rest )
                    {
                        this->computerMove();
                    }
                }
            }
        }
    }
}

void MainWindow::checkWinner()
{

    const QString val_1_1 = this->fieldButtons.at( this->getFieldIndex( 1,1 ))->text();
    const QString val_1_2 = this->fieldButtons.at( this->getFieldIndex( 1,2 ))->text();
    const QString val_1_3 = this->fieldButtons.at( this->getFieldIndex( 1,3 ))->text();
    const QString val_2_1 = this->fieldButtons.at( this->getFieldIndex( 2,1 ))->text();
    const QString val_2_2 = this->fieldButtons.at( this->getFieldIndex( 2,2 ))->text();
    const QString val_2_3 = this->fieldButtons.at( this->getFieldIndex( 2,3 ))->text();
    const QString val_3_1 = this->fieldButtons.at( this->getFieldIndex( 3,1 ))->text();
    const QString val_3_2 = this->fieldButtons.at( this->getFieldIndex( 3,2 ))->text();
    const QString val_3_3 = this->fieldButtons.at( this->getFieldIndex( 3,3 ))->text();

    const QString styleSheet = "padding: 0px;\nmargin: 0px;\nborder: 0px solid black;\ncolor: #F6F6F6;"
                               "\nbackground-color: #610094;\nfont-size: 40pt;\nborder-radius: 20px";

    if( !val_1_1.isEmpty() &&
        !val_1_2.isEmpty() &&
        !val_1_3.isEmpty() &&
        val_1_1 == val_1_2 && val_1_2 == val_1_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 1,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_2_1.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_2_3.isEmpty() &&
             val_2_1 == val_2_2 && val_2_2 == val_2_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 2,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_3_1.isEmpty() &&
             !val_3_2.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_3_1 == val_3_2 && val_3_2 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_1.isEmpty() &&
             !val_2_1.isEmpty() &&
             !val_3_1.isEmpty() &&
             val_1_1 == val_2_1 && val_2_1 == val_3_1 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,1 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_2.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_2.isEmpty() &&
             val_1_2 == val_2_2 && val_2_2 == val_3_2 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,2 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,2 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_3.isEmpty() &&
             !val_2_3.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_1_3 == val_2_3 && val_2_3 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,3 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_1.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_3.isEmpty() &&
             val_1_1 == val_2_2 && val_2_2 == val_3_3 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,1 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,3 ))
                        ->setStyleSheet( styleSheet );
    }
    else if( !val_1_3.isEmpty() &&
             !val_2_2.isEmpty() &&
             !val_3_1.isEmpty() &&
             val_1_3 == val_2_2 && val_2_2 == val_3_1 )
    {
        this->hasWinner = true;

        this->fieldButtons.at( this->getFieldIndex( 1,3 ))
                ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 2,2 ))
                        ->setStyleSheet( styleSheet );
        this->fieldButtons.at( this->getFieldIndex( 3,1 ))
                        ->setStyleSheet( styleSheet );
    }

}

void MainWindow::computerMove()
{
    int nextBlockPos = nextBlockPosition(
                (this->computerFirst) ? 0 : 1 );

    Position toPos;
    bool moved = false;

    if( nextBlockPos >= 0  )
    {
         toPos = this->getFieldCoordinate( nextBlockPos );

         moved = true;
    }

    if( !moved )
    {

        int itemCount = 0;
        QString item11 = "no";
        QString item12 = "no";
        QString item13 = "no";
        QString item21 = "no";
        QString item22 = "no";
        QString item23 = "no";
        QString item31 = "no";
        QString item32 = "no";
        QString item33 = "no";

        QString *buttonArray = new QString[9];

        if( this->fieldButtons.at( this->getFieldIndex( 1,1 ))->text().isEmpty() )
        {
            buttonArray[0] = "yes";
         } else {
            buttonArray[0] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 1,2 ))->text().isEmpty() )
         {
            buttonArray[1] = "yes";
         } else {
            buttonArray[2] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 1,3 ))->text().isEmpty() )
         {
            buttonArray[2] = "yes";
         } else {
            buttonArray[2] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 2,1 ))->text().isEmpty() )
         {
            buttonArray[3] = "yes";
         } else {
            buttonArray[3] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 2,2 ))->text().isEmpty() )
         {
            buttonArray[4] = "yes";
         } else {
            buttonArray[4] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 2,3 ))->text().isEmpty() )
         {
            buttonArray[5] = "yes";
         } else {
            buttonArray[5] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 3,1 ))->text().isEmpty() )
         {
            buttonArray[6] = "yes";
         } else {
            buttonArray[6] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 3,2 ))->text().isEmpty() )
         {
            buttonArray[7] = "yes";
         } else {
            buttonArray[7] = "no";
        }

        if( this->fieldButtons.at( this->getFieldIndex( 3,3 ))->text().isEmpty() )
         {
            buttonArray[8] = "yes";
         } else {
            buttonArray[8] = "no";
        }


        for (int i=0; i<9; i++) {

            if (buttonArray[i] == "yes")
            {
                itemCount += 1;
            }

        }

        int * itemArray = new int[itemCount];
        int loopIndex = 0;

        for (int i=0; i<9; i++) {

            if (buttonArray[i] == "yes")
            {
                itemArray[loopIndex] = i+1;
                loopIndex += 1;
            }

        }

        int index = rand() % itemCount; // pick a random index
        int value = itemArray[index];

        if (value == 1) {
            toPos = Position{1,1};
        } else if (value == 2) {
            toPos = Position{1,2};
        } else if (value == 3) {
            toPos = Position{1,3};
        } else if (value == 4) {
            toPos = Position{2,1};
        } else if (value == 5) {
            toPos = Position{2,2};
        } else if (value == 6) {
            toPos = Position{2,3};
        } else if (value == 7) {
            toPos = Position{3,1};
        } else if (value == 8) {
            toPos = Position{3,2};
        } else if (value == 9) {
            toPos = Position{3,3};
        }

    }

    this->moveTo( toPos.x, toPos.y );
}

int MainWindow::nextBlockPosition( const uint &currentAthleteIndex ) const
{
    // horizontal
    const QVector<QVector<uint>> winPossibilities {
        QVector<uint> { 0,1,2 },
        QVector<uint> { 3,4,5 },
        QVector<uint> { 6,7,8 },

        // vertical
        QVector<uint> { 3,4,5 },
        QVector<uint> { 1,4,7 },
        QVector<uint> { 2,5,8 },

        // cross
        QVector<uint> { 0,4,8 },
        QVector<uint> { 2,4,6 }
    };

    QVector<QVector<uint>> nearlyWinPossibilities
    {
        QVector<uint> { },
        QVector<uint> { },
        QVector<uint> { },

        // vertical
        QVector<uint> { },
        QVector<uint> { },
        QVector<uint> { },

        // cross
        QVector<uint> { },
        QVector<uint> { }
    };

    uint rivalIndex =
            (currentAthleteIndex  + 1) % this->pieceOfGame.size();

    QString opponent = this->pieceOfGame.at(rivalIndex)->getGameFigureSign();

    QVector<uint> opponentPosition;

    for( auto &reihe :winPossibilities )
    {
        for( auto &spalte : reihe )
        {
            if( this->fieldButtons.at(spalte)->text() == opponent )
            {
               opponentPosition.push_back( spalte );
            }
        }
    }

    std::sort( opponentPosition.begin(),
               opponentPosition.end());

    // Remove duplicates
    opponentPosition.erase(
       std::unique(opponentPosition.begin(),
                   opponentPosition.end() ),
       opponentPosition.end() );

    for( int i=0; i<winPossibilities.size(); i++ )
    {
        for( int j=0; j<winPossibilities.at(i).size(); j++ )
        {
            uint index = winPossibilities[i][j];

            if( !opponentPosition.contains(index) )
            {
                nearlyWinPossibilities[i].push_back( index );
            }
        }
    }

    int retValue = -1;

    for( auto &list : nearlyWinPossibilities )
    {
        if( list.size() == 1 )
        {
            if( this->fieldButtons.at(list.at(0))->text().isEmpty() )
            {
                retValue = list.at(0);
            }

            break;
        }
    }

    return retValue;
}
