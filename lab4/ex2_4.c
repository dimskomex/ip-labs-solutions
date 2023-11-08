/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex2_4 ex2_4.c
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex2_4
*/

/*
    Θα κάνουμε ελάχιστες αλλαγές, ουσιαστικά θα προσθέσουμε μια printf στην αρχή της συνάρτησης collatz
*/

#include <stdio.h>

#include <stdint.h>

uint64_t collatz(uint64_t n)
{
    printf("%ld ", n);
    /* base case, ξέρουμε ότι όταν το n είναι 1 επιστρέφουμε 1 */
    if (n == 1)
        return 1;

    /* Βήμα, πρέπει να καλέσουμε αναδρομικά την collatz με το κατάλληλο n */
    if (n % 2 == 0)
        n /= 2;
    else
        n = 3 * n + 1;

    return collatz(n) + 1;
}

int main()
{
    printf("\nThe number of terms of the collatz sequence is: %ld\n", collatz(22));
    return 0;
}