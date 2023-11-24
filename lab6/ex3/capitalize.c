/*
    Κάνουμε compile με: gcc -o capitalize capitalize.c
    Τρέχουμε με ./capitalize < capitalize.c

    Παρατηρούμε ότι οποισδήποτε πεζός χαρακτήρας, γίνεται κεφαλαίος αν του αφαιρέσουμε το offset
    ascii(a) - ascii(A) θα πάρουμε τον ίδιο χαρακτήρα σε κεφαλαίο.
*/

#include <stdio.h>

int main(void)
{ 
    int ch;                             /* Be careful! Declare ch as int because of getchar() and EOF */
    ch = getchar();                     /* Read first character */
    while (ch != EOF) {                 /* Go on if we didn't reach end of file */
        if (ch >= 'a' && ch <= 'z')     /* If lower case letter */
            ch = ch - ('a'-'A');        /* Move 'a'-'A' positions in the ASCII table */
    
        putchar(ch);                    /* Print out character */
        ch = getchar();                 /* Read next character */
    }
}