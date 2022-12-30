#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <QObject>

#include "boardroom.h"

const int boardSize = 8; // Initializing here for more transparency, could be initialized in the constructor

class Board : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(BoardRoom* boardRoom READ getRoom NOTIFY changedBoardRoom)
    int m_size;
    int m_boardRow;
    std::vector<BoardRoom*>::iterator m_boardRoom;
    std::vector<BoardRoom*> m_board;

    void generateRooms(EnumDifficulty difficulty);
    void generateHideouts(EnumDifficulty difficulty);
    void generateEnemies(EnumDifficulty difficulty);
    void generateItems(EnumDifficulty difficulty);
    void findRoom(bool direction = true); // if true - the player goes to the next room, otherwise - to the previous
    void printRooms();

public:
    Board(EnumDifficulty difficulty);

    std::vector<BoardRoom*> getBoard() const;

    BoardRoom* getRoom() const;

    Q_INVOKABLE void switchRoom(bool direction);

signals:
    void changedBoardRoom();

};

Q_DECLARE_METATYPE(BoardRoom*);

#endif // BOARD_H
