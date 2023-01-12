#ifndef LOADER_H
#define LOADER_H

#include "Board/board.h"
#include <QFile>
#include <QTextStream>
#include <QJsonObject>

class Loader
{
private:
    void controlFiles();
public:
    Loader();
    Board* loadNewGame(EnumDifficulty difficulty);
    Board* loadSavedGame();
    void saveGame(const Board* currentBoard, Hero* hero);
};

#endif // LOADER_H
