//#include <iostream>
//
////두 수를 함수 내에서 바꿉니다.
//void func_by_value(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////두 수를 함수 내에서 바꿉니다.
//void func_by_pointer(int* a, int* b) //포인터로도 구현 가능
//{
//	int* temp = a;
//	*a = *b;
//	*b = *temp;
//}
//
//
////두 수를 함수 내에서 바꿉니다.
//void func_by_ref(int& a, int& b) //포인터로도 구현 가능
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main(void)
//{
//	using namespace std;
//
//	int a = 10;
//	int b = 20;
//	cout << "before function" << endl;
//	cout << "a : " << a << endl;
//	cout << " b : " << b << endl << endl << endl;
//
//	func_by_value(a, b); // a, b 의 값은 그대로
//	cout << "after function" << endl;
//	cout << "a : " << a << endl;
//	cout << " b : " << b << endl << endl << endl;
//
//
//	func_by_ref(a, b); // a, b 의 값이 서로 바뀌어 있다.
//	cout << "after function" << endl;
//	cout << "a : " << a << endl;
//	cout << " b : " << b << endl << endl << endl;
//
//	return 0;
//}