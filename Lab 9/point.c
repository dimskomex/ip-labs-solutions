#include <stdio.h>

// Ορισμός της δομής point για αποθήκευση συντεταγμένων
struct point {
  double x;  // Συντεταγμένη x
  double y;  // Συντεταγμένη y
};

// Συνάρτηση που υπολογίζει το μέσο του ευθυγράμμου τμήματος με άκρα τα σημεία a
// και b
struct point middle(struct point a, struct point b) {
  struct point mid;
  mid.x = (a.x + b.x) / 2;  // Υπολογισμός μέσου όρου των συντεταγμένων x
  mid.y = (a.y + b.y) / 2;  // Υπολογισμός μέσου όρου των συντεταγμένων y
  return mid;
}

int main() {
  // Ορισμός των σημείων a και b
  struct point a = {1.2, 5.4};
  struct point b = {7.3, 1.8};

  // Υπολογισμός του μέσου σημείου
  struct point mid = middle(a, b);

  // Εκτύπωση των συντεταγμένων του μέσου σημείου
  printf("Middle point: (%.2f, %.2f)\n", mid.x, mid.y);

  return 0;
}

// Μεταγλώττιση:
// gcc point.c -o point
// Εκτέλεση:
// ./point
// Αναμενόμενη έξοδος:
// Middle point: (4.25, 3.60)
