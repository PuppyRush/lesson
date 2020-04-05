#pragma once


#define TETRIS_TFigureT
#ifdef TETRIS_TFigureT

#include <tuple>
#include "TType.h"
#include "TFigure.h"

/***************************************************
*		  □ □ □ □	 □ □ ■ □   □ □ ■ □	 □ □ ■ □   *
*		  □ ■ ■ ■	 □ □ ■ ■   □ ■ ■ ■   □ ■ ■ □   *
*		  □ □ ■ □    □ □ ■ □   □ □ □ □   □ □ ■ □   *
*		  □ □ □ □    □ □ □ □   □ □ □ □   □ □ □ □   *
*	type  	 A		    B		  C			D	   *
*	width	 3		    2		  3			2	   *
*	height   2		    3		  2			3	   *
*												   *
***************************************************/

namespace tetris {

class TFigureBuilder;
class TFigureT : public TFigure {
public:

    virtual ~TFigureT();
    virtual void initialize() override;
    virtual  TFigureType getTypeBegin()  override;
    virtual  TFigureType getTypeEnd()  override;


    //hide base ctr, make object from builder
    static TFigureT* get( TFigureBuilder *bld) {
        auto figure =  new TFigureT(bld);
        figure->initialize ();
        return figure;
    }

    TFigureT(){}

private:

    TFigureT( TFigureBuilder *bld);
    virtual bool _validation() override;
    virtual TFigure* _copy() override;
    //implement pure virtual funtions.
    virtual void _rotateLeft() override;
    virtual void _rotateRight() override;
};



}

#endif