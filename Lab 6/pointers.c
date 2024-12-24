#include <stdio.h>

// Συνάρτηση για εκτύπωση ενός πίνακα
void print_array(int *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d  ", array[i]);  // Εκτύπωση στοιχείων με 2 κενά διαστήματα
  }
  printf("\n");
}

int main() {
  int i, a[8], *pa;

  // Αρχικοποίηση του πίνακα
  for (i = 0; i < 8; i++) {
    a[i] = i * i;  // Το κάθε στοιχείο παίρνει την τιμή i^2
  }

  // Εντολές που τροποποιούν τον πίνακα
  pa = &a[0];  // pa δείχνει στο πρώτο στοιχείο του πίνακα
  a[6] = *(pa + 4);  // Το a[6] γίνεται ίσο με το a[4]
  *(pa + 3) = a[5];  // Το a[3] γίνεται ίσο με το a[5]
  pa++;              // Το pa δείχνει στο a[1]
  a[0] = *((pa++) + 2);  // Το a[0] γίνεται ίσο με το a[4] (λόγω pa++)
  *((++pa) + 5) = a[1];  // Το a[7] γίνεται ίσο με το a[1] (λόγω ++pa)
  *(&a[5] - 1) = *(pa);  // Το a[4] γίνεται ίσο με το a[1]

  // Εκτύπωση του πίνακα
  printf("Array contents after modifications:\n");
  print_array(a, 8);

  return 0;
}

// Μεταγλώττιση:
// gcc pointers.c -o pointers

// Εκτέλεση:
// ./pointers

// Έξοδος:
// Array contents after modifications:
// 25  1  4  25  25  25  16  49