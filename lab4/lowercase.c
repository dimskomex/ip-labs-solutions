#include <stdio.h>

int main() {
  int ch;
  ch = getchar();
  while (ch != EOF) {
    /* 
        Εάν ο χαρακτήρας είναι κεφαλαίος, 
        μετέτρεψέ τον σε μικρο και το 
        αντίστροφο
    */
    if (ch >= 'A' && ch <= 'Z') {
      ch = ch + ('a'-'A');
    } else if (ch >= 'a' && ch <= 'z') {
      ch = ch - ('a'-'A');
    }

    putchar(ch);
    ch = getchar();
  }
  return 0;
}