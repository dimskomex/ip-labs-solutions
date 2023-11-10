/* Καλό είναι να κάνουμε και στο .c αρχείο το αντίστοιχο .h που περιέχει την διεπαφή του */
#include "foo.h"
#include <stdio.h>

void print_integer(int integer)
{
    printf("%d", integer);
}