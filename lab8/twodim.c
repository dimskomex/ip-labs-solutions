#include <stdio.h>

int main(void)
{
    int A[6][10];
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j)
            A[i][j] = i * (5 - i) + j * (9 - j);
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j)
            printf("%d\t", A[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 6; ++i)
            printf("%d\t", A[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 6; ++i) {
        for (int j = 9; j > -1; --j)
            printf("%d\t", A[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 10; ++j)
            printf("%d\t", A[i][j]);
    }

    printf("\n");

    return 0;
}