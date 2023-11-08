/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex3 ex3.c -lm
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex3
*/

#include <stdio.h>
#include <math.h>

/* 1 για μια μέρα δεν γεννήθηκα 29/2 :) */
#define DD 28
#define MM 2
#define YYYY 2004

int main()
{
    int NYYYY = YYYY;
    int NMM;

    if (MM <= 2) {
        NYYYY -= 1;
        NMM = 0;
    } else {
        NMM = floor((4 * MM + 23) / 10);
    }


    int IDAY = 365 * YYYY + DD + 31 * (MM - 1) - NMM + floor(NYYYY / 4.0) - floor((3.0 / 4.0) * (floor(NYYYY / 100.0) + 1));

    switch (IDAY % 7) {
    case 0:
        printf("SATURDAY");
        break;
    case 1:
        printf("SUNDAY");
        break;
    case 2:
        printf("MONDAY");
        break;
    case 3:
        printf("TUESDAY");
        break;
    case 4:
        printf("WEDNESDAY");
        break;
    case 5:
        printf("THURSDAY");
        break;
    case 6:
        printf("FRIDAY");
        break;
    }

    printf("\n");

    return 0;
}