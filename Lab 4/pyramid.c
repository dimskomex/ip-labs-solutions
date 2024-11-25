#include <stdio.h>

int main() {
  int rows;

  // Διαβάζουμε τον αριθμό των γραμμών από τον χρήστη
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  // Εκτύπωση πυραμίδας χρησιμοποιώντας αποκλειστικά την συνάρτηση putchar
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= i; j++) {
      putchar('*');  // Εκτυπώνει τον χαρακτήρα '*'
    }
    putchar('\n');
  }

  return 0;
}

// Μεταγλώττιση:
// gcc pyramid.c -o pyramid
// Εκτέλεση:
// ./pyramid
// Enter the number of rows: 5
// *
// **
// ***
// ****
// *****
