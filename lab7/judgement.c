#include <stdio.h>
#include <limits.h>

int max_array(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (max < A[i])
            max = A[i];
    }

    return max;
}

int min_array(int *A, int n)
{
    int min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (min > A[i])
            min = A[i];
    }

    return min;
}

int sum_array(int *A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += A[i];

    return sum;
}

int main(void)
{
    int A[10];
    for (int i = 0; i < 10; ++i)
        scanf("%d", &A[i]);

    double grade = (sum_array(A, 10) - max_array(A, 10) - min_array(A, 10)) / 8.0;
    printf("%f\n", grade); 

    return 0;
}