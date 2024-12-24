#include "string.h"

#include <stdio.h>
#include <string.h>

/* Συνάρτηση που υπολογίζει το μήκος μιας συμβολοσειράς χωρίς να συμπεριλαμβάνει
   τον χαρακτήρα τέλους συμβολοσειράς '\0' */
int mystrlen(char *str) {
  if (str == NULL) {
    printf("Error: NULL pointer passed to mystrlen.\n");
    return -1;
  }

  int length = 0;
  while (str[length] != '\0') {
    length++;
  }

  return length;
}

/* Συνάρτηση που προσαρτά τη συμβολοσειρά s2 στο τέλος της συμβολοσειράς s1
   και επιστρέφει έναν δείκτη στην s1 */
char *mystrcat(char *s1, char *s2) {
  if (s1 == NULL || s2 == NULL) {
    printf("Error: NULL pointer passed to mystrcat.\n");
    return NULL;
  }

  char *ptr = s1;
  while (*ptr != '\0') {
    ptr++;
  }

  while (*s2 != '\0') {
    *ptr = *s2;
    ptr++;
    s2++;
  }

  *ptr = '\0';
  return s1;
}

/* Συνάρτηση για να εκτυπώσουμε τις λέξεις από τη συμβολοσειρά χωρίς στίξη
 * χρησιμοποιώντας strtok */
void strtok_example(char *str) {
  // Χαρακτήρες στίξης για διαχωρισμό
  const char *delim = " ,.;!?()[]{}\"'\n\t";
  char *word = strtok(str, delim);

  while (word != NULL) {
    printf("%s\n", word);  // Εκτυπώνουμε την τρέχουσα λέξη
    word = strtok(NULL, delim);  // Προχωράμε στην επόμενη λέξη
  }
}

int main() {
  // 1.3.1 Ορισμός των συμβολοσειρών με στατική δέσμευση μνήμης
  char strA[80];
  char strB[80];

  // 1.3.2 Αντιγραφή των συμβολοσειρών με strcpy
  strcpy(strA, "This is a string.");
  strcpy(strB, "This is another string.");

  // 1.3.3 Εκτύπωση των δύο συμβολοσειρών και υπολογισμός του μήκους τους
  printf("strA: %s\n", strA);
  printf("Length of strA using mystrlen: %d\n", mystrlen(strA));
  printf("strB: %s\n", strB);
  printf("Length of strB using strlen: %zu\n", strlen(strB));

  // 1.3.4 Συγκρίση των συμβολοσειρών strA και strB
  int comparison = strcmp(strA, strB);
  if (comparison == 0) {
    printf("The strings strA and strB are equal.\n");
  } else if (comparison > 0) {
    printf("strA is lexicographically greater than strB.\n");
  } else {
    printf("strA is lexicographically smaller than strB.\n");
  }

  // 1.3.5 Προσαρτήματα των συμβολοσειρών
  // Χρησιμοποιώντας τη δική μας mystrcat
  mystrcat(strA, strB);
  printf("Result of concatenation with mystrcat: %s\n", strA);

  // Χρησιμοποιώντας τη συνάρτηση strcat της C
  strcat(strB, strA);
  printf("Result of concatenation with strcat: %s\n", strB);

  // 1.3.6 Εκτύπωση των λέξεων από την τελική strB χωρίς στίξη
  printf("\nWords from the final strB without punctuation:\n");
  strtok_example(strB);

  return 0;
}

// Μεταγλώττιση:
// gcc string.c -o string
// Εκτέλεση:
// ./string
// Έξοδος:
// strA: This is a string.
// Length of strA using mystrlen: 17
// strB: This is another string.
// Length of strB using strlen: 23
// strA is lexicographically smaller than strB.
// Result of concatenation with mystrcat: This is a string.This is another
// string. Result of concatenation with strcat: This is another string.This is a
// string.This is another string.

// Words from the final strB without punctuation:
// This
// is
// another
// string
// This
// is
// a
// string
// This
// is
// another
// string