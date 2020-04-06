#pragma once

#include "TType.h"

namespace tetris {

enum class UnitType
{
    Fill,
    Empty
};

class TFigureUnit {
public:
    
    TFigureUnit();
    TFigureUnit( TPoint point,  t_age age,  TColor color,  UnitType type);
    ~TFigureUnit();
    
    bool operator!=( TFigureUnit& unit);
    
     TPoint getPoint () ;
    void setPoint ( TPoint m_point);
    
     t_age getAge () ;
    void setAge (t_age m_age);
    
     TColor getColor () ;
    void setColor (TColor m_color);
    
    UnitType getType () ;
    void setType (UnitType m_type);
    
    static TFigureUnit& getDefaultUnit()
    {
        static TFigureUnit unit(TPoint(0,0), 0,TColor::none, UnitType::Empty);
        return unit;
    }

private:
    TPoint m_point;
    t_age m_age;
    TColor m_color;
    UnitType m_type;
    
};

}