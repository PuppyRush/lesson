#include "Unit.h"
#include <iostream>

Unit::Unit(size_t x, size_t y)
	:x(x), y(y), type(eNone)
{
	std::cout << "Call Ctor Unit x,y" << x << y;
}
