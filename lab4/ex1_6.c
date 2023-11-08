/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex1_6 ex1_6.c
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex1_6
*/

#include <stdio.h>

#include <limits.h>     /* μία ενδιαφέρουσα βιβλιοθήκη που περιέχει τις μέγιστες/ελάχιστες τιμές από κάθε τύπο δεδομένων πχ INT_MAX, LONG_MIN κτλπ */

int main()
{
    double sum = 0;

    for (int i = 1; i <= SHRT_MAX; i++) {
        double temp = 1 / ((double)i * (double)i);      /* Είναι (σχεδόν!) το ίδιο με 1.0 / (i * i) (καλύτερο όμως το αρχικό!) */

        if (i % 2 == 0)                                 /* 4 mod 2 == 0, 6 mod 2 == 0, ... */
                temp *= -1;

        sum += temp;                                    /* Είναι το ίδιο με sum = sum + temp */
    }

    printf("%f\n", sum);

    return 0;
}