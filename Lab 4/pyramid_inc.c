#include <stdio.h>

int main() {
  int rows, increment;

  // Διαβάζουμε τον αριθμό των γραμμών και το πλήθος των αστερίσκων ανά γραμμή
  // από τον χρήστη
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the increment of stars per row: ");
  scanf("%d", &increment);

  // Εκτύπωση της πυραμίδας με τον επιθυμητό αριθμό αστερίσκων ανά γραμμή
  for (int i = 1, stars = 1; i <= rows; i++, stars += increment) {
    for (int j = 0; j < stars; j++) {
      putchar('*');  // Εκτυπώνει τον χαρακτήρα '*'
    }
    putchar('\n');
  }

  return 0;
}

// Μεταγλώττιση:
// gcc pyramid_inc.c -o pyramid_inc
// Εκτέλεση:
// ./pyramid_inc
// Έξοδος:
// Enter the number of rows: 5
// Enter the increment of stars per row: 2
// *
// ***
// *****
// *******
// *********