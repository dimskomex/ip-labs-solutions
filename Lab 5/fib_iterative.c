#include <stdio.h>

// Συνάρτηση για τον υπολογισμό του n-οστού αριθμού της ακολουθίας Fibonacci με
// επαναληπτική μέθοδο
int fib_it(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  int prev1 = 0, prev2 = 1, current = 0;
  for (int i = 2; i <= n; i++) {
    current = prev1 + prev2;
    prev1 = prev2;
    prev2 = current;
  }
  return current;
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
    int result = fib_it(i);
    printf("fib(%d) = %d\n", i, result);
  }

  return 0;
}

// Μεταγλώττιση:
// gcc -o fib_iterative fib_iterative.c
// Εκτέλεση:
// ./fib_iterative
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
