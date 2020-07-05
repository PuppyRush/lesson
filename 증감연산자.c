
void operator1()
{
	int x = 0;
	int y = 10;
	if (x++ && --x)
	{
		y++;
	}

	int b = y++ - ++y;
	y = b++ - y;

	//x,y,b의 값은?
	printf("%d %d %d\n", x, y, b);
}


int operator2() {

	int y = 3;

	int sum1 = ++y;
	sum1 = y++;
	sum1 = y++ + ++y;

	int x = 5;
	int sum2 = x++ + ++x + ++x;

	//https://msdn.microsoft.com/ko-kr/library/2bxt6kc4.aspx
	//어셈블리까지 보고 싶다면? http://ehclub.co.kr/431

	printf("%d \n", sum2);

	return 0;


}
