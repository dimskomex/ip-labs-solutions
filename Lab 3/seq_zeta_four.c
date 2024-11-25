#include <math.h>  // Απαιτείται για την έκφραση i^4
#include <stdio.h>

void zeta_four(int terms) {
  double sum_total = 0.0;
  double current_term;

  for (int i = 1; i <= terms; i++) {
    // Υπολογισμός του τρέχοντα όρου 1 / (i^4)
    current_term = 1.0 / pow(i, 4);
    sum_total += current_term;  // Προσθήκη του όρου στο άθροισμα
  }

  // Εκτύπωση του αποτελέσματος με ακρίβεια 6 δεκαδικών ψηφίων
  printf("Approximate value of ζ(4) with %d terms: %.6f\n", terms, sum_total);
}

int main() {
  int terms;

  // Ζητάμε από τον χρήστη τον αριθμό των όρων
  printf("Enter the number of terms to use: ");
  scanf("%d", &terms);

  // Κλήση της συνάρτησης
  zeta_four(terms);

  return 0;
}

// Μεταγλώττιση:
// gcc seq_zeta_four.c -o seq_zeta_four -lm
// Εκτέλεση:
// ./seq_zeta_four
// Έξοδος για 1-100:
// Approximate value of ζ(4) with 100 terms: 1.082323
// Έξοδος για 1-1000:
// Approximate value of ζ(4) with 1000 terms: 1.082323