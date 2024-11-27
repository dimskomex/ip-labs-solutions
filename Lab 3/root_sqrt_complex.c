#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Αρχικοποίηση του γεννήτριας τυχαίων αριθμών με βάση την τρέχουσα ώρα
  srand((unsigned int)time(NULL));

  // Παραγωγή τριών τυχαίων αριθμών στο διάστημα [0, 1] για τους συντελεστές του
  // τριωνύμου
  double a = (double)rand() / RAND_MAX;
  double b = (double)rand() / RAND_MAX;
  double c = (double)rand() / RAND_MAX;

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
    // Μιγαδικές ρίζες
    double real_part = -b / (2 * a);
    double imaginary_part = sqrt(-discriminant) / (2 * a);
    printf("The roots are complex and different.\n");
    printf("Root 1: %.3f + %.3fi\n", real_part, imaginary_part);
    printf("Root 2: %.3f - %.3fi\n", real_part, imaginary_part);
  }

  return 0;
}

// Μεταγλώττιση:
// gcc root_sqrt_complex.c -o root_sqrt_complex -lm
// Εκτέλεση:
// ./root_sqrt_complex

// Έξοδος με δύο πραγματικές ρίζες:
//
// Coefficients:
// a: 0.129880
// b: 0.968157
// c: 0.072090

// The roots are real and different.
// Root 1: -0.075
// Root 2: -7.379

// Έξοδος με μία πραγματική διπλή ρίζα:

// Coefficients:
// a: 0.000000
// b: 0.000000
// c: 0.000000

// The roots are real and equal.
// Root: -nan

// Έξοδος με μιγαδικές ρίζες:
//
// Coefficients:
// a: 0.282593
// b: 0.267229
// c: 0.687708

// The roots are complex and different.
// Root 1: -0.473 + 1.487i
// Root 2: -0.473 - 1.487i
