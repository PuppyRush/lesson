//
// Created by chaed on 18. 11. 24.
//

#ifndef TERIS_FIGURE_CLASS_BOARDCONTROLLER_H
#define TERIS_FIGURE_CLASS_BOARDCONTROLLER_H

#include <memory>

#include "TFigureBoard.h"

namespace tetris
{

//controller as a proxy class for tetris
class BoardController {

public:
    ~BoardController()
    {
        delete BoardController::get();
    }
    
     void rotate() 
    { m_board->rotate ();}

     void goStraightDown() 
    { m_board->goStraightDown ();}

     void goDown() 
    { m_board->goDown ();}
    
     void goLeft() 
    { m_board->goLeft ();}
    
     void goRight() 
    {m_board->goRight ();}
    
     TFigureBoard::BoardType getGameBoard() 
    {return TFigureBoard::get ()->getBoard ();}
    
    //singleton
    static BoardController* get()
    {
      static auto ctl = new BoardController();
      return ctl;
    }
    
private:
    BoardController();

    TFigureBoard* m_board;
};

}

#endif //TERIS_FIGURE_CLASS_BOARDCONTROLLER_H
