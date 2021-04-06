#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

#define MAX_IOT_LIST_SIZE 45

typedef struct {
	char name[20];
	int id;
}Namecard;

Namecard iot_list[MAX_IOT_LIST_SIZE];
int length;

Namecard make_Namecard(char name[], int id) {
	Namecard newCard;

	strcpy(newCard.name, name);
	newCard.id = id;

	return newCard;
}

void init(void) {
	length = 0;
}

int is_empty(void) {
	if (length == 0)
		return 1;
	else
		return 0;
}

int is_full(void) {
	if (length == MAX_IOT_LIST_SIZE)
		return 1;
	else
		return 0;
}

void insert(int pos, Namecard item) {
	int i;
	if (is_full() == 0 && pos >= 0 && pos <= length) {
		for (i = length; i > pos; i--)
			iot_list[i] = iot_list[i - 1];
		iot_list[pos] = item;
		length++;
	}
	else
		printf("��ȭ���� ���� �Ǵ� ���� ��ġ ����\n");
}

void delete(int pos) {
	int i;
	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		for (i = pos; i < length - 1; i++)
			iot_list[i] = iot_list[i + 1];
		length--;
	}
	else
		printf("������� ���� �Ǵ� ���� ��ġ ����\n");
}

Namecard get_entry(int pos) {
	if (pos >= 0 && pos < length)
		return iot_list[pos];
	else
		printf("��ȯ ��ġ ����\n");
}

int find(Namecard item) {
	for (int i = 0; i < length; i++) {
		if (strcmp(iot_list[i].name, item.name) == 0)
		{
			if (iot_list[i].id == item.id)
				return i;
		}
	}
	return -1;
}

void replace(int pos, Namecard item) {
	if (pos >= 0 && pos < length)
		iot_list[pos] = item;
	else
		printf("��ü ��ġ ����\n");
}

int size(void) {
	return length;
}

void sort_list(void) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (iot_list[j].id > iot_list[j + 1].id) {
				Namecard temp;
				temp = iot_list[j];
				iot_list[j] = iot_list[j + 1];
				iot_list[j + 1] = temp;
			}
		}
	}
}

void print_list(char* msg) {
	for (int i = 0; msg[i] != '\0'; i++)
		printf("%c", msg[i]);
	printf(": ");

	for (int i = 0; i < length; i++)
		printf("(%s, %d) ", iot_list[i].name, iot_list[i].id);
	printf("\n\n");
}

int main() {
	init();
	print_list("Init");

	insert(0, make_Namecard("�ȹ���", 20201509));
	insert(0, make_Namecard("������", 20201503));
	insert(1, make_Namecard("�ѹ���", 20201504));
	insert(size(), make_Namecard("��μ�", 20201496));
	insert(3, make_Namecard("�輺��", 20201506));
	insert(size(), make_Namecard("���ȣ", 20201494));
	insert(10, make_Namecard("��⼮", 20201508));
	print_list("Insert");

	replace(size() - 1, make_Namecard("���ؼ�", 20201493));
	replace(4, make_Namecard("�ѽ¿�", 20201511));
	replace(20, make_Namecard("��ȣ��", 20201512));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	sort_list();
	print_list("Sort");
	printf("%s is found at %d\n", "�ѽ¿�", find(make_Namecard("�ѽ¿�", 20201511)));
	printf("%s is found at %d\n", "������", find(make_Namecard("������", 20201515)));
	printf("%s is found at %d\n", "�ѹ���", find(make_Namecard("�ѹ���", 20201234)));
}