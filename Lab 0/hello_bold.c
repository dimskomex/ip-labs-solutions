#include <stdio.h>

int main() {
  // Εκτύπωση του "Hello world" με έντονη γραφή
  printf("Hello \033[1mworld\033[0m!\n");

  return 0;
}

// Μεταγλώττιση:
// gcc hello_bold.c -o hello_bold
// Εκτέλεση:
// ./hello_bold
// Έξοδος:
// Hello world! (με έντονη γραφή)