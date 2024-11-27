#include <stdio.h>

void sum_series() {
  // Αρχικοποίηση του αθροίσματος και του μετρητή
  int sum_total = 0;
  int i = 1;

  // Χρήση της επανάληψης while για τον υπολογισμό του αθροίσματος
  while (i <= 100) {
    sum_total += i;
    i++;
  }

  // Εκτύπωση του αποτελέσματος
  printf("Sum of the series: %d\n", sum_total);
}

int main() {
  // Κλήση της συνάρτησης
  sum_series();
  return 0;
}

// Μεταγλώττιση:
// gcc seq_sum.c -o seq_sum
// Εκτέλεση:
// ./seq_sum
// Έξοδος:
// Sum of the series: 5050