#include <stdio.h>

// Παγκόσμια μεταβλητή για την καταμέτρηση των αναδρομικών κλήσεων
int recursive_calls = 0;

// Συνάρτηση για τον υπολογισμό του n-οστού αριθμού της ακολουθίας Fibonacci
int fib(int n) {
  // Αύξηση του μετρητή αναδρομικών κλήσεων
  recursive_calls++;

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

  // Εκτύπωση των όρων της ακολουθίας Fibonacci και του αριθμού των αναδρομικών
  // κλήσεων
  for (int i = 0; i < terms; i++) {
    recursive_calls = 0;  // Επαναφορά του μετρητή αναδρομικών κλήσεων
    int result = fib(i);
    printf("fib(%d) = %d (Recursive calls: %d)\n", i, result, recursive_calls);
  }

  return 0;
}

// Μεταγλώττιση:
// gcc -o fib_recursive fib_recursive.c
// Εκτέλεση:
// ./fib_recursive
// Έξοδος:
// How many Fibonacci terms would you like: 10
// fib(0) = 0 (Recursive calls: 1)
// fib(1) = 1 (Recursive calls: 1)
// fib(2) = 1 (Recursive calls: 3)
// fib(3) = 2 (Recursive calls: 5)
// fib(4) = 3 (Recursive calls: 9)
// fib(5) = 5 (Recursive calls: 15)
// fib(6) = 8 (Recursive calls: 25)
// fib(7) = 13 (Recursive calls: 41)
// fib(8) = 21 (Recursive calls: 67)
// fib(9) = 34 (Recursive calls: 109)
