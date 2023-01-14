#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "loader.h"
#include "CharacterObjects/hero.h"

class Game : public QObject {
    Q_OBJECT
    Q_PROPERTY(Board* board READ getBoardMatrix CONSTANT)
    Q_PROPERTY(Hero* hero READ getHero CONSTANT)
    Q_PROPERTY(QStringList helpMessages READ getHelpMessages CONSTANT)

    Loader* m_loader;
    Board* m_board;
    Hero* m_hero;
    QStringList m_helpMessages;

    bool isOnEnemy();
    void createBoard(EnumDifficulty difficulty);
    void loadBoard();

public:
    Game();

    Game& operator=(const Game&) = delete;

    ~Game();

    Board* getBoardMatrix() const;

    Hero* getHero() const;

    QStringList getHelpMessages() const;

    Q_INVOKABLE void play(int userInput = 3);
    Q_INVOKABLE void saveGame();
};

Q_DECLARE_METATYPE(Board*); // None Qt Data types must be registered
Q_DECLARE_METATYPE(Hero*);

#endif // GAME_H
