#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "loader.h"

class Game : public QObject {
    Q_OBJECT
    Q_PROPERTY(Board* board READ getBoardMatrix CONSTANT)

    Loader* m_loader;
    Board* m_board;

    void createBoard(EnumDifficulty difficulty);

    void loadBoard();

public:
    Game();

    Game& operator=(const Game&) = delete;

    Board* getBoardMatrix() const;

    Q_INVOKABLE void play(int userInput = 3);

    ~Game();

};

Q_DECLARE_METATYPE(Board*); // None Qt Data types must be registered

#endif // GAME_H
