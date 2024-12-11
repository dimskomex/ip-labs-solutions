#include <stdio.h>

// Συνάρτηση για έλεγχο αν ο αριθμός είναι περιττός
int isodd(int n) { return n % 2; }

// Συνάρτηση για τον υπολογισμό του μήκους της ακολουθίας Collatz
int collatz_iterative(int n) {
  int length = 1;  // Αρχικοποίηση του μήκους με 1
  if (n <= 0) {
    printf("Error: Input must be a positive integer.\n");
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

int main() {
  int number;
  printf("Enter a positive integer: ");
  if (scanf("%d", &number) != 1) {
    printf("Error: Invalid input. Please enter a positive integer.\n");
    return 1;  // Επιστροφή λάθους σε περίπτωση μη έγκυρης εισόδου
  }
  int result = collatz_length(number);
  if (result != -1) {
    printf("The length of the Collatz sequence for %d is: %d\n", number,
           result);
  }
  return 0;
}

// Μεταγλώττιση:
// gcc collatz_iterative.c -o collatz_iterative
// Εκτέλεση:
// ./collatz_iterative
// Παράδειγμα:
// Enter a positive integer: 10
// The length of the Collatz sequence for 10 is: 7