#include <stdio.h>

int main() {
  long long int num1, num2;
  char operation;

  // Ζητάμε τον πρώτο αριθμό
  printf("Please enter the first number: ");
  if (scanf("%lld", &num1) != 1) {
    printf("Invalid input for the first number.\n");
    return 1;
  }

  // Ζητάμε τον δεύτερο αριθμό
  printf("Please enter the second number: ");
  if (scanf("%lld", &num2) != 1) {
    printf("Invalid input for the second number.\n");
    return 1;
  }

  // Ζητάμε την πράξη που θέλει ο χρήστης
  printf("Please enter the operation (+ for addition, - for subtraction): ");
  scanf(" %c", &operation);  // To κενό διάστημα πριν το %c είναι για να
                             // αγνοηθεί τυχόν προηγούμενο newline

  // Υπολογισμός ανάλογα με την πράξη
  if (operation == '+') {
    printf("The result of the addition is: %lld\n", num1 + num2);
  } else if (operation == '-') {
    printf("The result of the subtraction is: %lld\n", num1 - num2);
  } else {
    printf("Invalid operation. Please enter + or -.\n");
    return 1;
  }

  return 0;  // Επιστροφή επιτυχίας
}

// Μεταγλώττιση:
// gcc calc_add_sub.c -o calc_add_sub
// Δοκιμές:
// ./calc_add_sub
// Please enter the first number: 2
// Please enter the second number: 1
// Please enter the operation (+ for addition, - for subtraction): -
// The result of the subtraction is: 1
// ./calc_add_sub
// Please enter the first number: 3
// Please enter the second number: 11
// Please enter the operation (+ for addition, - for subtraction): +
// The result of the addition is: 14