#pragma once

	//enum�� enum class �� Ư¡�� ����
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
		//�Ʒ� �ּ������� �⺻ �����ڸ� ��ü �Ѵٸ� ��� �ɰ��ΰ�?
		//Unit() = delete;

		Unit(size_t x, size_t y);

		//�����ϴܰ�? ��ó���ܰ�?
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


