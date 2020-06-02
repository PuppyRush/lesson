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
	short footCount;
	float height;
	double weight;
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

	void Set(int _age)
	{
		age = _age;
	}

	void Set(EnumColor _color)
	{
		color = _color;
	}

	void Set(EnumSex _sex)
	{
		sex = _sex;
	}

	//�޸� ������ ���� ������ �߻��Ѵ�.
	void Set(std::string* _name)
	{
		name = _name;
	}

	//age���� ����ȯ ����
	void Set(short _fc)
	{
		footCount = _fc;
	}

	void Set(double _weight)
	{
		weight = _weight;
	}

	void Set(float _height)
	{
		height = _height;
	}
};