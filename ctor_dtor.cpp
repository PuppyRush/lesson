#include "animal_basic.h"

#include <string>
#include <iostream>

enum class EnumColor
{
	Black,
	Red,
	Yellow,
};


enum class EnumSex
{
	Female,
	Male
};

class Animal
{
	int age;
	EnumColor color;
	EnumSex sex;
	std::string* name;

	//생성자 constructor ctor
	//default ctor
	Animal()
		:age(20), sex(EnumSex::Female), color(EnumColor::Black)
	{
		name = new std::string{};
	}

	//생성자 오버로딩
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
	{}

	//소멸자 destructor dtor
	//소멸자는 오버로딩 대상이 안됨.
	~Animal()
	{
		//동적 할당한 name의 객체를 해제하지 않는다면 memory leak 발생.
		if (name != nullptr)
			delete name;
	}

	int GetAge()
	{
		return age;
	}

	void SetAge(int _age)
	{
		age = _age;
	}

	void SetColor(EnumColor _color)
	{
		color = _color;
	}

	void SetSex(EnumSex _sex)
	{
		sex = _sex;
	}

	//메모리 관리에 대한 문제가 발생한다.
	void SetName(std::string* _name)
	{
		name = _name;
	}
};