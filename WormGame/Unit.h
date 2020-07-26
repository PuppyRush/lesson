#pragma once

enum Color
{
	Red,
	Yellow,
	White
};

class Unit
{

public:
	Unit() = default;
	Unit(size_t x, size_t y);

	inline void setX(const size_t x)
	{
		this->x = x;
	}

	inline void setY(const size_t y)
	{
		this->y = y;
	}

	inline void setColor(const Color color)
	{
		this->color = color;
	}

private:
	size_t x;
	size_t y;
	Color color;

};

