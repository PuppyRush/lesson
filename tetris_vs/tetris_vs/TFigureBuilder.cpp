//
// Created by chaed on 18. 11. 25.
//

#include "TFigureBuilder.h"
#include "TypeTraits.h"

using namespace tetris;

TFigureBuilder::TFigureBuilder( TPoint point)
    : m_point(point),
      m_width(0),
      m_height(0),
      m_color(EnumHelper<TColor>::getRandomly ()),
      m_age(1),
      m_figureType(TFigureType::A),
      m_figureClass(EnumHelper<TFigureClass>::getRandomly())
  {
  }


TFigureBuilder* TFigureBuilder::color( TColor color)
{
    this->m_color = color;
    return this;
}

TFigureBuilder* TFigureBuilder::type( TFigureType type)
{
    this->m_figureType = type;
    return this;
}

TFigureBuilder* TFigureBuilder::age( t_age age)
{
    this->m_age = age;
    return this;
}

TFigureBuilder *TFigureBuilder::figure( TFigureClass figure)
{
    this->m_figureClass = figure;
    return this;
}

TFigure* TFigureBuilder::build()
{
    switch(getClass())
    {
        case TFigureClass::L:
            return TFigureL::get(this);
        case TFigureClass::Z:
            return TFigureZ::get(this);
        case TFigureClass ::I:
            return TFigureI::get(this);
        case TFigureClass ::O:
            return TFigureO::get(this);
        case TFigureClass ::T:
            return TFigureT::get(this);
        default:
            assert(0);
    }
}

