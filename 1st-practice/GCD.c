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

	printf("�ִ������� ���� 2���� ���� �Է��Ͻÿ�: ");
	scanf("%d %d", &a, &b);

	printf("%d�� %d�� �ִ������� %d \n", a, b, GCD(a, b));
}