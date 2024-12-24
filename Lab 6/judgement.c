#include <stdio.h>

// Συνάρτηση που επιστρέφει το μέγιστο στοιχείο ενός πίνακα
int max_array(int *array, int n) {
  int max = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// Συνάρτηση που επιστρέφει το ελάχιστο στοιχείο ενός πίνακα
int min_array(int *array, int n) {
  int min = array[0];
  for (int i = 1; i < n; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

// Συνάρτηση που επιστρέφει το άθροισμα των στοιχείων ενός πίνακα
int sum_array(int *array, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += array[i];
  }
  return sum;
}

int main() {
  int grades[10];

  // Ανάγνωση βαθμολογιών από το αρχείο εισόδου
  for (int i = 0; i < 10; i++) {
    if (scanf("%d", &grades[i]) != 1) {
      printf("Error: Invalid input.\n");
      return 1;
    }
  }

  // Υπολογισμός μέγιστου, ελάχιστου και αθροίσματος
  int max = max_array(grades, 10);
  int min = min_array(grades, 10);
  int sum = sum_array(grades, 10);

  // Υπολογισμός βαθμολογίας σύμφωνα με τον τύπο
  double average = (sum - max - min) / 8.0;

  // Εκτύπωση αποτελεσμάτων
  printf("Sum: %d\n", sum);
  printf("Min: %d\n", min);
  printf("Max: %d\n", max);
  printf("Average: %.2f\n", average);

  return 0;
}

// Μεταγλώττιση:
// gcc judgement.c -o judgement

// Εκτέλεση:
// ./judgement < grades.txt

// Έξοδος:
// Sum: 56
// Min: 2
// Max: 10
// Average: 5.50