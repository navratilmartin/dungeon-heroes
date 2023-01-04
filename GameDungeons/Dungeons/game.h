#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "loader.h"
#include "CharacterObjects/hero.h"

class Game : public QObject {
    Q_OBJECT
    Q_PROPERTY(Board* board READ getBoardMatrix CONSTANT)
    Q_PROPERTY(Hero* hero READ getHero CONSTANT)
    Q_PROPERTY(QString enemyName READ enemyName CONSTANT)

    Loader* m_loader;
    Board* m_board;
    Hero* m_hero;
    bool isOnEnemy();
    void createBoard(EnumDifficulty difficulty);

    void loadBoard();

public:
    Game();

    Game& operator=(const Game&) = delete;

    Board* getBoardMatrix() const;

    Hero* getHero() const;

    QString enemyName();

    Q_INVOKABLE void play(int userInput = 3);
    Q_INVOKABLE bool onEnemy();
    ~Game();

};

Q_DECLARE_METATYPE(Board*); // None Qt Data types must be registered
Q_DECLARE_METATYPE(Hero*);

#endif // GAME_H
