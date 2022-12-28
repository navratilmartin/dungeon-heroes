#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "loader.h"
#include "CharacterObjects/hero.h"
class Game : public QObject {
    Q_OBJECT
    Q_PROPERTY(Board* board READ getBoardMatrix CONSTANT)
    Q_PROPERTY(Hero* hero READ getHero CONSTANT)
    Loader* m_loader;
    Board* m_board;

    void createBoard(EnumDifficulty difficulty);

    void loadBoard();

public:
    Game();
    Hero* m_hero = new Hero(0,0,"",8);
    Game& operator=(const Game&) = delete;

    Board* getBoardMatrix() const;

    Q_INVOKABLE void play(int userInput = 3);

    ~Game();

    Hero* getHero();

};

Q_DECLARE_METATYPE(Board*); // None Qt Data types must be registered

#endif // GAME_H
