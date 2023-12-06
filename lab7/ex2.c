#include <stdio.h>

#define N 50

/* 
    TODO: όπως βλέπεις, δεν αξιοποιούμε ολόκληρο τον πίνακα, χρησιμοποιούμε τα 48 στοιχεία του πίνακα
    δηλαδή όλους εκτός από τους A[0] και A[1]. Άλλαξε το N σε 48 και κάνε τις αντίστοιχες αλλαγές για να
    μην βγαίνεις εκτός ορίων πινάκων.
*/

int main(void)
{
    int A[N];
    for (int i = 2; i < N; ++i)
        A[i] = 1;

    for (int i = 2; i < N; ++i) {
        if (A[i] != 0) {
            for (int j = 2 * i; j < N; j += i)
                A[j] = 0;
        }
    }

    for (int i = 2; i < N; ++i) {
        if (A[i] == 1)
            printf("The %d is prime!\n", i);
    }

    return 0;
}