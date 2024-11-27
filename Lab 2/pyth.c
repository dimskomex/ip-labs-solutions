#include <math.h>
#include <stdio.h>

int main() {
  double a, b, c, area, perimeter;

  // Ζητάμε από τον χρήστη να εισάγει τα μήκη των καθέτων πλευρών
  printf("Enter the length of the first perpendicular side: ");
  if (scanf("%lf", &a) != 1 || a <= 0) {
    printf(
        "Error: Invalid input. Please enter a positive number for the side.\n");
    return 1;
  }

  printf("Enter the length of the second perpendicular side: ");
  if (scanf("%lf", &b) != 1 || b <= 0) {
    printf(
        "Error: Invalid input. Please enter a positive number for the side.\n");
    return 1;
  }

  // Υπολογίζουμε την υποτείνουσα με το Πυθαγόρειο Θεώρημα
  c = sqrt(a * a + b * b);

  // Υπολογίζουμε το εμβαδόν του τριγώνου
  area = 0.5 * a * b;

  // Υπολογίζουμε την περίμετρο του τριγώνου
  perimeter = a + b + c;

  // Εμφάνιση αποτελεσμάτων
  printf("Area of the triangle: %.2f\n", area);
  printf("Perimeter of the triangle: %.2f\n", perimeter);

  return 0;
}

// Μεταγλώττιση:
// gcc pyth.c -o pyth -lm
// Δοκιμές:
// ./pyth
// Enter the length of the first perpendicular side: 3
// Enter the length of the second perpendicular side: 4
// Area of the triangle: 6.00
// Perimeter of the triangle: 12.00
