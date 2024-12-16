#include <stdio.h>

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

int main() {
  int number;
  printf("Enter a positive integer: ");
  if (scanf("%d", &number) != 1) {
    printf("Error: Invalid input. Please enter a positive integer.\n");
    return 1;  // Επιστροφή λάθους σε περίπτωση μη έγκυρης εισόδου
  }
  int result = collatz_recursive(number);
  if (result != -1) {
    printf("The length of the Collatz sequence for %d is: %d\n", number,
           result);
  }
  return 0;
}

// Μεταγλώττιση:
// gcc collatz_recursive.c -o collatz_recursive
// Εκτέλεση:
// ./collatz_recursive
// Παράδειγμα:
// Enter a positive integer: 27
// The length of the Collatz sequence for 27 is: 112