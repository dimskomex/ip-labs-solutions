#include <stdio.h>

int main(void)
{
    for (int i = 33; i <= 105; ++i) {
        if (i % 3 == 0) {
            putchar(i);
            printf(" ascii code: %d\n", i);
        }
    }
    return 0;
}