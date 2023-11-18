#include <stdio.h>

int fib(int n)
{
    int result;
    int prev;
    for (int i = 0; i <= n; ++i) {
        if (i == 0 || i == 1) {
            result = 1;
            prev = 1;
            continue;
        }

        int temp = result;
        result += prev;
        prev = temp;
    }

    return result;
}

int main(void)
{
    for (int i = 28; i <= 35; ++i)
        printf("Fibonacci for n = %d is: %d\n", i, fib(i));

    return 0;
}