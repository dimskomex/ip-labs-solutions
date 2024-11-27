#include <stdio.h>

void wallis(int terms) {
  double product = 1.0;

  for (int i = 1; i <= terms; i++) {
    // Υπολογισμός του τρέχοντα όρου (2.0 * i / (2 * i - 1)) * (2.0 * i / (2 * i
    // + 1))
    product *= (2.0 * i / (2 * i - 1)) * (2.0 * i / (2 * i + 1));
  }

  // Υπολογισμός της προσέγγισης του π
  double pi_approx = product * 2;

  // Εκτύπωση του αποτελέσματος με ακρίβεια 6 δεκαδικών ψηφίων
  printf("Approximate value of π using Wallis product with %d terms: %.6f\n",
         terms, pi_approx);
}

int main() {
  int terms;

  // Ζητάμε από τον χρήστη τον αριθμό των όρων
  printf("Enter the number of terms to use: ");
  scanf("%d", &terms);

  // Κλήση της συνάρτησης
  wallis(terms);

  return 0;
}

// Μεταγλώττιση:
// gcc seq_wallis.c -o seq_wallis
// Εκτέλεση:
// ./seq_wallis
// Έξοδος για 1-100:
// Approximate value of π using Wallis product with 100 terms: 3.133787
// Έξοδος για 1-1000:
// Approximate value of π using Wallis product with 1000 terms: 3.140808