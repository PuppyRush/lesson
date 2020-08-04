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

//범위지정자는 기본 private
public:

	//생성자의 호출 시점.
	//동적변수와 정적변수일때 모두 동일하다.

	Animal()
		:age(20), sex(EnumSex::None), color(EnumColor::Black),name(nullptr)
	{
		name = new std::string{};
	}

	//RAII
	//생성자 오버로딩
	Animal(int _age, EnumColor _color, EnumSex _sex, std::string* _name)
		:age(_age), color(_color), sex(_sex), name(_name)
		//생성자 초기화 리스트(Initialize List) 의 사용 의의
		//1. 컴파일러의 초기값이 아닌 개발자가 정의한 초기값이 필요한 경우
		//2. 복사의 비용이 많이 비싼 멤버 변수가 있는 경우.
		//3. 부모클래스의 생성자를 호출하는 경우.
	{

	}

	//소멸자 destructor dtor
	//소멸자는 오버로딩 대상이 안됨.
	//소멸자의 호출 시점.
	//정적변수는 할당된 지역공간(stack-frame)이 사라질때 메모리에서 정리되면서 소멸자가 호출되나 
	//동적변수는 delete를 명시적으로 호출하게 되는 경우에 호출된다.
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


//Getter,Setter의 의미?
//new, delete의 의미와 활용
//참조자의 특징?

//코드와 관련하여 - 클래스/함수/변수이름 짓기.