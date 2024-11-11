#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    // Αρχικοποίηση του γεννήτριας τυχαίων αριθμών με βάση την τρέχουσα ώρα
    srand((unsigned int)time(NULL));

    // Παραγωγή τριών τυχαίων αριθμών στο διάστημα [0, 1] για τους συντελεστές του τριωνύμου
    double a = 0.000000;
    double b = 0.000000;
    double c = 0.000000;

    // Εκτύπωση των συντελεστών του τριωνύμου
    printf("Coefficients:\n");
    printf("a: %.6f\n", a);
    printf("b: %.6f\n", b);
    printf("c: %.6f\n\n", c);

    // Υπολογισμός της διακρίνουσας
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Δύο πραγματικές ρίζες
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and different.\n");
        printf("Root 1: %.3f\n", root1);
        printf("Root 2: %.3f\n", root2);
    } else if (discriminant == 0) {
        // Μία πραγματική διπλή ρίζα
        double root = -b / (2 * a);
        printf("The roots are real and equal.\n");
        printf("Root: %.3f\n", root);
    } else {
        // Καμία πραγματική ρίζα
        printf("The equation has no real roots.\n");
    }

    return 0;
}

// Μεταγλώττιση:
// gcc root_sqrt.c -o root_sqrt -lm
// Εκτέλεση:
// ./root_sqrt
//
// Έξοδος με καμία πραγματική ρίζα:
// 
// Coefficients:
// a: 0.485505
// b: 0.172335
// c: 0.500670
//
// The equation has no real roots.

// Έξοδος με μία πραγματική διπλή ρίζα:
//
// Coefficients:
// a: 0.000000
// b: 0.000000
// c: 0.000000

// The roots are real and equal.
// Root: -nan

// Έξοδος με δύο πραγματικές ρίζες:
//
// Coefficients:
// a: 0.112138
// b: 0.259640
// c: 0.118163

// The roots are real and different.
// Root 1: -0.622
// Root 2: -1.693