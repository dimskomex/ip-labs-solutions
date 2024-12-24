#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για δέσμευση μνήμης για διδιάστατο πίνακα
char **allocate_matrix(int rows, int cols) {
  char **matrix = malloc(rows * sizeof(char *));
  if (matrix == NULL) {
    printf("Error: Failed to allocate rows.\n");
    exit(1);
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(char));
    if (matrix[i] == NULL) {
      printf("Error: Failed to allocate column %d.\n", i);
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      free(matrix);
      exit(1);
    }
  }
  return matrix;
}

// Συνάρτηση για αποδέσμευση μνήμης διδιάστατου πίνακα
void free_matrix(char **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

// Συνάρτηση για εκτύπωση του πίνακα
void print_matrix(char **matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int rows, cols;

  // Ανάγνωση διαστάσεων του πίνακα από την τυπική είσοδο
  if (scanf("%d %d", &rows, &cols) != 2) {
    printf("Error: Invalid input format for dimensions.\n");
    return 1;
  }

  // Δέσμευση μνήμης για τον πίνακα
  char **matrix = allocate_matrix(rows, cols);

  // Ανάγνωση δεδομένων του πίνακα από την τυπική είσοδο
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scanf(" %c", &matrix[i][j]) != 1) {
        printf("Error: Invalid input for matrix data.\n");
        free_matrix(matrix, rows);
        return 1;
      }
    }
  }

  // Εκτύπωση του πίνακα
  printf("Minefield:\n");
  print_matrix(matrix, rows, cols);

  // Αποδέσμευση μνήμης
  free_matrix(matrix, rows);

  return 0;
}

// Μεταγλώττιση:
// gcc mines.c -o mines
// Εκτέλεση:
// ./mines < minefield1.txt
// Έξοδος:
// Minefield:
// . * . .
// * * . .
// . . * .