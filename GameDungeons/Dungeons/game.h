#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "loader.h"

class Game : public QObject {
    Q_OBJECT
    Q_PROPERTY(std::vector<std::vector<BoardRoom*>> board READ getBoardMatrix NOTIFY boardChanged)

    Loader* m_loader;
    Board* m_board;

    void createBoard(EnumDifficulty difficulty);

    void loadBoard();

public:
    Game();

    Game& operator=(const Game&) = delete;

    std::vector<std::vector<BoardRoom*>> getBoardMatrix() const;

    Q_INVOKABLE void play(int userInput = 3);

    ~Game();

signals:
    void boardChanged();
};

Q_DECLARE_METATYPE(std::vector<std::vector<BoardRoom*> >); // None Qt Data types must be registered

#endif // GAME_H
