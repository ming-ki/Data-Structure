#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")
#pragma warning(disable:4996)

typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
DListNode* current; // ���� ������� �뷡�� ����Ű�� ������

DListNode* dinsert(DListNode* head, DListNode* pre, element value)
{
	DListNode* new_node = (DListNode*)malloc(sizeof(DListNode));
	strcpy(new_node->data, value);
	if (head == NULL) 
	{
		head = new_node;
		new_node->rlink = NULL;
		new_node->llink = NULL;
	}
	else if (pre == NULL) 
	{
		new_node->rlink = head;
		head = new_node;
		new_node->llink = NULL;
		new_node->rlink->llink = new_node;
	}

	else
	{
		new_node->rlink = pre->rlink;
		pre->rlink = new_node;
		new_node->llink = pre;
		if (new_node->rlink != NULL)
		{
			new_node->rlink->llink = new_node;
		}
		return head;
	}
}
DListNode* ddelete(DListNode* head, DListNode* removed) 
{ 
	if (head == NULL)
	{ 
		printf("ddelete()error  'n");
	}  
	else if(head == removed)
	{ 
		head = removed -> rlink;  
	if (removed -> rlink != NULL) 
		removed -> rlink -> llink = NULL;  
	free(removed); 
	} 
	else 
	{
		removed -> llink -> rlink = removed -> rlink; 
		if (removed -> rlink != NULL)
		{
			removed -> rlink -> llink = removed -> llink;
		}
		free(removed);
	} 
	return head; 
}
void print_dlist(DListNode* head) 
{
	DListNode* p;
	for (p = head; p != NULL; p = p->rlink) 
	{
		if (p == current)
			printf("<-| #%s# |->", p->data);
		else
			printf("<-| %s |->", p->data);
	}
	printf("\n");
}
int main() 
{
	DListNode* head = NULL;
	char filename[100];
	char ch;
	// ���� ���� ����Ʈ�� �뷡 ����
	head = dinsert(head, NULL, "The Next Right Thing");
	head = dinsert(head, NULL, "Show Yourself");
	head = dinsert(head, NULL, "Into The Unknown");
	head = dinsert(head, NULL, "All Is Found");
	// ù ��° �뷡�� ���
	current = head;
	print_dlist(head);
	strcpy(filename, current->data);
	strcat(filename, ".wav");
	PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC); // filename�� �ش��ϴ� �뷡�� ����ϴ� �Լ�
	do {
		printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
		ch = getch(); // 1���� ���ڸ� �Է� �޴� �Լ�. Enter�� �Է����� �ʾƵ� ��
		printf("\n\n\n");
		if (ch == '<') 
		{ 
			if (current->llink != NULL) 
			{ 
				current = current->llink;
				print_dlist(head);
				strcpy(filename, current->data);
				strcat(filename, ".wav");
				PlaySoundA(NULL, NULL, NULL); // ���� ��� ���� �뷡�� ����
				PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC); // �ش� �뷡 ���
			}
			else 
			{ 
				printf("ù ��° �뷡�Դϴ�.\n");
			}
		}
		else if (ch == '>') 
		{ 
			if (current->rlink != NULL) { // ������ ��尡 �����ϴ� ���, ���������� �̵� �� �ش� �뷡 ���
				current = current->rlink;
					print_dlist(head);
					strcpy(filename, current->data);
					strcat(filename, ".wav");
					PlaySoundA(NULL, NULL, NULL); // ���� ��� ���� �뷡�� ����
					PlaySoundA(filename, NULL, SND_FILENAME | SND_ASYNC); // �ش� �뷡 ���
			}
			else 
			{ // ������ ��尡 ���� ���, �޽��� ���
				printf("������ �뷡�Դϴ�.\n");
			}
	}
} while (ch != 'q'); // ��q���� �Է��ϴ� ���, ���α׷� ����
}
