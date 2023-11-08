/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex1_5 ex1_5.c -lm
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex1_5
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0;
    int i = 1;
    double temp = 1.0;
    while (temp >= 1.0e-15) {
        temp = 1 / ((double)i * (double)i);     /* Είναι (σχεδόν!) το ίδιο με 1.0 / (i * i) (καλύτερο όμως το αρχικό!) */
        sum += temp;                            /* Είναι το ίδιο με sum = sum + temp */

        i++;
    }

    double pi = sqrt(6 * sum);
    printf("%0.8f\n", pi);

    return 0;
}