#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define ROWS 4
#define COLS 4

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS];
    int skalar = 2;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = i * j;
        }
    }

    printf("Matriks Awal:\n");
    printMatrix(matrix);

    pid_t pid = fork();

    if (pid == 0) {
        printf("\nProses Anak - Matriks Hasil:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                matrix[i][j] *= skalar;
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else if (pid > 0) {
        wait(NULL);
        printf("\nProses Induk Selesai.\n");
    } else {
        fprintf(stderr, "Fork gagal.\n");
        return 1;
    }

    return 0;
}