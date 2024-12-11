#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για τον υπολογισμό των διαφορετικών τρόπων να ανέβεις τη σκάλα με
// memoization
unsigned long long calculate_ways(int steps, unsigned long long *memo) {
  // Αν ο αριθμός των βημάτων είναι 0, υπάρχει μόνο ένας τρόπος (να μην ανέβεις
  // καθόλου)
  if (steps == 0) return 1;
  // Αν ο αριθμός των βημάτων είναι αρνητικός, δεν υπάρχει τρόπος
  if (steps < 0) return 0;

  // Αν το αποτέλεσμα έχει ήδη υπολογιστεί, επιστρέφουμε την αποθηκευμένη τιμή
  if (memo[steps] != -1) return memo[steps];

  // Υπολογισμός τρόπων και αποθήκευση του αποτελέσματος
  memo[steps] = calculate_ways(steps - 1, memo) +
                calculate_ways(steps - 2, memo) +
                calculate_ways(steps - 3, memo);

  return memo[steps];
}

int main() {
  int steps;

  // Ζητάμε από τον χρήστη τον αριθμό των σκαλιών
  printf("Please provide the number of steps: ");
  if (scanf("%d", &steps) != 1) {
    // Μήνυμα λάθους αν η είσοδος δεν είναι έγκυρος αριθμός
    printf("Error: Invalid input. Please enter a valid number.\n");
    return 1;
  }

  // Έλεγχος αν ο αριθμός των σκαλιών είναι αρνητικός
  if (steps < 0) {
    printf("Error: Number of steps cannot be negative.\n");
    return 1;
  }

  // Δημιουργούμε έναν πίνακα για το memoization
  unsigned long long *memo = malloc((steps + 1) * sizeof(unsigned long long));
  if (!memo) {
    printf("Error: Memory allocation failed.\n");
    return 1;
  }

  // Αρχικοποιούμε όλες τις θέσεις του πίνακα σε -1
  for (int i = 0; i <= steps; i++) {
    memo[i] = -1;
  }

  // Υπολογισμός των διαφορετικών τρόπων
  unsigned long long ways = calculate_ways(steps, memo);

  // Εκτύπωση του αποτελέσματος
  printf("There are %llu different ways to climb the ladder\n", ways);

  // Αποδέσμευση της μνήμης
  free(memo);

  return 0;
}

// Μεταγλώττιση:
// gcc -o ladder ladder.c
// Εκτέλεση:
// ./ladder
// Έξοδος:
// Please provide the number of steps: 10
// There are 274 different ways to climb the ladder
