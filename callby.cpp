//#include <iostream>
//
////�� ���� �Լ� ������ �ٲߴϴ�.
//void func_by_value(int a, int b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////�� ���� �Լ� ������ �ٲߴϴ�.
//void func_by_pointer(int* a, int* b) //�����ͷε� ���� ����
//{
//	int* temp = a;
//	*a = *b;
//	*b = *temp;
//}
//
//
////�� ���� �Լ� ������ �ٲߴϴ�.
//void func_by_ref(int& a, int& b) //�����ͷε� ���� ����
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
//	func_by_value(a, b); // a, b �� ���� �״��
//	cout << "after function" << endl;
//	cout << "a : " << a << endl;
//	cout << " b : " << b << endl << endl << endl;
//
//
//	func_by_ref(a, b); // a, b �� ���� ���� �ٲ�� �ִ�.
//	cout << "after function" << endl;
//	cout << "a : " << a << endl;
//	cout << " b : " << b << endl << endl << endl;
//
//	return 0;
//}