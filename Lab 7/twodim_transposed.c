#include <stdio.h>

// Συνάρτηση για την αρχικοποίηση του πίνακα
void initialize_array(int rows, int cols, int array[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array[i][j] = 5 * (5 - i) + j * (9 - j);
    }
  }
}

// Συνάρτηση για την εκτύπωση του πίνακα
void print_array(int rows, int cols, int array[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }
}

// Συνάρτηση για την εκτύπωση του μεταθεμένου πίνακα
void print_transposed(int rows, int cols, int array[rows][cols]) {
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      printf("%d\t", array[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Δημιουργία και αρχικοποίηση πίνακα
  int rows = 3, cols = 5;
  int array[rows][cols];

  initialize_array(rows, cols, array);

  // Εκτύπωση του αρχικού πίνακα
  printf("Original array:\n");
  print_array(rows, cols, array);

  // Εκτύπωση του μεταθεμένου πίνακα
  printf("\nTransposed array:\n");
  print_transposed(rows, cols, array);

  return 0;
}

// Μεταγλώττιση:
// gcc twodim_transposed.c -o twodim_transposed
// Εκτέλεση:
// ./twodim_transposed
// Έξοδος:
// Original array:
// 25      33      39      43      45
// 20      28      34      38      40
// 15      23      29      33      35

// Transposed array:
// 25      20      15
// 33      28      23
// 39      34      29
// 43      38      33
// 45      40      35