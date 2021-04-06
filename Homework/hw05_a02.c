#include <stdio.h>

int list[100];
int length = 0;

void insert(int pos, int item) {
    int i;
    if (length == 100 || pos < 0 || pos > length) {
        printf("삽입 에러\n");
        return;
    }
    for (i = length; i > pos; i--)
        list[i] = list[i - 1];
    list[pos] = item;
    length++;
}

void print_list() {
    printf("( ");
    for (int i = 0; i < length; i++)
        printf("%d ", list[i]);
    printf(")\n");
}

void delete(int pos) {
    int i;
    if (length == 0 || pos < 0 || pos >= length) {
        printf("삭제에러\n");
        return;
    }
    for (i = pos; i < length - 1; i++)
        list[i] = list[i + 1];
    length--;
}

int main() {
    insert(0, 10);
    insert(0, 20);
    insert(1, 30);
    insert(2, 40);
    insert(10, 50);
    print_list();

    delete(3);
    delete(0);
    delete(length);
    print_list();
}