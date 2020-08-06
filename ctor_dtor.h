#include "animal_basic.h"

#include <string>
#include <iostream>

enum class EnumColor
{
	Black,
	Red,
	Yellow,
	None
};


enum class EnumSex
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
		:age(20), sex(EnumSex::None), color(EnumColor::Black),name(nullptr)
	{
		std::cout << "Call Ctor %x " << this << std::endl;
		name = new std::string{};
	}

	//RAII
	//������ �����ε�
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
		//������ �ʱ�ȭ ����Ʈ(Initialize List) �� ��� ����
		//1. �����Ϸ��� �ʱⰪ�� �ƴ� �����ڰ� ������ �ʱⰪ�� �ʿ��� ���
		//2. ������ ����� ���� ��� ��� ������ �ִ� ���.
		//3. �θ�Ŭ������ �����ڸ� ȣ���ϴ� ���.
	{

	}

	//�Ҹ��� destructor dtor
	//�Ҹ��ڴ� �����ε� ����� �ȵ�.
	//�Ҹ����� ȣ�� ����.
	//���������� �Ҵ�� ��������(stack-frame)�� ������� �޸𸮿��� �����Ǹ鼭 �Ҹ��ڰ� ȣ��ǳ� 
	//���������� delete�� ��������� ȣ���ϰ� �Ǵ� ��쿡 ȣ��ȴ�.
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

	
	void SetName(std::string& _name)
	{
		name = &_name;

	}
private:
	//member variable
	int age;
	EnumColor color;
	EnumSex sex;
	std::string* name;

};


//Getter,Setter�� �ǹ�?
//new, delete�� �ǹ̿� Ȱ��
//�������� Ư¡?

//�ڵ�� �����Ͽ� - Ŭ����/�Լ�/�����̸� ����.