#include "TFigureT.h"
#include "TypeTraits.h"

using namespace tetris;

TFigureT::TFigureT( TFigureBuilder *bld)
    : TFigure(bld) {
    _rotateLeft();
}

TFigureT::~TFigureT() {
}

void TFigureT::initialize() {
    m_figureTypeCount = toUType(getTypeEnd()) - toUType(getTypeBegin());
}

void TFigureT::_rotateLeft() {

    m_relativeCoord[0].setPoint(TPoint(m_point.x, m_point.y));

    switch (m_figureType) {
        case TFigureType::A:
            m_relativeCoord[1].setPoint(TPoint(m_point.x, m_point.y - 1));
            m_relativeCoord[2].setPoint(TPoint(m_point.x, m_point.y + 1));
            m_relativeCoord[3].setPoint(TPoint(m_point.x+1, m_point.y));
            m_figureType = TFigureType::B;
            break;
        case TFigureType::B:
            m_relativeCoord[1].setPoint(TPoint(m_point.x - 1, m_point.y));
            m_relativeCoord[2].setPoint(TPoint(m_point.x + 1, m_point.y));
            m_relativeCoord[3].setPoint(TPoint(m_point.x, m_point.y-1));
            m_figureType = TFigureType::C;
            break;
        case TFigureType::C:
            m_relativeCoord[1].setPoint(TPoint(m_point.x, m_point.y - 1));
            m_relativeCoord[2].setPoint(TPoint(m_point.x, m_point.y + 1));
            m_relativeCoord[3].setPoint(TPoint(m_point.x-1, m_point.y));
            m_figureType = TFigureType::D;
            break;
        case TFigureType::D:
            m_relativeCoord[1].setPoint(TPoint(m_point.x - 1, m_point.y));
            m_relativeCoord[2].setPoint(TPoint(m_point.x + 1, m_point.y));
            m_relativeCoord[3].setPoint(TPoint(m_point.x, m_point.y+1));
            m_figureType = TFigureType::A;
            break;
        default:
            assert(0);
    }
}

void TFigureT::_rotateRight() {

}

bool TFigureT::_validation() {
    return false;
}

 TFigureType TFigureT::getTypeBegin()  {
    return TFigureType::A;
}

 TFigureType TFigureT::getTypeEnd()  {
    return TFigureType::D;
}

TFigure* TFigureT::_copy() {
    return new TFigureT();
}