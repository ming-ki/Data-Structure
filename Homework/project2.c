#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct name_card {
    char name[20];
    int id;
    struct name_card* link;
} Namecard;

Namecard* head = NULL;

Namecard* getNode(int pos) {
    Namecard* p;
    p = head;
    for (int i = 0; i < pos; i++) 
    {
        if (p == NULL)
            return NULL;
        p = p->link;
    }
    return p;
}

Namecard make_Namecard(char name[], int id) {
    Namecard newCard;
    strcpy(newCard.name, name);
    newCard.id = id;
    newCard.link = NULL;
    return newCard;
}

void init() {
    Namecard* p, * removed;
    for (p = head; p != NULL;) 
    {
        removed = p;
        p = p->link;
        free(removed);
    }
    head = NULL;
}

int is_emty(void) {
    if (head == NULL)
        return 1;
    else
        return 0;
}

void insert(int pos, Namecard item) {
    Namecard* new = (Namecard*)malloc(sizeof(Namecard));
    new->id = item.id;
    strcpy(new->name, item.name);
    if (pos == 0) 
    {
        new->link = head;
        head = new;
    }
    else 
    {
        Namecard* pre = getNode(pos - 1);
        if (pre == NULL) 
        {
            printf("삽입 위치 오류\n");
            return;
        }
        new->link = pre->link;
        pre->link = new;
    }
}

void delete(int pos) {
    Namecard* removed = getNode(pos);
    if (removed == NULL) 
    {
        printf("삭제 위치 오류\n");
        return;
    }
    if (pos == 0) 
    {
        if (head == NULL)
            printf("공백상태 오류\n");
        removed = head;
        head = removed->link;
        free(removed);
    }
    else {
        Namecard* pre = getNode(pos - 1);
        if (pre == NULL) 
        {
            printf("공백상태 오류\n");
            return;
        }
        removed = pre->link;
        pre->link = removed->link;
        free(removed);
    }
}

Namecard get_entry(int pos) {
    Namecard* p = getNode(pos);
    if (p == NULL) 
    {
        printf("공백상태 오류\n");
        return;
    }
    Namecard opt;
    opt.id = p->id;
    strcpy(opt.name, p->name);
    opt.link = NULL;
    return opt;
}

int find(Namecard item) {
    Namecard* p = head;
    int i = 0;
    while (p != NULL) 
    {
        if (strcmp(p->name, item.name) == 0 && p->id == item.id) 
        {
            return i;
        }
        p = p->link;
        i++;
    }
    return -1;
}

void replace(int pos, Namecard item) {
    Namecard* p = getNode(pos);
    if (p == NULL) 
    {
        printf("교체 위치 오류\n");
        return;
    }
    p->id = item.id;
    strcpy(p->name, item.name);
}

int size(void) {
    Namecard* p = head;
    int i = 0;
    while (p != NULL) 
    {
        i++;
        p = p->link;
    }
    return i;
}

void print_list(char* msg) {
    printf("%s : ", msg);
    Namecard* p = head;
    while (p != NULL) 
    {
        printf("(%s, %d) ", p->name, p->id);
        p = p->link;
    }
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

    printf("%s is found at %d\n", "한승우", find(make_Namecard("한승우", 20201511)));
    printf("%s is found at %d\n", "석준현", find(make_Namecard("석준현", 20201515)));
    printf("%s is found at %d\n", "한문섭", find(make_Namecard("한문섭", 20201234)));

    Namecard temp = get_entry(1);
    printf("\nEntry 1 : (%s, %d)\n", temp.name, temp.id);
}