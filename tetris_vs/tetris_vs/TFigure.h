#pragma once


#include <cassert>
#include <memory>
#include <deque>
#include <numeric>
#include <array>

#include "TType.h"
#include "TFigureUnit.h"

/***********************************************
*		            □ □ □ □                    *
*		            □ □ ■ □                    *
*		            □ □ □ □                    *
*		            □ □ □ □                    *
*	   	      Relatevie Coordnation		       *
*	(x-2,y-1) (x  ,y-1) (x,y-1)	 (x  ,y-1)     *
*	(x-2,y  ) (x-1,y  ) (x,y  )	 (x+1,y  )     *
*	(x-2,y+1) (x-1,y+1) (x,y+1)	 (x+1,y+1)     *
*	(x-2,y+2) (x-1,y+2) (x,y+2)	 (x+1,y+2)     *
***********************************************/

namespace tetris {


class TFigureBuilder;
class TFigure {
public:

    using FigureCoords = std::array<TFigureUnit, 4>;
    
    virtual ~TFigure();

    TFigureType getType()
    { return m_figureType;}
    
    size_t getWidth()
    { return m_width;}
    
    size_t getHeight()
    { return m_height;}
    
    TPoint getPoint()
    { return m_point;}
    
    FigureCoords getCoords()
    { return m_relativeCoord; }

    TFigure* goRight();
    TFigure* goLeft();
    TFigure* goDown();
    TFigure* rotateLeft();
    TFigure* rotateRight();
    TFigure* copy() ;
    virtual  TFigureType getRandomlyFigureType() ;

    //pure virtual function
    virtual void initialize() = 0;
    virtual  TFigureType getTypeBegin()  = 0;
    virtual  TFigureType getTypeEnd()  = 0;

protected:
    TFigure( TFigureBuilder *bld);
    TFigure();

    t_size m_figureTypeCount;
    t_size m_width;
    t_size m_height;
    TPoint m_point;
    TFigureType m_figureType;
    FigureCoords m_relativeCoord;
    
private:

    virtual void _goRight();
    virtual void _goLeft();
    virtual void _goDown();

    //pure virtual function
    virtual TFigure* _copy() = 0;
    virtual bool _validation() = 0;
    virtual void _rotateLeft() = 0;
    virtual void _rotateRight() = 0;
};

}

