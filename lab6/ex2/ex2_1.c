#include <stdio.h>

#define N 6

int main(void)
{
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j)
            putchar('*');

        putchar('\n');
    }

    return 0;
}