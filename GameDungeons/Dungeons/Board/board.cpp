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
    for(int height=0; height<roomSize; height++){
        for(int width=0; width<roomSize; width++){
            BoardRoom* r=  new BoardRoom(difficulty);   // The cell is being generated now, once it is
            m_board.at(height).at(width) = r;           // generated, it is put into the board
            std::cout << height << width <<r->n;
        }
        std::cout << std::endl;
    }
}
*/
void Board::generateRooms(EnumDifficulty difficulty) {
    for(int height=0; height<roomSize; height++) {
        generate(m_board.at(height).begin(), m_board.at(height).end(), [difficulty]() -> BoardRoom * {
            BoardRoom *r = new BoardRoom(difficulty);
            return r;
        });
    }
}

std::vector<std::vector<BoardRoom*>> Board::getBoard() const {
    return m_board;
}
