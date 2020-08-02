#include "animal_basic.h"

#include <string>
#include <iostream>

//https://modoocode.com/173#page-heading-2
//함수의 오버로딩 특징
//1 단계
//자신과 타입이 정확히 일치하는 함수를 찾는다.

//2 단계
//정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
//(형변환 중 손실이 일어나지 않도록 자기보다 data-type이 큰것을 찾아간다
//Char, unsigned char, short 는 int 로 변환된다.
//Unsigned short 는 int 의 크기에 따라 int 혹은 unsigned int 로 변환된다.
//Float 은 double 로 변환된다.
//Enum 은 int 로 변환된다.

//3 단계
//위와 같이 변환해도 일치하는 것이 없다면 아래의 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
//임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. (예를 들어 float -> int)
//Enum 도 임의의 숫자 타입으로 변환된다(예를 들어 Enum -> double)
//0 은 포인터 타입이나 숫자 타입으로 변환된 0 은 포인터 타입이나 숫자 타입으로 변환된다
//포인터는 void 포인터로 변환된다.

//4 단계
//유저 정의된 타입 변환으로 일치하는 것을 찾는다. (파라미터의 객체의 생성자 중 변환이 가능한것을 찾는다)

//오버로딩의 모호함으로 인해 사고를 방지하고 싶다면 애당초 오버로딩으로 함수를 만드는것이 아니라 이름을 달리 한다.
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

	//범위지정자는 기본 private
public:

	//생성자의 호출 시점.
	//동적변수와 정적변수일때 모두 동일하다.

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

	//생성자 오버로딩
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
	{}
	~Animal()
	{
		//동적 할당한 name의 객체를 해제하지 않는다면 memory leak 발생.
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

	//지양해야할 오버로딩
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
