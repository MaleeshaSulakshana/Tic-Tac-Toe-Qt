#ifndef PIECE_OF_GAME_H
#define PIECE_OF_GAME_H

#include <QString>

class piece_of_game
{

public:
    virtual const QString& getGameFigureSign() const = 0;

protected:
    const QString gameFigureSign;

    piece_of_game( const QString &gameFigureSign );
    virtual ~piece_of_game();

};

#endif // PIECE_OF_GAME_H
