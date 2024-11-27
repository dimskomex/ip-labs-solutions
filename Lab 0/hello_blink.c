#include <stdio.h>

int main() {
  // Εκτύπωση του "Hello world" με αναβόσβησμα
  printf("Hello \033[5mworld\033[5m!\n");

  return 0;
}

// Μεταγλώττιση:
// gcc hello_blink.c -o hello_blink
// Εκτέλεση:
// ./hello_blink
// Έξοδος:
// Hello world! (με αναβόσβησμα)
// Σημείωση: Για να δείτε το αναβόσβημα, θα πρέπει να τρέξετε το πρόγραμμα σε
// κονσόλα (terminal) και όχι σε κάποιο περιβάλλον ανάπτυξης (π.χ. Visual Studio
// Code).