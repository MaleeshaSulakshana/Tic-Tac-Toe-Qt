#include "x_piece_of_game.h"

x_piece_of_game::x_piece_of_game( const QString &gameFigureSign )
: piece_of_game{ gameFigureSign }
{

}

x_piece_of_game::~x_piece_of_game()
{

}

const QString& x_piece_of_game::getGameFigureSign() const
{
    return this->gameFigureSign;
}
