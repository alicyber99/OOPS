#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    return matrix;
}
void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];
}
void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}
void deallocateMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;
    int** matrix1 = allocateMatrix(rows, cols);
    int** matrix2 = allocateMatrix(rows, cols);
    int** sum = allocateMatrix(rows, cols);
    int** diff = allocateMatrix(rows, cols);
    cout << "Matrix 1:\n";
    inputMatrix(matrix1, rows, cols);
    cout << "Matrix 2:\n";
    inputMatrix(matrix2, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            diff[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    cout << "Sum of matrices:\n";
    displayMatrix(sum, rows, cols);
    cout << "Difference of matrices:\n";
    displayMatrix(diff, rows, cols);
    deallocateMatrix(matrix1, rows);
    deallocateMatrix(matrix2, rows);
    deallocateMatrix(sum, rows);
    deallocateMatrix(diff, rows);
    return 0;
}
