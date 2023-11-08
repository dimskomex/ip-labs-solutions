/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex1_1 ex1_1.c 
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex1_1
*/

#include <stdio.h>

int main()
{
    int sum = 0;

    int i = 1;                  /* Ξεκινάμε από το 1 */
    do {
        sum += i;               /* Είναι το ίδιο με sum = sum + i */
        i++;                    /* αυξάνουμε τον μετριτή ώστε να μην εκτελείτε η επανάληψη επ άπειρον */
    } while (i <= 100);

    printf("%d\n", sum);

    return 0;
}