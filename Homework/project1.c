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
		printf("포화상태 오류 또는 삽입 위치 오류\n");
}

void delete(int pos) {
	int i;
	if (is_empty() == 0 && pos >= 0 && pos <= length) {
		for (i = pos; i < length - 1; i++)
			iot_list[i] = iot_list[i + 1];
		length--;
	}
	else
		printf("공백상태 오류 또는 삭제 위치 오류\n");
}

Namecard get_entry(int pos) {
	if (pos >= 0 && pos < length)
		return iot_list[pos];
	else
		printf("반환 위치 오류\n");
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
		printf("교체 위치 오류\n");
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

	insert(0, make_Namecard("안민지", 20201509));
	insert(0, make_Namecard("이정빈", 20201503));
	insert(1, make_Namecard("한문섭", 20201504));
	insert(size(), make_Namecard("김민성", 20201496));
	insert(3, make_Namecard("김성웅", 20201506));
	insert(size(), make_Namecard("김길호", 20201494));
	insert(10, make_Namecard("양기석", 20201508));
	print_list("Insert");

	replace(size() - 1, make_Namecard("염준선", 20201493));
	replace(4, make_Namecard("한승우", 20201511));
	replace(20, make_Namecard("권호윤", 20201512));
	print_list("Replace");

	delete(3);
	delete(size() - 1);
	delete(0);
	delete(30);
	print_list("Delete");

	sort_list();
	print_list("Sort");
	printf("%s is found at %d\n", "한승우", find(make_Namecard("한승우", 20201511)));
	printf("%s is found at %d\n", "석준현", find(make_Namecard("석준현", 20201515)));
	printf("%s is found at %d\n", "한문섭", find(make_Namecard("한문섭", 20201234)));
}