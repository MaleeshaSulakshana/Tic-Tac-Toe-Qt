#include "o_piece_of_game.h"

o_piece_of_game::o_piece_of_game( const QString &gameFigureSign )
: piece_of_game{ gameFigureSign }
{

}

o_piece_of_game::~o_piece_of_game()
{

}

const QString& o_piece_of_game::getGameFigureSign() const
{
    return this->gameFigureSign;
}
