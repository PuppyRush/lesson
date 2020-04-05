//
// Created by chaed on 18. 11. 24.
//

#include <random>
#include <algorithm>
#include <set>

#include "TypeTraits.h"
#include "TFigureBoard.h"
#include "TFigureBuilder.h"
#include "TFigureL.h"
#include "TFigureZ.h"

using namespace tetris;

TFigureBoard::TFigureBoard()
    : m_currentFigure(nullptr) {
    createNextFigureRandomly();

    for (int i = 0 ; i < m_board.size() ; i++) {
        auto board = m_board[i];
        for (int l = 0 ; l < board.size() ; l++) {
            board[l] = TFigureUnit(TPoint(i, l), 0, TColor::none, TFigureUnit::UnitType::Empty);
        }
    }
}

void TFigureBoard::createNextFigureRandomly() {
    if (m_currentFigure) {
        m_currentFigure = nullptr;
    }

    TFigureBuilder *bld = new TFigureBuilder(TPoint(BOARD_WIDTH_COUNT / 2 - 1, 2));
    m_currentFigure = bld->build();

    setCoords();
}

TFigure* TFigureBoard::getCurrentFigure() {
    return m_currentFigure;
}

TFigureBoard* TFigureBoard::get() {
    static auto board = new TFigureBoard();
    return board;
}

void TFigureBoard::goStraightDown()
{
    eraseCoords();

    TFigure* copied(nullptr);
    while(isValidation(m_currentFigure))
    {
        copied = m_currentFigure->goDown();
    }

    if(copied)
    {
        m_currentFigure = copied;
        setCoords();
    }

    eraseLineIfFillLinesAndThenCollapse();
    createNextFigureRandomly();

    setCoords();
}

void TFigureBoard::rotate() {

    eraseCoords();

    auto copied = m_currentFigure->rotateLeft();
    if (!isValidation(m_currentFigure))
        m_currentFigure = copied;

    setCoords();
}

void TFigureBoard::goDown() {

    eraseCoords();

    auto copied = m_currentFigure->goDown();

    if (!isValidation(m_currentFigure)) {
        m_currentFigure = copied;
        setCoords();
        createNextFigureRandomly();
    }

    setCoords();
}

void TFigureBoard::goLeft() {

    eraseCoords();

    auto copied = m_currentFigure->goLeft();
    if (!isValidation(m_currentFigure))
        m_currentFigure = copied;

    setCoords();
}

void TFigureBoard::goRight() {

    eraseCoords();

    auto copied = m_currentFigure->goRight();
    if (!isValidation(m_currentFigure))
        m_currentFigure = copied;

    setCoords();
}

 bool TFigureBoard::isValidation( TFigure *destFigure) {

    for ( auto coord : m_currentFigure->getCoords()) {
         auto x = coord.getPoint().x;
         auto y = coord.getPoint().y;

        if (y < 0 || y >= BOARD_HEIGHT_COUNT  || x < 0 || x >= BOARD_WIDTH_COUNT)
            return false;

        if (m_board[y][x].getType() == TFigureUnit::UnitType::Fill)
            return false;
    }

    return true;
}

void TFigureBoard::eraseCoords() {
    for ( auto coord : m_currentFigure->getCoords()) {
        auto x = coord.getPoint().x;
        auto y = coord.getPoint().y;
        m_board[y][x].setType(TFigureUnit::UnitType::Empty);
        m_board[y][x].setColor(TColor::none);
    }
}

void TFigureBoard::setCoords() {
    for ( auto coord : m_currentFigure->getCoords()) {
         auto x = coord.getPoint().x;
         auto y = coord.getPoint().y;
        m_board[y][x].setType(TFigureUnit::UnitType::Fill);
        m_board[y][x].setColor(coord.getColor());
    }
}

bool TFigureBoard::eraseLineIfFillLinesAndThenCollapse()
{
    std::set<tetris::t_coord, std::greater<t_coord>> collapseHeights;
    for(t_coord y = BOARD_HEIGHT_COUNT-1 ; y >= 0 ; --y)
    {
        int x=0;
        for(; x < BOARD_WIDTH_COUNT ; ++x)
        {
            if(m_board[y][x].getType() == TFigureUnit::UnitType ::Empty)
                break;
        }
        if(x==BOARD_WIDTH_COUNT) {
            collapseHeights.insert(y);
            for(int x=0; x < BOARD_WIDTH_COUNT ; ++x)
            {
                m_board[y][x].setType(TFigureUnit::UnitType::Empty);
                m_board[y][x].setColor(TColor::none);
            }
        }
    }

    if(collapseHeights.empty())
        return false;

    for(t_coord x=0 ; x < BOARD_WIDTH_COUNT ; ++x)
    {
        for(t_coord y = BOARD_HEIGHT_COUNT-1 ; y >= 0 ; --y)
        {
            if(m_board[y][x].getType() == TFigureUnit::UnitType ::Fill)
            {
                 size_t removedCnt = std::count_if(collapseHeights.begin(), collapseHeights.end(),
                    [y]( auto _y){
                        return y < _y;
                    });

                if(removedCnt>0)
                {
                    m_board[y+removedCnt][x].setType(TFigureUnit::UnitType::Fill);
                    m_board[y+removedCnt][x].setColor(m_board[y][x].getColor());
                    m_board[y][x].setType(TFigureUnit::UnitType::Empty);
                    m_board[y][x].setColor(TColor::none);
                }
            }
        }
    }

    return true;
}