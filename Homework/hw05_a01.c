#include <stdio.h>

int list[100];
int length = 0;

void insert(int pos, int item)
{
	int i;
	if (length == 100 || pos <0 || pos > length)
	{
		printf("»ðÀÔ ¿¡·¯\n");
		return;
	}
	for (i = length; i > pos; i--)
	{
		list[i] = list[i - 1];
	}
	list[pos] = item;
	length++;
}
void print_list()
{
	printf("( ");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", list[i]);
	}
	printf(" )");
}

int main()
{
	insert(0, 10);
	insert(1, 20);
	insert(2, 30);
	insert(3, 40);
	insert(10, 50);
	print_list();
}