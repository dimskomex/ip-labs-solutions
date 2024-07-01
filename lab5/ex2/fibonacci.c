#include <stdio.h>

int fib(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int a = 0; // F(0)
    int b = 1; // F(1)
    int result = 0;

    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main(void)
{
    for (int i = 28; i <= 35; ++i)
        printf("Fibonacci for n = %d is: %d\n", i, fib(i));

    return 0;
}