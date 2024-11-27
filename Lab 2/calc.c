#include <stdio.h>

int main() {
  int num1, num2;

  // Ζητάμε τον πρώτο αριθμό
  printf("Please enter the first number: ");
  if (scanf("%d", &num1) != 1) {
    printf("Invalid input for the first number.\n");
    return 1;
  }

  // Ζητάμε τον δεύτερο αριθμό
  printf("Please enter the second number: ");
  if (scanf("%d", &num2) != 1) {
    printf("Invalid input for the second number.\n");
    return 1;
  }

  // Υπολογίζουμε και τυπώνουμε το άθροισμα
  printf("The sum of the two numbers is: %d\n", num1 + num2);

  return 0;  // Επιστρέφουμε επιτυχία
}

// Μεταγλώττιση:
// gcc calc.c -o calc
// Δοκιμές:
// ./calc
// Please enter the first number: 42
// Please enter the second number: 58
// The sum of the two numbers is: 100
// $ echo $?
// 0