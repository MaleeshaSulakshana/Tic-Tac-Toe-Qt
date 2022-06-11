#ifndef X_PIECE_OF_GAME_H
#define X_PIECE_OF_GAME_H

#include "piece_of_game.h"

class x_piece_of_game : public piece_of_game
{
public:
    x_piece_of_game( const QString &gameFigureSign );
    virtual ~x_piece_of_game() override;

    const QString& getGameFigureSign() const override;
};

#endif // X_PIECE_OF_GAME_H
