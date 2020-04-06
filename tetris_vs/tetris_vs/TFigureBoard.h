//
// Created by chaed on 18. 11. 24.
//

#ifndef TERIS_FIGURE_CLASS_FIGUREBOARD_H
#define TERIS_FIGURE_CLASS_FIGUREBOARD_H

#include <array>
#include <memory>
#include <cassert>
#include <exception>
#include <mutex>

#include "TFigure.h"
#include "TProperty.h"

namespace tetris {

class TFigureBoard {

public:

    using BoardType = std::array< std::array<TFigureUnit,BOARD_WIDTH_COUNT>,BOARD_HEIGHT_COUNT >;
    
    BoardType getBoard() 
    {return m_board;}

    void rotate();
    void goDown();
    void goLeft();
    void goRight();
    void goStraightDown();
    void eraseLine( t_size lineNumber);
    void addLine( t_size lineNumber);
    void eraseBottomLine( t_size = 1);
    void addBottomLine( t_size = 1);
    void createNextFigureRandomly();
    TFigure* getCurrentFigure();
    
    static TFigureBoard* get();

private:

    TFigureBoard();
    ~TFigureBoard() { delete TFigureBoard::get(); }
    void eraseCoords();
    void setCoords();
    bool eraseLineIfFillLinesAndThenCollapse();
    bool isValidation( TFigure* destFigure);
    
    TFigure* m_currentFigure;
    BoardType m_board;
};

}

#endif //TERIS_FIGURE_CLASS_FIGUREBOARD_H
