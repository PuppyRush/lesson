#pragma once
#include "ctor_dtor.h"
#include <string>

using namespace std;

int main()
{
	Animal animal;
	Animal* animal_ptr = new Animal{};

	Animal& animal_ref = animal;
	animal_ref.SetName(new string{ "abc" });

	string str;
	animal_ptr->SetName(str);
	animal_ptr->SetName(&str);

	
}