#pragma once


#include "TFigure.h"
#include "TFigureL.h"
#include "TFigureZ.h"
#include "TFigureI.h"
#include "TFigureT.h"
#include "TFigureO.h"
#include "TType.h"

namespace tetris
{

class TFigureBuilder {
public:

    TFigureBuilder( TPoint point);
    virtual ~TFigureBuilder() {}

    TFigureBuilder *color( TColor color);
    TFigureBuilder *type( TFigureType type);
    TFigureBuilder *age( t_age age);
    TFigureBuilder *figure( TFigureClass figure);

    TPoint getPoint()   { return m_point; }
    TColor getColor()   { return m_color; }
    TFigureType getType()   { return m_figureType; }
    t_age getAge()   { return m_age; }
    t_size getHeight()   { return m_height; }
    t_size getWidth()   { return m_width; }
    TFigureClass getClass()   { return m_figureClass; }

    TFigure* build();

private:
     void width( t_size width)
    { m_width = width;}

     void height( t_size height)
    { m_height = height;}

    t_size m_width;
    t_size m_height;
    TColor m_color;
    TPoint m_point;
    TFigureType m_figureType;
    TFigureClass  m_figureClass;
    t_age m_age;
    
};

}
