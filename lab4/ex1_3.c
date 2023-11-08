/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex1_3 ex1_3.c -lm
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex1_3
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0;
    for (int i = 1; i <= 100; ++i) {
        double temp = 1 / ((double)i * (double)i);      /* Είναι (σχεδόν!) το ίδιο με 1.0 / (i * i) (καλύτερο όμως το αρχικό!) */
        sum += temp;                                    /* Είναι το ίδιο με sum = sum + temp */
    }
            
    double pi = sqrt(6 * sum);
    printf("%f\n", pi);

    return 0;
}
