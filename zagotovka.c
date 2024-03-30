#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n;
    printf("Введите размерность матрицы n: ");
    scanf("%d", &n);

    double **matrix1 = (double **)malloc(n * sizeof(double *));
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    double **result;

    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < n; i++) {
        matrix2[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    char operation;
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            result = matrix_addition(matrix1, matrix2, n);
            break;
        case '-':
            result = matrix_subtraction(matrix1, matrix2, n);
            break;
        case '*':
            result = matrix_multiplication(matrix1, matrix2, n);
            break;
        default:
            printf("Неверная операция!\n");
            return 1;
    }

    printf("Результат операции:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    // Освобождаем выделенную память
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
```

**matrix_operations.c:**
```c
#include <stdlib.h>
#include "matrix_operations.h"

double **matrix_addition(double **matrix1, double **matrix2, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double **matrix_subtraction(double **matrix1, double **matrix2, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

double **matrix_multiplication(double **matrix1, double **matrix2, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}
```

**matrix_operations.h:**
```c
#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

double **matrix_addition(double **matrix1, double **matrix2, int n);
double **matrix_subtraction(double **matrix1, double **matrix2, int n);
double **matrix_multiplication(double **matrix1, double **matrix2, int n);

#endif
```

Эта программа включает три файла: `main.c`, `matrix_operations.c` и `matrix_operations.h`. Функции для операций с матрицами (сложение, вычитание, умножение) определены в `matrix_operations.c`, а сама программа, включая ввод данных и вывод результата, реализована в `main.c`.
