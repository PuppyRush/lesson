#pragma once


#define TETRIS_TFIGUREI
#ifdef TETRIS_TFIGUREI

#include <tuple>
#include "TType.h"
#include "TFigure.h"

/********************************
*		  □ □ □ □	 □ □ ■ □    *
*		  ■ ■ ■ ■	 □ □ ■ □    *
*		  □ □ □ □    □ □ ■ □    *
*		  □ □ □ □    □ □ ■ □    *
*	type  	 A		    B	    *
*	width	 1		    4	    *
*	height   4		    1	    *
*								*
********************************/

namespace tetris {

class TFigureBuilder;
class TFigureI : public TFigure {
public:

    virtual ~TFigureI();
    virtual void initialize() override;
    virtual  TFigureType getTypeBegin()  override;
    virtual  TFigureType getTypeEnd()  override;


    //hide base ctr, make object from builder
    static TFigureI* get( TFigureBuilder *bld)
    {
        auto figure =  new TFigureI(bld);
        figure->initialize ();
        return figure;
    }

private:
    TFigureI() = default;
    TFigureI( TFigureBuilder *bld);
    virtual bool _validation() override;
    virtual TFigure* _copy() override;
    virtual void _rotateLeft() override;
    virtual void _rotateRight() override;
};

}

#endif