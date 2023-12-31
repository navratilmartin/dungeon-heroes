#ifndef LOADER_H
#define LOADER_H

#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "CharacterObjects/hero.h"
#include "Board/board.h"

class Loader {
private:
    void controlFiles();

public:
    Loader();
    Board* loadNewGame(EnumDifficulty difficulty);
    Board* loadSavedGame();
    Hero* loadSavedHero();
    void saveGame(const Board* currentBoard, Hero* hero);
    QStringList loadHelpFile();
};

#endif // LOADER_H
