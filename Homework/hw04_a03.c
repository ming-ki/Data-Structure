#include <stdio.h>
#pragma warning(disable: 4996)

void strcpyArr(char src[], char dst[]) 
{
	int i;
	for (i = 0; src[i] != '\0'; i++)
	{
		dst[i] = src[i];
    }
	dst[i] = '\0';
}

void strcpyPtr(char *src, char *dst) 
{
	int j;
	for (j = 0; src[j] != '\0'; j++)
	{
		*(dst + j) = *(src + j); 
    }
	dst[j] = '\0';
}

int main() {
   char* src = "Welcome to IoT World!";
   char dst1[30], dst2[30];

   strcpyArr(src, dst1);
   strcpyPtr(src, dst2);

   printf("Src(%s) Dst1(%s) Dst2(%s)\n", src, dst1, dst2);
}