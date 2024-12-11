#include <stdio.h>

// Συνάρτηση για τον υπολογισμό του n-οστού αριθμού της ακολουθίας Fibonacci
int fib(int n) {
  // Αν n είναι 0, επιστρέφουμε 0
  if (n == 0) {
    return 0;
  }
  // Αν n είναι 1, επιστρέφουμε 1
  if (n == 1) {
    return 1;
  }
  // Αναδρομικός υπολογισμός της ακολουθίας Fibonacci
  return fib(n - 1) + fib(n - 2);
}

int main() {
  int terms;

  // Ζητάμε από τον χρήστη να δώσει τον αριθμό των όρων που θέλει να εκτυπωθούν
  printf("How many Fibonacci terms would you like: ");
  if (scanf("%d", &terms) != 1) {
    // Μήνυμα λάθους αν η είσοδος δεν είναι έγκυρος αριθμός
    printf("Error: Invalid input. Please enter a valid number.\n");
    return 1;
  }

  // Έλεγχος αν ο αριθμός των όρων είναι αρνητικός
  if (terms < 0) {
    printf("Error: Number of terms cannot be negative.\n");
    return 1;
  }

  // Εκτύπωση των όρων της ακολουθίας Fibonacci
  for (int i = 0; i < terms; i++) {
    printf("fib(%d) = %d\n", i, fib(i));
  }

  return 0;
}

// Μεταγλώττιση:
// gcc -o fib_terms fib_terms.c
// Εκτέλεση:
// ./fib_terms
// Έξοδος:
// How many Fibonacci terms would you like: 10
// fib(0) = 0
// fib(1) = 1
// fib(2) = 1
// fib(3) = 2
// fib(4) = 3
// fib(5) = 5
// fib(6) = 8
// fib(7) = 13
// fib(8) = 21
// fib(9) = 34
