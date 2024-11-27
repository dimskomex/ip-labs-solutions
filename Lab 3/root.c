#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Αρχικοποίηση του γεννήτριας τυχαίων αριθμών με βάση την τρέχουσα ώρα
  srand((unsigned int)time(NULL));

  // Παραγωγή τριών τυχαίων αριθμών στο διάστημα [0, 1]
  double a = (double)rand() / RAND_MAX;
  double b = (double)rand() / RAND_MAX;
  double c = (double)rand() / RAND_MAX;

  // Εκτύπωση των τριών τυχαίων αριθμών
  printf("Random number a: %.6f\n", a);
  printf("Random number b: %.6f\n", b);
  printf("Random number c: %.6f\n", c);

  return 0;
}

// Μεταγλώττιση:
// gcc root.c -o root -lm
// Εκτέλεση:
// ./root
// Έξοδος:
// Random number a: 0.714169
// Random number b: 0.711600
// Random number c: 0.023043
