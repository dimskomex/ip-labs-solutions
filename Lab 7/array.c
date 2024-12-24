#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για εκτύπωση των στοιχείων του πίνακα
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d\t", array[i]);
  }
  printf("\n");
}

int main() {
  int *array;  // Δείκτης για τον δυναμικό πίνακα
  int size;

  // Ανάγνωση του μεγέθους του πίνακα από την είσοδο
  if (scanf("%d", &size) != 1 || size <= 0) {
    printf("Error: Invalid size input.\n");
    return 1;
  }

  // Δέσμευση δυναμικής μνήμης
  array = (int *)malloc(size * sizeof(int));
  if (array == NULL) {
    printf("Error: Memory allocation failed.\n");
    return 1;
  }

  // Ανάγνωση των στοιχείων του πίνακα από την είσοδο
  for (int i = 0; i < size; i++) {
    if (scanf("%d", &array[i]) != 1) {
      printf("Error: Invalid array element input.\n");
      free(array);
      return 1;
    }
  }

  // Εκτύπωση του πίνακα
  printf("Array elements:\n");
  print_array(array, size);

  // Αποδέσμευση δυναμικής μνήμης
  free(array);

  return 0;
}

// Μεταγλώττιση:
// gcc array.c -o array
// Εκτέλεση:
// ./array < input.txt
// Έξοδος:
// Array elements:
// 10      20      30      40      50