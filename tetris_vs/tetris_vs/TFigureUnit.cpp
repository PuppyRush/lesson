#include "TFigureUnit.h"

using namespace tetris;

TFigureUnit::TFigureUnit()
    :m_type(UnitType::Empty),
     m_point(TPoint(0,0)),
     m_color(TColor::none),
     m_age(0)
{

}

TFigureUnit::TFigureUnit( TPoint point,  t_age age,  TColor color,  UnitType type)
    :m_type(type),
    m_point(point),
    m_color(color),
    m_age(age)
{
}


TFigureUnit::~TFigureUnit()
{
}

 TPoint TFigureUnit::getPoint () 
{
    return m_point;
}

void TFigureUnit::setPoint ( TPoint m_point)
{
    TFigureUnit::m_point = m_point;
}

 t_age TFigureUnit::getAge () 
{
    return m_age;
}

void TFigureUnit::setAge (t_age m_age)
{
    TFigureUnit::m_age = m_age;
}

 TColor TFigureUnit::getColor () 
{
    return m_color;
}

void TFigureUnit::setColor (TColor m_color)
{
    TFigureUnit::m_color = m_color;
}

TFigureUnit::UnitType TFigureUnit::getType () 
{
    return m_type;
}

void TFigureUnit::setType (TFigureUnit::UnitType m_type)
{
    TFigureUnit::m_type = m_type;
}

bool TFigureUnit::operator!=( TFigureUnit& unit)
{
    return (this->getPoint ().x != unit.getPoint ().x || this->getPoint ().y != unit.getPoint ().y);
}