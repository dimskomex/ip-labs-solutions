#include <ctype.h>
#include <stdio.h>

int main() {
  int ch1, ch2;

  // Διαβάζουμε το πρώτο ψηφίο
  ch1 = getchar();

  // Συνεχίζουμε μέχρι να φτάσουμε στο τέλος του αρχείου
  while (ch1 != EOF) {
    // Διαβάζουμε το δεύτερο ψηφίο
    ch2 = getchar();

    // Μετατροπή των δεκαεξαδικών χαρακτήρων σε ακέραιο
    if (isxdigit(ch1) && isxdigit(ch2)) {
      int decoded_char =
          (ch1 <= '9' ? ch1 - '0' : toupper(ch1) - 'A' + 10) * 16 +
          (ch2 <= '9' ? ch2 - '0' : toupper(ch2) - 'A' + 10);
      putchar(decoded_char);  // Εκτυπώνουμε τον αποκωδικοποιημένο χαρακτήρα
    }

    // Διαβάζουμε το επόμενο ζευγάρι ψηφίων
    ch1 = getchar();
  }

  return 0;
}

// Μεταγλώττιση:
// gcc decode.c -o decode
// Εκτέλεση:
// echo -ne 68656c6c6f20776f726c640a | ./decode
// Έξοδος:
// hello world
// Εκτέλεση:
// ./decode < encoded_text
// Έξοδος:
// Lorem Ipsum is simply dummy text of the printing and typesetting industry.