#include <stdio.h>

// Δήλωση της συνάρτησης goodf από το myfun.c
void goodf(int x, int y, int *sum, int *diff);

int main() {
  // Δήλωση μεταβλητών
  int a, b, sum = 0, diff = 0;

  // Είσοδος των τιμών για τις μεταβλητές a και b
  printf("Enter the value of a: ");
  if (scanf("%d", &a) != 1) {
    printf("Error: Invalid input for a.\n");
    return 1;
  }

  printf("Enter the value of b: ");
  if (scanf("%d", &b) != 1) {
    printf("Error: Invalid input for b.\n");
    return 1;
  }

  // Κλήση της συνάρτησης goodf με χρήση δεικτών
  goodf(a, b, &sum, &diff);

  // Εμφάνιση των αποτελεσμάτων
  printf("Sum: %d\n", sum);
  printf("Diff: %d\n", diff);

  return 0;
}

// Οι τιμές των μεταβλητών a και b εισάγονται από τον χρήστη μέσω της συνάρτησης
// scanf(). Ελέγχεται αν η εισαγωγή είναι έγκυρη. Σε περίπτωση μη έγκυρης
// εισόδου, εμφανίζεται μήνυμα λάθους και το πρόγραμμα τερματίζεται. Η συνάρτηση
// goodf καλείται με τις τιμές a και b και ενημερώνει τις τιμές των sum και diff
// μέσω δεικτών.

// Μεταγλώττιση:
// gcc -c myfun.c
// gcc -c myprog.c
// gcc -o myprog myfun.o myprog.o

// Εκτέλεση:
// ./myprog

// Παράδειγμα Εκτέλεσης:
// Enter the value of a: 8
// Enter the value of b: 3
// Sum: 11
// Diff: 5

// Παράδειγμα Εκτέλεσης με Λανθασμένη Είσοδο:
// Enter the value of a: abc
// Error: Invalid input for a.