#include <stdio.h>

int GCD(int x, int y)
{
	int min, gcd;

	if (x > y)
	{
		min = y;
	}
	else
	{
		min = x;
	}

	for (int i = 1; i <= min; i++)
	{
		if ((x % i == 0) && (y % i == 0))
		{
			gcd = i;
		}
	}
	return gcd;
}

int main()
{
	int a, b;

	printf("최대공약수를 구할 2개의 수를 입력하시오: ");
	scanf("%d %d", &a, &b);

	printf("%d와 %d의 최대공약수는 %d \n", a, b, GCD(a, b));
}