#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int id;
	double grade;
}Student;

void strcpyPrt(char* src, char* dst) {
	for (; *dst++ = *src++;);
}

int main() {
	Student* A, * B;

	A = (Student*)malloc(sizeof(Student));

	B = (Student*)calloc(1, sizeof(Student));

	strcpyPrt("Kim", A->name);
	A->id = 20200123;
	A->grade = 4.3;

	strcpyPrt("Lee", B->name);
	B->id = 20200789;
	B->grade = 3.8;

	printf("Student A: %s, %d, %lf\n", A->name, A->id, A->grade);
	printf("Student B: %s, %d, %lf\n", B->name, B->id, B->grade);
}