#include <stdio.h>

void rotateMatrixClockwise(int mat[][100], int rows, int cols, int steps) {
    steps = steps % 4; 

    for (int s = 0; s < steps; s++) {
        int temp = mat[0][0];
        
        for (int i = 0; i < cols - 1; i++) {
            mat[0][i] = mat[0][i + 1];
        }
        
        for (int i = 0; i < rows - 1; i++) {
            mat[i][cols - 1] = mat[i + 1][cols - 1];
        }
        
        for (int i = cols - 1; i > 0; i--) {
            mat[rows - 1][i] = mat[rows - 1][i - 1];
        }
        
        for (int i = rows - 1; i > 1; i--) {
            mat[i][0] = mat[i - 1][0];
        }
        
        mat[1][0] = temp;
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    int matrix[100][100];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int steps;
    printf("Enter the number of clockwise rotations: ");
    scanf("%d", &steps);

    rotateMatrixClockwise(matrix, rows, cols, steps);

    printf("Rotated matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}