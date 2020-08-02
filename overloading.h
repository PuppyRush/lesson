#include "animal_basic.h"

#include <string>
#include <iostream>

//https://modoocode.com/173#page-heading-2
//�Լ��� �����ε� Ư¡
//1 �ܰ�
//�ڽŰ� Ÿ���� ��Ȯ�� ��ġ�ϴ� �Լ��� ã�´�.

//2 �ܰ�
//��Ȯ�� ��ġ�ϴ� Ÿ���� ���� ��� �Ʒ��� ���� ����ȯ�� ���ؼ� ��ġ�ϴ� �Լ��� ã�ƺ���.
//(����ȯ �� �ս��� �Ͼ�� �ʵ��� �ڱ⺸�� data-type�� ū���� ã�ư���
//Char, unsigned char, short �� int �� ��ȯ�ȴ�.
//Unsigned short �� int �� ũ�⿡ ���� int Ȥ�� unsigned int �� ��ȯ�ȴ�.
//Float �� double �� ��ȯ�ȴ�.
//Enum �� int �� ��ȯ�ȴ�.

//3 �ܰ�
//���� ���� ��ȯ�ص� ��ġ�ϴ� ���� ���ٸ� �Ʒ��� ���� �������� ����ȯ�� ���� ��ġ�ϴ� �Լ��� ã�´�.
//������ ����(numeric) Ÿ���� �ٸ� ���� Ÿ������ ��ȯ�ȴ�. (���� ��� float -> int)
//Enum �� ������ ���� Ÿ������ ��ȯ�ȴ�(���� ��� Enum -> double)
//0 �� ������ Ÿ���̳� ���� Ÿ������ ��ȯ�� 0 �� ������ Ÿ���̳� ���� Ÿ������ ��ȯ�ȴ�
//�����ʹ� void �����ͷ� ��ȯ�ȴ�.

//4 �ܰ�
//���� ���ǵ� Ÿ�� ��ȯ���� ��ġ�ϴ� ���� ã�´�. (�Ķ������ ��ü�� ������ �� ��ȯ�� �����Ѱ��� ã�´�)

//�����ε��� ��ȣ������ ���� ��� �����ϰ� �ʹٸ� �ִ��� �����ε����� �Լ��� ����°��� �ƴ϶� �̸��� �޸� �Ѵ�.
//SetAge_int, SetAge_short ...

enum EnumColor
{
	Black,
	Red,
	Yellow,
	None
};


enum EnumSex
{
	Female,
	Male,
	None,
};

class Animal
{

	//���������ڴ� �⺻ private
public:

	//�������� ȣ�� ����.
	//���������� ���������϶� ��� �����ϴ�.

	Animal()
		:age(20), sex(EnumSex::None), color(EnumColor::Black)
	{
		name = new std::string{};
	}
	
	Animal(int age, std::string _name)
		:age(20), sex(EnumSex::None), color(EnumColor::Black)
	{
		this->name = &_name;
	}

	//������ �����ε�
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
	{}
	~Animal()
	{
		//���� �Ҵ��� name�� ��ü�� �������� �ʴ´ٸ� memory leak �߻�.
		if (name != nullptr)
			delete name;
	}

	//Getter
	int GetAge()
	{
		return age;
	}

	//Setter
	void SetAge(int _age)
	{
		age = _age;
	}

	void SetAge(double _age)
	{
		age = static_cast<int>(_age);
	}

	//�����ؾ��� �����ε�
	void SetColor(EnumColor _color)
	{
		color = _color;
	}

	void SetColor(int _color)
	{
		color = static_cast<EnumColor>(_color);
	}

	void SetSex(EnumSex _sex)
	{
		sex = _sex;
	}

	void SetName(std::string* _name)
	{
		name = _name;
	}

private:
	//member variable
	int age;
	EnumColor color;
	EnumSex sex;
	std::string* name;

};
