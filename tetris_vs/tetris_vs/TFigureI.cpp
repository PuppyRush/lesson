#include "TFigureI.h"
#include "TypeTraits.h"

using namespace tetris;

TFigureI::TFigureI (TFigureBuilder *bld)
    : TFigure (bld)
{
    _rotateLeft ();
}

TFigureI::~TFigureI ()
{
}

void TFigureI::initialize ()
{
    m_figureTypeCount = toUType (getTypeEnd ()) - toUType (getTypeBegin ());
}

void TFigureI::_rotateLeft ()
{
    m_relativeCoord[0].setPoint (TPoint (m_point.x, m_point.y));

    switch (m_figureType)
    {
        case TFigureType::A:
            m_relativeCoord[1].setPoint (TPoint (m_point.x, m_point.y-1));
            m_relativeCoord[2].setPoint (TPoint (m_point.x, m_point.y-2));
            m_relativeCoord[3].setPoint (TPoint (m_point.x, m_point.y+1));
            m_figureType = TFigureType::B;
            break;
        case TFigureType::B:
            m_relativeCoord[1].setPoint (TPoint (m_point.x-1, m_point.y));
            m_relativeCoord[2].setPoint (TPoint (m_point.x-2, m_point.y));
            m_relativeCoord[3].setPoint (TPoint (m_point.x+1, m_point.y));
            m_figureType = TFigureType::A;
            break;
        default:
            assert(0);
    }
}

void TFigureI::_rotateRight ()
{

}

bool TFigureI::_validation()
{
    return false;
}

 TFigureType TFigureI::getTypeBegin () 
{
    return TFigureType::A;
}

 TFigureType TFigureI::getTypeEnd () 
{
    return TFigureType::B;
}

TFigure* TFigureI::_copy()
{
    return new TFigureI();
}