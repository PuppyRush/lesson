#pragma once

	//enum과 enum class 각 특징과 차이
	//https://www.cppkorea.org/CppCoreGuidelines/Enum/
	enum Color
	{
		eRed,
		eYellow,
		eWhite
	};

	enum UnitType
	{
		eFeed,
		eWall,
		eHurdle,
		eWorm,
		eNone
	};

	class Unit
	{

	public:

		Unit() = default;
		//아래 주석문으로 기본 생성자를 대체 한다면 어떻게 될것인가?
		//Unit() = delete;

		Unit(size_t x, size_t y);

		//컴파일단계? 전처리단계?
		inline void setX(const size_t x)
		{
			this->x = x;
		}

		inline void setY(const size_t y)
		{
			this->y = y;
		}
		
		inline size_t getX()
		{
			return this->x;
		}

		inline size_t getY()
		{
			return this->y;
		}

		inline void setColor(const Color color)
		{
			this->color = color;
		}

		inline void setType(const UnitType type)
		{
			this->type = type;
		}

	private:
		size_t x;
		size_t y;
		Color color;
		UnitType type;
	};


