#include <stdio.h>

int main() {
  int ch;

  // Διαβάζουμε τον πρώτο χαρακτήρα
  ch = getchar();

  // Συνεχίζουμε μέχρι να φτάσουμε στο τέλος του αρχείου
  while (ch != EOF) {
    // Εάν είναι κεφαλαίο γράμμα, το μετατρέπουμε σε πεζό
    if (ch >= 'A' && ch <= 'Z') {
      ch = ch + ('a' - 'A');
    }
    // Εάν είναι πεζό γράμμα, το μετατρέπουμε σε κεφαλαίο
    else if (ch >= 'a' && ch <= 'z') {
      ch = ch - ('a' - 'A');
    }

    // Εκτυπώνουμε τον χαρακτήρα
    putchar(ch);

    // Διαβάζουμε τον επόμενο χαρακτήρα
    ch = getchar();
  }

  return 0;
}

// Μεταγλώττιση:
// gcc lowercase_swap.c -o lowercase_swap
// Εκτέλεση:
// ./lowercase_swap
// Παράδειγμα:
// echo "Hello, World!" | ./lowercase_swap
// Έξοδος:
// hELLO, wORLD!