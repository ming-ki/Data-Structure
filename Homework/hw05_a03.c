#include<stdio.h> 

void printMatrix(int a[][5], int row, int col) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

}
int main() {
    int Mat[5][5] = { {0,0,0,2,0},{0,0,5,0,0},{4,0,0,0,0},{0,0,0,0,0},{0,0,0,0,1} };
    printMatrix(Mat, 5, 5);
}