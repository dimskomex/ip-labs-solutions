#include <stdio.h>
#include <stdlib.h>

// Ορισμός της δομής person για αποθήκευση ονόματος, επωνύμου και πατρώνυμου
struct person {
  char *fname;  // Όνομα
  char *lname;  // Επώνυμο
  char *mname;  // Πατρώνυμο
};

// Συνάρτηση που δεσμεύει χώρο για μια δομή person και την αρχικοποιεί
struct person *person_init(char *firstname, char *lastname, char *middlename) {
  // Δέσμευση μνήμης για τη δομή person
  struct person *p = (struct person *)malloc(sizeof(struct person));

  // Αν η δέσμευση μνήμης αποτύχει
  if (p == NULL) {
    printf("Memory allocation failed.\n");
    return NULL;
  }

  // Αρχικοποίηση των πεδίων της δομής
  p->fname = firstname;
  p->lname = lastname;
  p->mname = middlename;

  return p;
}

// Συνάρτηση που καταχωρεί τα στοιχεία ενός παιδιού, βασισμένο στον πατέρα
struct person *childof(struct person father, char *newname) {
  // Δημιουργία και αρχικοποίηση της δομής για το παιδί
  return person_init(newname, father.lname, father.fname);
}

int main() {
  // Δεσμεύουμε μνήμη για τις συμβολοσειρές των ονομάτων
  char fname[50], lname[50], mname[50], childname[50];

  // Εισαγωγή στοιχείων του πατέρα από το πληκτρολόγιο
  printf("Enter father's first name: ");
  scanf("%49s", fname);  // Διαβάζουμε το όνομα του πατέρα
  printf("Enter father's last name: ");
  scanf("%49s", lname);  // Διαβάζουμε το επώνυμο του πατέρα
  printf("Enter father's middle name: ");
  scanf("%49s", mname);  // Διαβάζουμε το πατρώνυμο του πατέρα

  // Δημιουργία και αρχικοποίηση της δομής για τον πατέρα
  struct person *father = person_init(fname, lname, mname);

  // Αν η δέσμευση μνήμης για τον πατέρα απέτυχε
  if (father == NULL) {
    return 1;  // Επιστροφή με σφάλμα
  }

  // Εισαγωγή στοιχείων του παιδιού από το πληκτρολόγιο
  printf("Enter child's first name: ");
  scanf("%49s", childname);  // Διαβάζουμε το όνομα του παιδιού

  // Δημιουργία και καταχώρηση του παιδιού, χρησιμοποιώντας τον πατέρα
  struct person *child = childof(*father, childname);

  // Εκτύπωση των στοιχείων του πατέρα και του παιδιού
  if (child != NULL) {
    printf("Father: %s %s, %s\n", father->fname, father->lname, father->mname);
    printf("Child: %s %s, %s\n", child->fname, child->lname, child->mname);
  }

  // Αποδέσμευση της μνήμης που δεσμεύθηκε
  free(father);
  free(child);

  return 0;
}

// Μεταγλώττιση:
// gcc person.c -o person
// Εκτέλεση:
// ./person
// Enter father's first name: Nick
// Enter father's last name: Daniels
// Enter father's middle name: Carl
// Enter child's first name: James
// Father: Nick Daniels, Carl
// Child: James Daniels, Nick
