#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
		free(removed);
		return head;
}ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* reverse(ListNode* head)
{
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
ListNode* search_list(ListNode* head, element x)
{
	ListNode* p = head;

	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->link;
	}
	return NULL;
}

int main()
{
	ListNode* head = NULL;
	ListNode* pre = NULL;
	ListNode* p = NULL;

	for (int i = 0; i < 10; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}

	head = delete_first(head);
	print_list(head);

	pre = head->link->link;
	head = delete(head, pre);
	print_list(head);

	pre = head;
	while (pre->link->link != NULL)
	{
		pre = pre->link;
	}
	head = delete(head, pre);
	print_list(head);

	p = search_list(head, 4);
	if (p != NULL)
	{
		printf("[%d] is found!\n", p->data);
	}
	else
	{
		printf("No data is found.");
	}
	p = search_list(head, 5);
	if (p != NULL)
	{
		printf("[%d] is found!\n", p->data);
	}
	else
	{
		printf("No data is found.");
	}
	head = reverse(head);
	print_list(head);
}