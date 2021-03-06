#include "TFigureZ.h"
#include "TypeTraits.h"

using namespace tetris;

TFigureZ::TFigureZ ( TFigureBuilder *bld)
    : TFigure (bld)
{
    _rotateLeft ();
}

TFigureZ::~TFigureZ ()
{
}

void TFigureZ::initialize ()
{
    m_figureTypeCount = toUType (getTypeEnd ()) - toUType (getTypeBegin ());
}

void TFigureZ::_rotateLeft ()
{
    m_relativeCoord[0].setPoint (TPoint (m_point.x, m_point.y));

    switch (m_figureType)
    {
        case TFigureType::A:
            m_relativeCoord[1].setPoint (TPoint (m_point.x, m_point.y-1));
            m_relativeCoord[2].setPoint (TPoint (m_point.x + 1, m_point.y));
            m_relativeCoord[3].setPoint (TPoint (m_point.x + 1, m_point.y+1));
            m_figureType = TFigureType::B;
            break;
        case TFigureType::B:
            m_relativeCoord[1].setPoint (TPoint (m_point.x+1, m_point.y));
            m_relativeCoord[2].setPoint (TPoint (m_point.x-1, m_point.y + 1));
            m_relativeCoord[3].setPoint (TPoint (m_point.x, m_point.y + 1));
            m_figureType = TFigureType::A;
            break;
        default:
            assert(0);
    }
}

void TFigureZ::_rotateRight ()
{

}

bool TFigureZ::_validation()
{
    return false;
}

 TFigureType TFigureZ::getTypeBegin () 
{
    return TFigureType::A;
}

 TFigureType TFigureZ::getTypeEnd () 
{
    return TFigureType::B;
}

TFigure* TFigureZ::_copy()
{
    return new TFigureZ();
}