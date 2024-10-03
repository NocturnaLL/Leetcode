#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);

// Function implementation
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        return false;
    }

    int m = matrixSize;
    int n = matrixColSize[0];
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Use pointer arithmetic to calculate the address of the mid value
        int* rowPtr = *(matrix + (mid / n));
        int midValue = *(rowPtr + (mid % n));

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    int m = 3;  // Number of rows
    int n = 4;  // Number of columns
    int target = 3;

    // Dynamically allocate the matrix
    int** matrix = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // Fill the matrix with values
    int values[3][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(matrix[i] + j) = values[i][j];  // Use pointer arithmetic
        }
    }

    // Create the column size array
    int matrixColSize[3] = {4, 4, 4};

    // Call the searchMatrix function
    bool found = searchMatrix(matrix, m, matrixColSize, target);

    // Print the result
    if (found) {
        printf("Target %d is in the matrix.\n", target);
    } else {
        printf("Target %d is not in the matrix.\n", target);
    }

    // Free the matrix memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
