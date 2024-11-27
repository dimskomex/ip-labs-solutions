#include <stdio.h>

int main() {
  // Εκτύπωση των χαρακτήρων με ASCII κωδικό
  // που είναι πολλαπλάσιο του 3, μεταξύ 33 και 105
  for (int i = 33; i <= 105; i++) {
    if (i % 3 == 0) {
      printf("%c - (dec: %d, hex: %x)\n", i, i, i);
    }
  }
  return 0;
}

// Μεταγλώττιση:
// gcc printchar.c -o printchar
// Εκτέλεση:
// ./printchar
// Έξοδος:
// ! - (dec: 33, hex: 21)
// $ - (dec: 36, hex: 24)
// ' - (dec: 39, hex: 27)
// * - (dec: 42, hex: 2a)
// - - (dec: 45, hex: 2d)
// 0 - (dec: 48, hex: 30)
// 3 - (dec: 51, hex: 33)
// 6 - (dec: 54, hex: 36)
// 9 - (dec: 57, hex: 39)
// < - (dec: 60, hex: 3c)
// ? - (dec: 63, hex: 3f)
// B - (dec: 66, hex: 42)
// E - (dec: 69, hex: 45)
// H - (dec: 72, hex: 48)
// K - (dec: 75, hex: 4b)
// N - (dec: 78, hex: 4e)
// Q - (dec: 81, hex: 51)
// T - (dec: 84, hex: 54)
// W - (dec: 87, hex: 57)
// Z - (dec: 90, hex: 5a)
// ] - (dec: 93, hex: 5d)
// ` - (dec: 96, hex: 60)
// c - (dec: 99, hex: 63)
// f - (dec: 102, hex: 66)
// i - (dec: 105, hex: 69)
