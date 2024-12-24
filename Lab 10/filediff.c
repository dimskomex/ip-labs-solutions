#include <stdio.h>
#include <stdlib.h>

int compare_files(FILE *file1, FILE *file2) {
  int ch1, ch2;
  long position = 0;  // Αρχική θέση για τη σύγκριση

  // Διαβάζουμε χαρακτήρα από τα δύο αρχεία
  while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
    position++;
    if (ch1 != ch2) {
      // Αν οι χαρακτήρες διαφέρουν, επιστρέφουμε τη θέση της διαφοράς
      return position;
    }
  }

  // Αν φτάσουμε στο EOF και τα δύο αρχεία είναι ίδια, επιστρέφουμε 0
  if (ch1 == EOF && ch2 == EOF) {
    return 0;
  }

  // Αν φτάσουμε σε EOF σε ένα από τα αρχεία και το άλλο συνεχίζει, επιστρέφουμε
  // τη θέση του EOF
  return position + 1;
}

int main(int argc, char *argv[]) {
  // Βεβαιωνόμαστε ότι έχουμε δώσει δύο αρχεία ως ορίσματα
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
    return 1;
  }

  FILE *file1 = fopen(argv[1], "rb");
  FILE *file2 = fopen(argv[2], "rb");

  // Έλεγχος αν τα αρχεία άνοιξαν σωστά
  if (file1 == NULL) {
    perror("Error opening file 1");
    return 1;
  }
  if (file2 == NULL) {
    perror("Error opening file 2");
    fclose(file1);  // Κλείσιμο του πρώτου αρχείου αν το δεύτερο δεν ανοίξει
    return 1;
  }

  // Σύγκριση των δύο αρχείων
  int result = compare_files(file1, file2);

  // Εκτύπωση του αποτελέσματος της σύγκρισης
  if (result == 0) {
    printf("The files are identical.\n");
  } else {
    printf("The files differ at byte position %d.\n", result);
  }

  // Κλείσιμο των αρχείων
  fclose(file1);
  fclose(file2);

  return 0;
}

// Μεταγλώττιση:
// gcc filediff.c -o filediff
// Δοκιμή:
// ./filediff file1.txt file2.txt