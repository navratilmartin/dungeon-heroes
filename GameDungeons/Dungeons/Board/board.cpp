#include "board.h"

Board::Board(EnumDifficulty difficulty, int boardCurrentRoomIndex) {
    m_size = boardSize;
    m_boardRow = 0;
    m_boardCurrentRoomIndex = boardCurrentRoomIndex;
    m_totalNumberOfShamans = 0;
    m_board = std::vector<BoardRoom*> (std::vector<BoardRoom*> (boardSize));
    m_boardDifficulty = difficulty;
    generateRooms();
    m_boardCurrentRoom = m_board.at(m_boardCurrentRoomIndex);

    std::for_each(m_board.begin(), m_board.end(), [this](const BoardRoom* br) {
        this->m_totalNumberOfShamans += br->getNumberOfShamansInRoom();
    });

    // std::cout << "NUMBER OF SHAMANS: " << m_totalNumberOfShamans << "\n";
}

void Board::generateRooms() {
    generate(m_board.begin(), m_board.end(), [this]() -> BoardRoom * {
        BoardRoom *r = new BoardRoom(this->m_boardDifficulty);
        return r;
    });

    generateHideouts();
    generateEnemies();
    generateItems();

    m_boardCurrentRoom = m_board.at(m_boardRow);
    m_board.at(boardSize-1)->setBoss(); // last room always has a boss
}

void Board::generateLoadedRooms(int numberOfKilledShamans){
    generate(m_board.begin(), m_board.end(), [this]() -> BoardRoom * {
        BoardRoom *r = new BoardRoom(this->m_boardDifficulty);
        return r;
    });

    m_totalNumberOfShamans += numberOfKilledShamans;
    m_boardCurrentRoom = m_board.at(m_boardRow);
    m_board.at(boardSize-1)->setBoss(); // last room always has a boss
}

void Board::addItem(int roomIndex, int cellX, int cellY, Item* i){
    m_board.at(roomIndex)->addItemCell(cellX, cellY, i);
}

void Board::addEnemy(int roomIndex, int cellX, int cellY, Enemy* e){
    m_board.at(roomIndex)->addEnemyCell(cellX, cellY, e);
}

void Board::generateHideouts() {
    srand(time(0));
    int numOfHideouts=0;

    if (m_boardDifficulty == EnumDifficulty::Easy) {
        numOfHideouts = boardSize/2;
    }else if (m_boardDifficulty == EnumDifficulty::Medium) {
        numOfHideouts = boardSize/3;
    } else if (m_boardDifficulty == EnumDifficulty::Hard) {
        numOfHideouts = boardSize/4;
    }

    for (int count=0; count<numOfHideouts; count++) {
        int randx = rand()%(boardSize*boardSize);
        int x = randx / boardSize;
        m_board.at(x) ->addHideout();
    }
}

void Board::generateEnemies() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, boardSize-1);
    int numOfEnemies=0;

    if (m_boardDifficulty == EnumDifficulty::Easy) {
        numOfEnemies = boardSize * 1.8;
    } else if (m_boardDifficulty == EnumDifficulty::Medium) {
        numOfEnemies = boardSize * 2.4;
    } else if (m_boardDifficulty == EnumDifficulty::Hard) {
        numOfEnemies = boardSize * 3.0;
    }

    for(int count=0; count<numOfEnemies; count++){
        int x = dis(gen);

        if (count < numOfEnemies*0.5) {
            m_board.at(x)->addEnemy(1);  // creates a robber
        } else if (count < numOfEnemies*0.8) {
            m_board.at(x)->addEnemy(2);  // creates a slime
        } else {
            m_board.at(x)->addEnemy(3);  // creates a shaman
        }
    }
}

void Board::generateItems() {
    std::random_device rd;
    std::mt19937 gen(rd());
    int numOfItems=0, typeOfItem=0;
    std::uniform_int_distribution<> dis(0, boardSize-1);
    std::uniform_int_distribution<> ite(1, 3);

    if (m_boardDifficulty == EnumDifficulty::Easy) {
        numOfItems = boardSize * 1.5;
    } else if (m_boardDifficulty  == EnumDifficulty::Medium) {
        numOfItems = boardSize * 1.3;
    } else if (m_boardDifficulty  == EnumDifficulty::Hard) {
        numOfItems = boardSize * 1;
    }

    for (int count=0; count<numOfItems; count++) {
        int x = dis(gen);
        typeOfItem = ite(gen);
        m_board.at(x) ->addItem(typeOfItem);
    }
}

std::vector<BoardRoom*> Board::getBoard() const {
    return m_board;
}

BoardRoom* Board::getCurrentRoom() const {
        return m_boardCurrentRoom;
}

void Board::switchRoom(bool direction) {
    // if true - the player goes to the next room, otherwise - to the previous
    if (direction and m_boardRow+1 < m_size) {
            m_boardRow++;
            m_boardCurrentRoom = m_board.at(m_boardRow);
            emit changedBoardRoom();
            m_boardCurrentRoomIndex++;
    } else if (!direction and m_boardRow-1 >= 0) {
            m_boardRow--;
            m_boardCurrentRoom = m_board.at(m_boardRow);
            m_boardCurrentRoomIndex--;
            emit changedBoardRoom();
            // std::cout << "Room n" << m_boardCurrentRoomIndex << std::endl;
    }
}

void Board::revealBoss() {
    EnemyFactoryShaman boss;
    BoardCell* bossCell = m_board.at(boardSize-1)->getBoardCells().at(7).at(7);

    bossCell->addCharacter(boss.getEnemy(7, 7));
    bossCell->setBossCell(m_boardDifficulty);
}

int Board:: getCurrentRoomIndex() const {
    return m_boardCurrentRoomIndex;
}

int Board::getSize() const {
    return m_size;
}

BoardRoom* Board::getRoom(int index) const {
    return m_board.at(index);
}

int Board::getNumberOfShamans() const {
    return m_totalNumberOfShamans;
}

void Board::printRooms(){
    for(int i=0; i<boardSize; i++){
        std::cout << "room" << i << std::endl;
        m_board.at(i)->printCells();
    }
}
