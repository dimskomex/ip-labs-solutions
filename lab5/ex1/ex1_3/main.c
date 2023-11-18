/*
    Στον φάκελο mult_files υπάρχει ένα απλό παράδειγμα στο οποίο
    φτιάχνουμε ένα εκτελέσιμο πρόγραμμα χρησιμοποιόντας πολλά αρχεία.
    Προσπάθησε με βάση αυτό να φτιάξεις το εκτελέσιμο και εδώ!
*/

#include <stdio.h>
#include "isodd.h"
#include "getinteger.h"

int main(void)
{
    int n = getinteger(10);     // βάζουμε αυτό το όρισμα γιατί θέλουμε ο αριθμός να είναι στο δεκαδικό σύστημα αρίθμησης.
    
    if (isodd(n))
        printf("%d is odd!\n", n);
    else
        printf("%d is even!\n", n);

    return 0;
}