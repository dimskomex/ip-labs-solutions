#include <stdio.h>

void leibniz(int terms) {
  double sum_total = 0.0;
  double current_term;

  for (int i = 1; i <= terms; i++) {
    // Υπολογισμός του τρέχοντα όρου (-1)^(i+1) / (2*i - 1)
    current_term = (i % 2 == 0 ? -1.0 : 1.0) / (2 * i - 1);
    sum_total += current_term;  // Προσθήκη του όρου στο άθροισμα
  }

  // Εκτύπωση του αποτελέσματος με ακρίβεια 6 δεκαδικών ψηφίων
  printf("Approximate value of pi/4 with %d terms: %.6f\n", terms, sum_total);
  printf("Approximate value of pi with %d terms: %.6f\n", terms, 4 * sum_total);
}

int main() {
  int terms;

  // Ζητάμε από τον χρήστη τον αριθμό των όρων
  printf("Enter the number of terms to use: ");
  scanf("%d", &terms);

  // Κλήση της συνάρτησης
  leibniz(terms);

  return 0;
}

// Μεταγλώττιση:
// gcc seq_leibniz.c -o seq_leibniz -lm
// Εκτέλεση:
// ./seq_leibniz
// Έξοδος για 1-100:
// Approximate value of pi/4 with 100 terms: 0.782898
// Approximate value of pi with 100 terms: 3.131593
// Έξοδος για 1-1000:
// Approximate value of pi/4 with 1000 terms: 0.785148
// Approximate value of pi with 1000 terms: 3.140593