#include <stdio.h>

int main() {
  int ch;

  // Διαβάζουμε τον πρώτο χαρακτήρα
  ch = getchar();

  // Συνεχίζουμε μέχρι να φτάσουμε στο τέλος του αρχείου
  while (ch != EOF) {
    // Εκτυπώνουμε τον ASCII κωδικό του χαρακτήρα σε δεκαεξαδική μορφή με δύο
    // ψηφία
    printf("%02x", ch);

    // Διαβάζουμε τον επόμενο χαρακτήρα
    ch = getchar();
  }

  return 0;
}

// Μεταγλώττιση:
// gcc encode.c -o encode
// Εκτέλεση:
// echo hello world | ./encode
// Έξοδος:
// 68656c6c6f20776f726c640a
// Εκτέλεση:
// ./encode < text > encoded_text
