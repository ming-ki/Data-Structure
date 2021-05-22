#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s)
{
	return (s->top == -1);
}
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
int checkPalindrome(char str[])
{
	int i;
	StackType s;
	init_stack(&s);

	for (i = 0; str[i] != '\0'; i++)
	{
		push(&s, str[i]);
	}
	for (i = 0; !is_empty(&s); i++)
	{
		if (str[i] != pop(&s))
		{
			return 0;
		}
		else
			return 1;
	}
}

int main()
{
	char str[100];
	int ret;

	while (1)
	{
		printf("���ڿ��� �Է��ϼ���: ");
		scanf("%s", str);
		ret = checkPalindrome(str);
		if (ret == 1)
		{
			printf("ȸ���Դϴ�.\n\n");
		}
		else
		{
			printf("ȸ���� �ƴմϴ�.\n\n");
		}
	}
}