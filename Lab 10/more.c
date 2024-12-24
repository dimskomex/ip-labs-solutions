#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 20

// Συνάρτηση για την εμφάνιση 20 γραμμών του αρχείου
void show_lines(FILE *fp) {
  char line[256];
  int line_count = 0;

  // Διαβάζουμε και εμφανίζουμε μέχρι 20 γραμμές ή το τέλος του αρχείου
  while (line_count < LINES_PER_PAGE && fgets(line, sizeof(line), fp)) {
    printf("%s", line);
    line_count++;
  }

  // Επιστρέφουμε αν το τέλος του αρχείου φτάσει ή αν δεν έχουμε άλλες γραμμές
  // να εμφανίσουμε
  if (line_count < LINES_PER_PAGE) {
    return;
  }

  // Ρωτάμε τον χρήστη αν θέλει να συνεχίσει με τις επόμενες γραμμές
  char ch;
  printf("\n-- More -- (Press 'q' to quit, any other key to continue): ");
  ch = getchar();
  while (ch != 'q' && ch != 'Q' && ch != '\n') {
    ch = getchar();  // Περιμένουμε την είσοδο του χρήστη
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    // Αν δεν δοθεί όνομα αρχείου
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    // Αν αποτύχει το άνοιγμα του αρχείου
    perror("Error opening file");
    return 1;
  }

  // Εμφανίζουμε τις γραμμές του αρχείου
  while (!feof(fp)) {
    show_lines(fp);
  }

  fclose(fp);
  return 0;
}

// Μεταγλώττιση:
// gcc more.c -o more
// Δοκιμές:
// ./more more.c
// ./more more.c | less
// ./more more.c | more