#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Έλεγχος για σωστό αριθμό ορισμάτων
  if (argc != 4) {
    printf(
        "Error: Incorrect number of arguments. Usage: ./calc <num1> <operator> "
        "<num2>\n");
    return 1;
  }

  // Μετατροπή των πρώτων δύο ορισμάτων σε ακέραιους αριθμούς
  int num1 = atoi(argv[1]);
  int num2 = atoi(argv[3]);
  char operator= argv[2][0];  // Ο χαρακτήρας της πράξης

  // Εκτέλεση της επιθυμητής αριθμητικής πράξης
  switch (operator) {
    case '+':
      printf("%d\n", num1 + num2);  // Πρόσθεση
      break;
    case '-':
      printf("%d\n", num1 - num2);  // Αφαίρεση
      break;
    case '*':
      printf("%d\n", num1 * num2);  // Πολλαπλασιασμός
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero.\n");
      } else {
        printf("%d\n", num1 / num2);  // Πηλίκο διαίρεσης
      }
      break;
    case '%':
      if (num2 == 0) {
        printf("Error: Division by zero.\n");
      } else {
        printf("%d\n", num1 % num2);  // Υπόλοιπο διαίρεσης
      }
      break;
    default:
      printf("Error: Unknown operator. Supported operators: +, -, *, /, %%.\n");
      return 1;  // Επιστροφή με σφάλμα
  }

  return 0;
}

// Μεταγλώττιση:
// gcc calc.c -o calc
// Δοκιμές:
// ./calc 5 + 3
// ./calc 5 - 3
// ./calc 5 \* 3
// ./calc 5 / 3
// ./calc 5 % 3
