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
  int n;

  // Ζητάμε από τον χρήστη να δώσει την τιμή του n
  printf("Please provide the value of n: ");
  if (scanf("%d", &n) != 1) {
    // Μήνυμα λάθους αν η είσοδος δεν είναι έγκυρος αριθμός
    printf("Error: Invalid input. Please enter a valid number.\n");
    return 1;
  }

  // Έλεγχος αν το n είναι αρνητικό
  if (n < 0) {
    printf("Error: Fibonacci sequence is not defined for negative numbers.\n");
    return 1;
  }

  // Υπολογισμός και εκτύπωση του n-οστού αριθμού της ακολουθίας Fibonacci
  int result = fib(n);
  printf("The %d-th Fibonacci number is %d\n", n, result);

  return 0;
}

// Μεταγλώττιση:
// gcc -o fib fib.c
// Εκτέλεση:
// ./fib
// Έξοδος:
// Please provide the value of n: 10
// The 10-th Fibonacci number is 55
