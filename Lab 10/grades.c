#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Δομή για αποθήκευση του ονόματος και του βαθμού
struct grade {
  char name[MAX_NAME_LENGTH];  // Όνομα φοιτητή
  int grade;                   // Βαθμός
};

int main() {
  FILE *file;
  struct grade student;

  // Άνοιγμα του αρχείου για δυαδική εγγραφή (write)
  file = fopen("grades.dat", "wb");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Διάβασμα ονομάτων και βαθμών και εγγραφή στο αρχείο
  printf("Enter student name and grade (enter 'done' to stop):\n");
  while (1) {
    printf("Name: ");
    if (fgets(student.name, MAX_NAME_LENGTH, stdin) == NULL) {
      break;  // Εξόδος αν δεν μπορούν να διαβαστούν δεδομένα
    }

    // Αφαιρούμε το χαρακτήρα νέας γραμμής από το όνομα (αν υπάρχει)
    student.name[strcspn(student.name, "\n")] = 0;

    // Αν ο χρήστης πληκτρολογήσει 'done', τερματίζουμε την είσοδο
    if (strcmp(student.name, "done") == 0) {
      break;
    }

    // Διάβασμα του βαθμού
    printf("Grade: ");
    if (scanf("%d", &student.grade) != 1) {
      break;  // Αν η είσοδος του βαθμού δεν είναι έγκυρη
    }

    // Αποθήκευση των δεδομένων στο αρχείο
    fwrite(&student, sizeof(struct grade), 1, file);

    // Καθαρισμός του buffer του εισαγωγέα
    getchar();  // Για να καταναλώσουμε τον χαρακτήρα newline που μένει από το
                // scanf
  }

  fclose(file);

  // Άνοιγμα του αρχείου για δυαδική ανάγνωση (read)
  file = fopen("grades.dat", "rb");
  if (file == NULL) {
    perror("Error opening file for reading");
    return 1;
  }

  // Εμφάνιση των δεδομένων του αρχείου
  printf("\nStudent Grades:\n");
  while (fread(&student, sizeof(struct grade), 1, file)) {
    printf("Name: %s, Grade: %d\n", student.name, student.grade);
  }

  fclose(file);
  return 0;
}

// Μεταγλώττιση:
// gcc grades.c -o grades
// Δοκιμές:
// ./grades
// Enter student name and grade (enter 'done' to stop):
// Name: Alice
// Grade: 85
// Name: Bob
// Grade: 90
// Name: done

// Student Grades:
// Name: Alice, Grade: 85
// Name: Bob, Grade: 90