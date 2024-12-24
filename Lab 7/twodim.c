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

int main() {
  // Δημιουργία και αρχικοποίηση πίνακα
  int rows = 3, cols = 5;
  int array[rows][cols];

  initialize_array(rows, cols, array);

  // Εκτύπωση του αρχικού πίνακα
  printf("Original array:\n");
  print_array(rows, cols, array);

  return 0;
}

// Μεταγλώττιση:
// gcc twodim.c -o twodim
// Εκτέλεση:
// ./twodim
// Έξοδος:
// Original array:
// 25      33      39      43      45
// 20      28      34      38      40
// 15      23      29      33      35