#include <stdio.h>

int SequentialSearch(int a[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int a[10] = { 1, 10, 34, 2, 7, 95, 100, 745, 3, 56 };

	printf("Best : %d, Avg : %d, Worst : %d, NA : %d\n", SequentialSearch(a, 10, 1), SequentialSearch(a, 10, 95), SequentialSearch(a, 10, 56), SequentialSearch(a, 10, 1004));
}