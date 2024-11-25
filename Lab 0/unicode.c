#include <stdio.h>

int main() {
  // Εκτύπωση του Unicode χαρακτήρα 🔥
  printf("Here is a fire emoji: \U0001F525\n");

  return 0;
}

// Μεταγλώττιση:
// gcc unicode.c -o unicode
// Εκτέλεση:
// ./unicode
// Έξοδος:
// Here is a fire emoji: 🔥
// Σημείωση: Ο Unicode χαρακτήρας 🔥 αντιστοιχεί στον κωδικό U+1F525.