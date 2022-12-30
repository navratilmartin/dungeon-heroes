#include "board.h"

Board::Board(EnumDifficulty difficulty){
    m_size = boardSize;
    m_boardRow = 0;
    m_board = std::vector<BoardRoom*> (std::vector<BoardRoom*> (boardSize));
    generateRooms(difficulty);
}
// Both generateRooms algorithms work. The one with generator is weird, maybe we should not use for cycle at all? Idk

/*
void Board::generateRooms(EnumDifficulty difficulty) {
    for(int height=0; height<boardSize; height++){
        for(int width=0; width<boardSize; width++){
            BoardRoom* r=  new BoardRoom(difficulty);   // The cell is being generated now, once it is
            m_board.at(height).at(width) = r;           // generated, it is put into the board
            std::cout << height << width <<r->r;
        }
        std::cout << std::endl;
    }
}
 */

void Board::generateRooms(EnumDifficulty difficulty) {
        generate(m_board.begin(), m_board.end(), [difficulty]() -> BoardRoom * {
            BoardRoom *r = new BoardRoom(difficulty);
            return r;
        });
    generateHideouts(difficulty);
    generateEnemies(difficulty);
    generateItems(difficulty);
    //printRooms();

    // TODO udelat tak, aby se prazdnost Room nastavovala na zaklade zvolene slozitosti

    // Prvni Room by vzdy nemela byt prazdna, proc? Pro jednoduchost, at nemusim vyhledavat pomoci std::find_if
    m_boardRoom = m_board.begin();

    // Posledni Room vzdy bude mit bossa
    m_board.at(boardSize-1)->setBoss();

}

void Board::generateHideouts(EnumDifficulty difficulty) {
    srand(time(0));
    int numOfHideouts=0;
    if(difficulty == EnumDifficulty::Easy){
        numOfHideouts = boardSize/2;
    }else if(difficulty == EnumDifficulty::Medium){
        numOfHideouts = boardSize/3;
    }else if(difficulty == EnumDifficulty::Hard){
        numOfHideouts = boardSize/4;
    }
    for(int count=0; count<numOfHideouts; count++){
        int randx = rand()%(boardSize*boardSize);
        int x = randx / boardSize;
        m_board.at(x) ->addHideout();
    }
}

void Board::generateEnemies(EnumDifficulty difficulty) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, boardSize-1);
    int numOfEnemies=0;
    if(difficulty == EnumDifficulty::Easy){
        numOfEnemies = boardSize * 1.8;
    }else if(difficulty == EnumDifficulty::Medium){
        numOfEnemies = boardSize * 2.4;
    }else if(difficulty == EnumDifficulty::Hard){
        numOfEnemies = boardSize * 3.0;
    }
    for(int count=0; count<numOfEnemies; count++){
        int x = dis(gen);
        if(count < numOfEnemies*0.5){
            m_board.at(x) ->addEnemy(1);  // creates a robber
        }
        else if(count < numOfEnemies*0.8){
            m_board.at(x)->addEnemy(2);  // creates a slime
        }
        else{
            m_board.at(x) ->addEnemy(3);  // creates a shaman
        }
    }
}

void Board::generateItems(EnumDifficulty difficulty){
    std::random_device rd;
    std::mt19937 gen(rd());
    int numOfItems=0, typeOfItem=0;
    std::uniform_int_distribution<> dis(0, boardSize-1);
    std::uniform_int_distribution<> ite(1, 3);
    if(difficulty == EnumDifficulty::Easy){
        numOfItems = boardSize * 1.5;
    }else if(difficulty == EnumDifficulty::Medium){
        numOfItems = boardSize * 1.3;
    }else if(difficulty == EnumDifficulty::Hard){
        numOfItems = boardSize * 1;
    }
    for(int count=0; count<numOfItems; count++){
        int x = dis(gen);
        typeOfItem = ite(gen);
        m_board.at(x) ->addItem(typeOfItem);
    }
}

void Board::findRoom(bool direction) {
    if (direction) {

        while ((*m_boardRoom)->isEmptyRoom() == true) {
        m_boardRoom = std::find_if(m_boardRoom, m_board.end(),
                                    [](BoardRoom* boardRoom) {
                return boardRoom->isEmptyRoom() == false;
        });

        if (m_boardRoom == m_board.end()) {
            m_boardRow++;
            m_boardRoom = m_board.begin();
        }
    }

    } else {
        auto reversedRoom = m_board.rend();

        while (reversedRoom == m_board.rend() or (*reversedRoom)->isEmptyRoom() == true) {
        reversedRoom = std::find_if(m_board.rbegin()+1, m_board.rend(),
                                    [this](BoardRoom* boardRoom) {
                return boardRoom != *m_boardRoom and boardRoom->isEmptyRoom() == false;
        });

        if (reversedRoom == m_board.rend()) {
            m_boardRow--;
            reversedRoom = m_board.rend();
        } else {
            m_boardRoom = (reversedRoom+1).base();
        }
    }

    }

    // std::cout << "Coordinates of the room: " << m_boardRow << ", " << std::distance(m_board.at(m_boardRow).begin(), m_boardRoom) << std::endl;
    // std::cout << std::boolalpha;
    // std::cout << "Emptiness: " << (*m_boardRoom)->isEmptyRoom() << std::endl;
}


std::vector<BoardRoom*> Board::getBoard() const {
    return m_board;
}

BoardRoom* Board::getRoom() const {
        return *m_boardRoom;
}

void Board::switchRoom(bool direction) {
    if (direction and m_boardRoom-m_board.begin() < 7) {
            m_boardRoom++;
    } else if (direction) {
            m_boardRow++;
            m_boardRoom = m_board.begin();
    }
    findRoom(direction);

    emit changedBoardRoom();
}

void Board::printRooms(){
    for(int i=0; i<boardSize; i++){
        std::cout << "room" << i << std::endl;
        m_board.at(i)->printCells();
    }
}
