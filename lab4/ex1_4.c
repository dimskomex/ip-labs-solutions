/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex1_4 ex1_4.c -lm
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex1_4
*/

/*
    Σημαντική σημείωση:
    Στην C, το 1E20 σημαίνει 1 * 10 ^ 20, πιο γενικά: xEy == x * 10 ^ y.
    ΠΡΟΣΟΧΗ ΟΜΩΣ! Η σύνταξη αυτή δουλεύει μόνο για αριθμούς, όχι για μεταβλητές.
    Δηλαδή αν γράψουμε xEy όπου x & y μεταβλητές του προγράμματος μας, ο compiler θα γκρινιάζει.
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double sum = 0;
    int i = 1;
    double temp = 1.0;
    while (temp >= 1.0E-15) {
        temp = 1 / ((double)i * (double)i);     /* Είναι (σχεδόν!) το ίδιο με 1.0 / (i * i) (καλύτερο όμως το αρχικό!) */
        sum += temp;                            /* Είναι το ίδιο με sum = sum + temp */

        i++;
    }

    double pi = sqrt(6 * sum);
    printf("%f\n", pi);
}