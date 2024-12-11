#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για έλεγχο αν ο αριθμός είναι περιττός
int isodd(int n) { return n % 2; }

// Αναδρομική συνάρτηση για τον υπολογισμό του μήκους της ακολουθίας Collatz
int collatz_recursive(int n) {
  if (n <= 0) {
    printf("Error: Input must be a positive integer.\n");
    return -1;  // Επιστροφή λάθους σε περίπτωση μη θετικού αριθμού
  }
  if (n == 1) {
    return 1;  // Τέλος της ακολουθίας όταν ο αριθμός είναι 1
  } else if (isodd(n)) {
    return 1 + collatz_recursive(3 * n + 1);  // Αναδρομή για περιττούς αριθμούς
  } else {
    return 1 + collatz_recursive(n / 2);  // Αναδρομή για άρτιους αριθμούς
  }
}

// Επαναληπτική συνάρτηση για τον υπολογισμό του μήκους της ακολουθίας Collatz
int collatz_iterative(int n) {
  int length = 1;  // Αρχικοποίηση του μήκους με 1
  if (n <= 0) {
    prinft("Error: Input must be a positive integer.\n");
    return -1;  // Επιστροφή λάθους σε περίπτωση μη θετικού αριθμού
  }
  while (n != 1) {
    if (isodd(n)) {
      n = 3 * n + 1;  // Εφαρμογή του κανόνα αν ο αριθμός είναι περιττός
    } else {
      n = n / 2;  // Εφαρμογή του κανόνα αν ο αριθμός είναι άρτιος
    }
    length++;  // Αύξηση του μήκους της ακολουθίας
  }
  return length;  // Επιστροφή του συνολικού μήκους της ακολουθίας
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <positive integer>\n", argv[0]);
    return 1;  // Επιστροφή λάθους σε περίπτωση μη έγκυρης εισόδου
  }

  int number = atoi(argv[1]);
  if (number <= 0) {
    printf("Error: Input must be a positive integer.\n");
    return 1;  // Επιστροφή λάθους σε περίπτωση μη θετικού αριθμού
  }

  int recursive_result = collatz_recursive(number);
  int iterative_result = collatz_iterative(number);

  if (recursive_result != -1 && iterative_result != -1) {
    printf("Iterative result: %d\n", iterative_result);
    printf("Recursive result: %d\n", recursive_result);

    // Έλεγχος αν τα αποτελέσματα συμφωνούν
    if (recursive_result != iterative_result) {
      printf("Error: Results do not match. Something went wrong.\n");
    }
  }

  return 0;
}

// Μεταγλώττιση:
// gcc collatz_argument.c -o collatz_argument
// Εκτέλεση:
// ./collatz_argument <positive integer>
// Παράδειγμα:
// ./collatz_argument 27
// Iterative result: 112
// Recursive result: 112
