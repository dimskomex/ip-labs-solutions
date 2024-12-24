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

// Συνάρτηση για υπολογισμό γειτονικών ναρκών
void calculate_mines(char **matrix, int rows, int cols) {
  int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

  char **result = allocate_matrix(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == '*') {
        result[i][j] = '*';  // Αν υπάρχει νάρκη, μένει νάρκη
      } else {
        int mine_count = 0;
        for (int d = 0; d < 8; d++) {
          int ni = i + directions[d][0];
          int nj = j + directions[d][1];
          if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
              matrix[ni][nj] == '*') {
            mine_count++;
          }
        }
        result[i][j] = '0' + mine_count;  // Μετατροπή αριθμού σε χαρακτήρα
      }
    }
  }

  // Εκτύπωση του τροποποιημένου πίνακα
  printf("Minefield:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", result[i][j]);
    }
    printf("\n");
  }

  free_matrix(result, rows);  // Αποδέσμευση του προσωρινού πίνακα
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

  // Υπολογισμός και εκτύπωση του τροποποιημένου πίνακα
  calculate_mines(matrix, rows, cols);

  // Αποδέσμευση μνήμης
  free_matrix(matrix, rows);

  return 0;
}

// Μεταγλώττιση:
// gcc mines_detector.c -o mines_detector
// Εκτέλεση:
// ./mines_detector < minefield1.txt
// Έξοδος:
// Minefield:
// 3 * 2 0
// * * 3 1
// 2 3 * 1