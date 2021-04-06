#include <stdio.h>
#include <math.h>

int main(void)
{
	int two[10]={ 0,0,0,0,0,0,0,0,0,0 };
	int j=0;
	for (int i = 0; i < 10; i++)
	{
		two[i] = pow(2,j);
		printf("%d\n", two[i]);
		j++;
	}
}