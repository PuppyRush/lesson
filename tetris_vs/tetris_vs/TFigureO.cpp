#include "TFigureO.h"
#include "TypeTraits.h"

using namespace tetris;

TFigureO::TFigureO ( TFigureBuilder *bld)
    : TFigure (bld)
{
    _rotateLeft ();
}

TFigureO::~TFigureO ()
{
}

void TFigureO::initialize ()
{
    m_figureTypeCount = toUType (getTypeEnd ()) - toUType (getTypeBegin ());
}

void TFigureO::_rotateLeft ()
{
    m_relativeCoord[0].setPoint (TPoint (m_point.x, m_point.y));

    switch (m_figureType)
    {
        case TFigureType::A:
            m_relativeCoord[1].setPoint (TPoint (m_point.x-1, m_point.y));
            m_relativeCoord[2].setPoint (TPoint (m_point.x -1, m_point.y + 1));
            m_relativeCoord[3].setPoint (TPoint (m_point.x, m_point.y+1));
            m_figureType = TFigureType::B;
            break;
        default:
            assert(0);
    }
}

void TFigureO::_rotateRight ()
{

}

bool TFigureO::_validation()
{
    return false;
}

 TFigureType TFigureO::getTypeBegin () 
{
    return TFigureType::A;
}

 TFigureType TFigureO::getTypeEnd () 
{
    return TFigureType::A;
}

TFigure* TFigureO::_copy()
{
    return new TFigureO();
}