/*
 * Question 6: Represent a sparse matrix using arrays
 *
 * Only the non-zero elements are stored, in a triplet (3-column) array:
 *   row 0      : [rows, columns, number of non-zero elements]
 *   rows 1..n  : [row index, column index, value]
 */
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_TERMS (MAX_ROWS * MAX_COLS + 1)

int main(void) {
    int matrix[MAX_ROWS][MAX_COLS];
    int sparse[MAX_TERMS][3];
    int rows, cols;

    printf("Enter number of rows and columns (max %d x %d): ", MAX_ROWS, MAX_COLS);
    if (scanf("%d %d", &rows, &cols) != 2 ||
        rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter the %d elements row by row:\n", rows * cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input.\n");
                return 1;
            }

    /* Build the triplet representation */
    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;

    printf("\nOriginal matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%4d", matrix[i][j]);
        printf("\n");
    }

    printf("\nSparse representation (Row Col Value):\n");
    for (int i = 0; i < k; i++)
        printf("%4d %4d %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);

    int total = rows * cols;
    printf("\nStored %d values instead of %d.\n", k * 3, total);
    return 0;
}
