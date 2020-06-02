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

	//������ constructor ctor
	//default ctor
	Animal()
		:age(20), sex(EnumSex::Female), color(EnumColor::Black)
	{
		name = new std::string{};
	}

	//������ �����ε�
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
	{}

	//�Ҹ��� destructor dtor
	//�Ҹ��ڴ� �����ε� ����� �ȵ�.
	~Animal()
	{
		//���� �Ҵ��� name�� ��ü�� �������� �ʴ´ٸ� memory leak �߻�.
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

	//�޸� ������ ���� ������ �߻��Ѵ�.
	void SetName(std::string* _name)
	{
		name = _name;
	}
};