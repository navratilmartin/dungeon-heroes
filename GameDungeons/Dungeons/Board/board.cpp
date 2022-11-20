#include "board.h"

Board::Board(EnumDifficulty difficulty){
    m_size = boardSize;
    m_board = std::vector<std::vector<BoardRoom*>> (boardSize, std::vector<BoardRoom*> (boardSize));
    // Initializing of the vector
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
    for(int height=0; height<boardSize; height++) {
        std::cout << "y" << std::endl;
        generate(m_board.at(height).begin(), m_board.at(height).end(), [difficulty]() -> BoardRoom * {
            BoardRoom *r = new BoardRoom(difficulty);
            std::cout << "x" << std::endl;
            return r;
        });
    }
    generateHideouts(difficulty);
    generateEnemies(difficulty);
}

void Board::generateHideouts(EnumDifficulty difficulty) {
    srand(time(0));
    int numOfHideouts=0;
    if(difficulty == EnumDifficulty::Easy){
        numOfHideouts = boardSize;
    }else if(difficulty == EnumDifficulty::Medium){
        numOfHideouts = boardSize/3;
    }else if(difficulty == EnumDifficulty::Hard){
        numOfHideouts = boardSize/2;
    }
    for(int count=0; count<numOfHideouts; count++){
        int randx = rand()%(boardSize*boardSize);
        int x = randx / boardSize;
        int y = randx % boardSize;
        m_board.at(x).at(y) ->addHideout();
    }
}

void Board::generateEnemies(EnumDifficulty difficulty) {
    srand(time(0));
    int numOfEnemies=0;
    if(difficulty == EnumDifficulty::Easy){
        numOfEnemies = pow(boardSize, 2) * 0.4;
    }else if(difficulty == EnumDifficulty::Medium){
        numOfEnemies = pow(boardSize, 2) * 0.5;
    }else if(difficulty == EnumDifficulty::Hard){
        numOfEnemies = pow(boardSize, 2) * 0.7;
    }
    for(int count=0; count<numOfEnemies; count++){
        int randx = rand()%(boardSize*boardSize);
        int x = randx / boardSize;
        int y = randx % boardSize;
        if(count < numOfEnemies*0.5){
            m_board.at(x).at(y) ->addEnemy(1);  // creates a robber
        }
        else if(count < numOfEnemies*0.8){
            m_board.at(x).at(y) ->addEnemy(2);  // creates a slime
        }
        else{
            m_board.at(x).at(y) ->addEnemy(3);  // creates a shaman
        }
    }
}

std::vector<std::vector<BoardRoom*>> Board::getBoard() const {
    return m_board;
}
