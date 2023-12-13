#include <stdio.h>
#include <stdlib.h>

// compile: gcc -o array array.c
// run: ./array < input.txt

int main(void)
{
    int size;
    scanf("%d", &size);

    int *p = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i)
        scanf("%d", &p[i]);

    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += p[i];

    double average = sum / ((double)size);
    printf("%f\n", average);

    free(p);
    return 0;
}