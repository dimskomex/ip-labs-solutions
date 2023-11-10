#include <stdio.h>

#include "foo.h"    /* Δεν κάνουμε ΠΟΤΕ include .c files. Κακή πρακτική */

/*
    αν δοκιμάσουμε να κάνουμε παραδοσιακά gcc -o main main.c θα πάρουμε (πιθανώς) αυτό το error:
    
    /usr/bin/ld: /tmp/cc4AncMc.o: in function `main':
    main.c:(.text+0xe): undefined reference to `print_integer'
    collect2: error: ld returned 1 exit status

    αυτό συμβαίνει επειδή παρόλο που έχουμε κάνει include το foo.h αρχείο, δεν έχουμε δώσει καμία πληροφορία
    για την υλοποίηση της συνάρτησης print_integer.

    ο σωστός τρόπος είναι ο εξής:

    gcc -c main.c
    gcc -c foo.c

    keep in mind το εξής:
    το -c φτιάχνει ένα object file .o (παρατήρησε ότι τώρα φτιάχτηκαν δύο αρχεία, main.o & foo.o)
    το -o φτιάχνει εκτελέσιμο αρχέιο.

    Τώρα, θα φτιάξουμε το εκτελέσιμο γράφοντας:

    gcc -o executable_file main.o foo.o

    Αυτό που έγινε χοντρικά είναι το εξής:

    κάνοντας απλό compile (-c) δημιουργήσαμε δύο αρχεία τα οποία ενώσαμε σε ένα ενιαίο.

    Τώρα, τρέχουμε το πρόγραμμα κλασσικά γράφοντας στο terminal:
    ./executable_file
*/

int main(void) 
{
    /* καλούμε την print_integer με το όρισμα που θέλουμε */
    print_integer(10);
    printf("\n");

    /* εκτυπώνουμε και την σταθερά του .h αρχείου */
    printf("%d\n", VALUE);

    return 0;
}