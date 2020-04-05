#pragma once


#define TETRIS_TFIGUREH
#ifdef TETRIS_TFIGUREH

#include <tuple>
#include "TType.h"
#include "TFigure.h"
//#include "TFigureBuilder.h"

/********************************
*		  □ □ □ □	 □ □ ■ □    *
*		  □ □ ■ ■	 □ □ ■ ■    *
*		  □ ■ ■ □    □ □ □ ■    *
*		  □ □ □ □    □ □ □ □    *
*	type  	 A		    B	    *
*	width	 3		    2	    *
*	height   2		    3	    *
*								*
********************************/

namespace tetris {

class TFigureBuilder;
class TFigureZ : public TFigure {
public:

    virtual ~TFigureZ();
    virtual void initialize() override;
    virtual  TFigureType getTypeBegin()  override;
    virtual  TFigureType getTypeEnd()  override;


    //hide base ctr, make object from builder
    static TFigureZ* get( TFigureBuilder *bld)
    {
        auto figure =  new TFigureZ(bld);
        figure->initialize ();
        return figure;
    }

private:
    TFigureZ(){}
    TFigureZ( TFigureBuilder *bld);
    virtual bool _validation() override;
    virtual TFigure* _copy() override;
    virtual void _rotateLeft() override;
    virtual void _rotateRight() override;
};

}

#endif