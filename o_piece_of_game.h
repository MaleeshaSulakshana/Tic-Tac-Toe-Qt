#ifndef O_PIECE_OF_GAME_H
#define O_PIECE_OF_GAME_H

#include "piece_of_game.h"

class o_piece_of_game : public piece_of_game
{
public:
    o_piece_of_game(const QString &gameFigureSign );
    virtual ~o_piece_of_game() override;

    const QString& getGameFigureSign() const override;

//    o_piece_of_game();
};

#endif // O_PIECE_OF_GAME_H
