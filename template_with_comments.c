/*
    Κάνουμε απλό compile γράφοντας: gcc -o template template.c
    Βέβαια, ένας πιο κομψός τρόπος να κάνουμε compile είναι ο εξής: gcc -Wall -Wextra -Werror -o template_with_comments template_with_comments.c
    τα Wall & Wextra εμφανίζουν κάποια επιπρόσθετα warnings
    το Werror μετατρέπει τα warnings σε errors
*/

#include <stdio.h>      // συναρτήσεις εισόδου-εξόδου
#include <stdlib.h>     // χρήσιμες συναρτήσεις όπως atoi, malloc, free, rand κτλπ
#include <math.h>       // μαθηματικές συναρτήσεις (δεν ξεχνάμε να κάνουμε compile με -lm)
#include <string.h>     // χρήσιμες συναρτήσεις για συμβολοσειρές όπως strlen, strcpy, strcmp κτλπ
#include <limits.h>     // σταθερές που περιέχουν τα μέγιστα / ελάχιστα των κλασσικών τύπων δεδομένων (int, float, char κτλπ)
#include <time.h>

// δηλώσεις ή υλοποιήσεις συναρτήσεων

int main(void)          // αν θέλουμε να τρέξουμε το πρόγραμμα μας με ορίσματα, γράφουμε int main(int argc, char **argv) 
{
    return 0;
}