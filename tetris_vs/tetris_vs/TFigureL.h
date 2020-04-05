#pragma once


#define TETRIS_TFIGUREL
#ifdef TETRIS_TFIGUREL

#include <tuple>
#include "TType.h"
#include "TFigure.h"
//#include "TFigureBuilder.h"

/***************************************************
*		  □ □ □ □	 □ □ ■ □   □ □ □ ■	 □ ■ ■ □   *
*		  □ ■ ■ ■	 □ □ ■ □   □ ■ ■ ■   □ □ ■ □   *
*		  □ ■ □ □    □ □ ■ ■   □ □ □ □   □ □ ■ □   *
*		  □ □ □ □    □ □ □ □   □ □ □ □   □ □ □ □   *
*	type  	 A		    B		  C			D	   *
*	width	 3		    2		  3			2	   *
*	height   2		    3		  2			3	   *
*												   *
***************************************************/

namespace tetris {

class TFigureBuilder;
class TFigureL : public TFigure {
public:
    
    virtual ~TFigureL();
    virtual void initialize() override;
    virtual  TFigureType getTypeBegin()  override;
    virtual  TFigureType getTypeEnd()  override;


    //hide base ctr, make object from builder
    static TFigureL* get( TFigureBuilder *bld) {
        auto figure =  new TFigureL(bld);
        figure->initialize ();
        return figure;
    }

    TFigureL(){}

private:

    TFigureL( TFigureBuilder *bld);
    virtual bool _validation() override;
    virtual TFigure* _copy() override;
    //implement pure virtual funtions.
    virtual void _rotateLeft() override;
    virtual void _rotateRight() override;
};



}

#endif