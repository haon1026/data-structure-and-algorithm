# include <stdio.h>

/*
long f(long n)
{
	long mult;
	//while(n != 1)�Ǵ���ģ������nһֱ��Ϊ0������ѭ��
	if(n != 1)
	{
		mult = n * f(n-1);
	}
	if(n == 1)
		mult = 1;

	return mult;
}
*/

long f(long n)
{
	if(1 == n)
		return 1;
	else
		return f(n-1) * n;
}

int main(void)
{
	printf("%ld\n", f(6));
	
	return 0;
}