#include <stdio.h>

int main() {
  long long int num1, num2;
  char operation;

  // Ζητάμε τον πρώτο αριθμό
  printf("Please enter the first number: ");
  if (scanf("%lld", &num1) != 1) {
    printf("Error: Invalid input for the first number.\n");
    return 1;
  }

  // Ζητάμε τον δεύτερο αριθμό
  printf("Please enter the second number: ");
  if (scanf("%lld", &num2) != 1) {
    printf("Error: Invalid input for the second number.\n");
    return 1;
  }

  // Ζητάμε την πράξη που θέλει ο χρήστης
  printf("Please enter the operation (+ for addition, - for subtraction): ");
  scanf(" %c",
        &operation);  // To κενό διάστημα πριν το %c αγνοεί το newline χαρακτήρα

  // Υπολογισμός ανάλογα με την πράξη
  if (operation == '+') {
    printf("The result of the addition is: %lld\n", num1 + num2);
  } else if (operation == '-') {
    printf("The result of the subtraction is: %lld\n", num1 - num2);
  } else {
    printf("Error: Invalid operation. Please enter + or -.\n");
    return 1;
  }

  return 0;  // Επιστροφή επιτυχίας
}

// Μεταγλώττιση:
// gcc calc_check_inv.c -o calc_check_inv
// Δοκιμές:
// ./calc_check_inv
// Please enter the first number: 12
// Please enter the second number: a
// Error: Invalid input for the second number.
// ./calc_check_inv
// Please enter the first number: a
// Error: Invalid input for the first number.