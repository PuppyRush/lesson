#pragma once


#define TETRIS_TFIGUREO
#ifdef TETRIS_TFIGUREO

#include <tuple>
#include "TType.h"
#include "TFigure.h"
//#include "TFigureBuilder.h"

/*********************
*		  □ □ □ □	 *
*		  □ ■ ■ □	 *
*		  □ ■ ■ □    *
*		  □ □ □ □    *
*	type  	 A		 *
*	width	 2		 *
*	height   2		 *
**********************/

namespace tetris {

class TFigureBuilder;
class TFigureO : public TFigure {
public:

    virtual ~TFigureO();
    virtual void initialize() override;
    virtual  TFigureType getTypeBegin()  override;
    virtual  TFigureType getTypeEnd()  override;


    //hide base ctr, make object from builder
    static TFigureO* get( TFigureBuilder *bld)
    {
        auto figure =  new TFigureO(bld);
        figure->initialize ();
        return figure;
    }

private:
    TFigureO(){}
    TFigureO( TFigureBuilder *bld);
    virtual bool _validation() override;
    virtual TFigure* _copy() override;
    virtual void _rotateLeft() override;
    virtual void _rotateRight() override;
};

}

#endif