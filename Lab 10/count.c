#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Έλεγχος αν δόθηκε το όνομα αρχείου ως όρισμα
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  // Έλεγχος αν το αρχείο άνοιξε σωστά
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int char_count = 0;  // Μετρητής για τους χαρακτήρες
  int line_count = 0;  // Μετρητής για τις γραμμές
  int ch;  // Μεταβλητή για την ανάγνωση κάθε χαρακτήρα

  // Διαβάζουμε το αρχείο χαρακτήρα προς χαρακτήρα
  while ((ch = fgetc(file)) != EOF) {
    char_count++;  // Αύξηση του μετρητή χαρακτήρων
    if (ch == '\n') {
      line_count++;  // Αύξηση του μετρητή γραμμών όταν βρίσκουμε χαρακτήρα
                     // αλλαγής γραμμής
    }
  }

  // Αν το αρχείο δεν είναι κενό, προσθέτουμε μια γραμμή
  if (char_count > 0 && ch != '\n') {
    line_count++;
  }

  // Εμφανίζουμε τα αποτελέσματα
  printf("Character count: %d\n", char_count);
  printf("Line count: %d\n", line_count);

  // Κλείνουμε το αρχείο
  fclose(file);

  return 0;
}

// Μεταγλώττιση:
// gcc count.c -o count
// Εκτέλεση:
// ./count <filename>
// ./count more.c
// Character count: 1803
// Line count: 59