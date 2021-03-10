#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumAlgorithmA(int n)
{
	int sum;
	sum = n*(n + 1) / 2;
	return sum;
}
int sumAlgorithmB(int n)
{
	int sum=0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}
int sumAlgorithmC(int n)
{
	int i, j = 0;
	int sum = 0;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			sum++;
		}
	}
	return sum;
}

int main()
{
	double timeA, timeB, timeC;
	clock_t start, finish;

	start = clock();
	sumAlgorithmA(100000000);
	finish = clock();
	timeA = ((double)(finish - start)) / CLOCKS_PER_SEC;

	start = clock();
	sumAlgorithmB(100000000);
	finish = clock();
	timeB = ((double)(finish - start)) / CLOCKS_PER_SEC;

	start = clock();
	sumAlgorithmC(100000);
	finish = clock();
	timeC = ((double)(finish - start)) / CLOCKS_PER_SEC;

	printf("Time_A : %lf, Time_B : %lf, Time_C : %lf\n", timeA, timeB, timeC);
}