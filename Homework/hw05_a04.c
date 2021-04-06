#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct {
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

void toSparseMatrix(int src[][5], SparseMatrix* dst, int row, int col) {
    dst->rows = row;
    dst->cols = col;
    dst->terms = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (src[i][j] != 0) {
                dst->data[dst->terms].row = i;
                dst->data[dst->terms].col = j;
                dst->data[dst->terms].value = src[i][j];
                dst->terms++;
            }
        }
    }


}

void printSparseMatrix(SparseMatrix S) {
    printf("Rows: %d, Cols: %d, Nums: %d\n", S.rows, S.cols, S.terms);
    for (int i = 0; i < S.terms; i++)
        printf("%d %d %d\n", S.data[i].row, S.data[i].col, S.data[i].value);
    printf("\n");
}

int main() {
    int Mat[5][5] = { {0,0,0,2,0},
                    {0,0,5,0,0},
                    {4,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,1} };

    SparseMatrix A;
    toSparseMatrix(Mat, &A, 5, 5);
    printSparseMatrix(A);
}