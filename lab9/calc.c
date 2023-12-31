#include <stdio.h>
#include <stdlib.h>

// Η προσοχή σε αυτήν την άσκηση είναι στην πράξη του πολλαπλασιασμού.
// Το * στο unix έχει μια ιδιαίτερη σημασία για τα αρχεία.
// Αν πχ σε έναν φάκελο με πολλά αρχεία .h και .c γράψετε ls *.c θα σας εμφανίσει
// όλα τα αρχεία που τελειώνουν σε .c.
// Συνεπώς, πρέπει να δείξουμε στην γραμμή εντολών ότι θέλουμε να το περάσουμε σαν όρισμα.
// Αυτό γίνεται με δύο τρόπους:

// τρόπος Α:
// ./calc 10 \* 20

// τρόπος Β:
// ./calc 10 '*' 20

float calc(int a, char b, int c)
{
    return b == '+' ? a + c : b == '-' ? a - c : b == '*' ? a * c : ((float)a) / ((float)c);
}

int main(int argc, const char **argv)
{
    printf("%f\n", calc(atoi(argv[1]), *argv[2], atoi(argv[3])));
    return 0;
}
