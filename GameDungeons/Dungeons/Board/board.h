#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <QObject>

#include "boardroom.h"

const int boardSize = 8; // Initializing here for more transparency, could be initialized in the constructor

class Board : public QObject {
    Q_OBJECT
    Q_PROPERTY(BoardRoom* boardRoom READ getCurrentRoom NOTIFY changedBoardRoom)
    Q_PROPERTY(int numberOfShamans READ getNumberOfShamans CONSTANT)

    int m_size;
    int m_boardRow;
    int m_boardCurrentRoomIndex;
    int m_totalNumberOfShamans;
    BoardRoom* m_boardCurrentRoom;
    std::vector<BoardRoom*> m_board;
    EnumDifficulty m_boardDifficulty;

    void generateRooms();
    void generateHideouts();
    void generateEnemies();
    void generateItems();
    void printRooms();

public:
    Board(EnumDifficulty difficulty, int boardCurrentRoomIndex=0);
    void generateLoadedRooms(int numberOfKilledShamans);
    void addItem(int roomIndex, int cellX, int cellY, Item* i);
    void addEnemy(int roomIndex, int cellX, int cellY, Enemy* e);

    std::vector<BoardRoom*> getBoard() const;
    int getSize() const;
    BoardRoom* getRoom(int index) const;
    int getNumberOfShamans() const;
    void setNumberOfShamans(int numberTotalShamans);

    BoardRoom* getCurrentRoom() const;
    int getCurrentRoomIndex() const;

    Q_INVOKABLE void switchRoom(bool direction);
    Q_INVOKABLE void revealBoss();

signals:
    void changedBoardRoom();
};

Q_DECLARE_METATYPE(BoardRoom*);

#endif // BOARD_H
