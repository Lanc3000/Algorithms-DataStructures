/*
 * task_01.c
 * 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define maxHeight 25
#define maxWidth 25
int matrix[maxHeight][maxWidth];

void solution01(){

    int h;
    int w;
    FILE *file;

    file = fopen("../database/matrix.csv", "r");
    if (file == NULL)
        return 1;

    readMatrixSize(file, &w, &h);
    if (h != w) {
        printf("Матрица должна быть квадратной.");
        return 1;
    }
    printf("Глубина = %d Ширина = %d\n\n", h, w);
    rewind(file);
    readMatrix(file);
    fclose(file);

    printMatrix(w);
}

void readMatrixSize(FILE *f, int *width, int *height) {
    int lines = 0;
    int commas = 0;
    int max = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%c", &c);
        if (c == ',')
            commas++;

        if (c == '\n') {
            lines++;
            if (commas > max)
                max = commas;
            commas = 0;
        }
    }
    *height = lines + 1;
    *width = max + 1;
}
void readMatrix(FILE *f) {
    int i = 0, j = 0;
    while (!feof(f)) {
        char c;
        fscanf(f, "%d%c", &matrix[i][j], &c);
        j++;
        if (c == '\n' || c == '\r') {
            j = 0;
            i++;
        }
    }
}
void printMatrix(int size) {
    int i, j;
    for (i = -1; i < size; i++) {
        for (j = -1; j < size; j++)
            (j < 0) ? printf("%c ", (i < 0) ? ' ' : 65 + i)
                    : (i < 0) ? printf("%c ", 65 + j) : printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
