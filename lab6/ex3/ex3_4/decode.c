/*
    Για το τελευταίο ερώτημα, θα πρέπει να γνωρίζεις τι σημαίνει για το command line
    η εντολή: |
    Αυτή η εντολή, σημαίνει είσοδος σε ένα άλλο πρόγραμμα.
    Άρα, θα πρέπει το αποτέλεσμα της ./encode < text να είναι είσοδος στο ./decode.
    Τελικά, η εντολή είναι η εξής: ./encode < text | ./decode
*/

#include <stdio.h>

int main(void)
{ 
    int ch;                             /* Be careful! Declare ch as int because of getchar() and EOF */
    ch = getchar();                     /* Read first character */
    while (ch != EOF) {                 /* Go on if we didn't reach end of file */
        if (ch >= 'a' && ch <= 'z')     /* If lower case letter */
            ch--;

        putchar(ch);                    /* Print out character */
        ch = getchar();                 /* Read next character */
    }
}