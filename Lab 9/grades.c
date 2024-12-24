#include <stdio.h>
#include <stdlib.h>

// Ορισμός της αυτοαναφορικής δομής λίστας
typedef struct listnode *Listptr;
struct listnode {
  int data;
  Listptr next;  // Δείκτης στο επόμενο στοιχείο της λίστας
};

// Συνάρτηση για την εισαγωγή ενός βαθμού στην αρχή της λίστας
void insert_at_start(Listptr *ptr, int grade) {
  // Δημιουργία νέου κόμβου
  Listptr new_node = (Listptr)malloc(sizeof(struct listnode));

  // Αν η δέσμευση μνήμης αποτύχει
  if (new_node == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  // Αρχικοποίηση του νέου κόμβου
  new_node->data = grade;
  new_node->next = *ptr;

  // Ενημέρωση της κεφαλής της λίστας
  *ptr = new_node;
}

// Συνάρτηση για τον υπολογισμό του μέσου όρου των βαθμών στη λίστα
float average(Listptr ptr) {
  int sum = 0;
  int count = 0;

  // Διασχίζουμε τη λίστα και υπολογίζουμε το άθροισμα των βαθμών και τον αριθμό
  // των στοιχείων
  while (ptr != NULL) {
    sum += ptr->data;
    count++;
    ptr = ptr->next;
  }

  // Αν η λίστα είναι κενή, επιστρέφουμε 0.0 για να αποφύγουμε τη διαίρεση με το
  // 0
  if (count == 0) {
    return 0.0;
  }

  return (float)sum / count;
}

int main() {
  Listptr head = NULL;
  int grade;
  char choice;

  // Διαβάζουμε βαθμούς από το πληκτρολόγιο και τους προσθέτουμε στη λίστα
  do {
    printf("Enter a grade: ");
    scanf("%d", &grade);

    insert_at_start(&head, grade);  // Εισαγωγή του βαθμού στην αρχή της λίστας

    printf("Do you want to add another grade? (y/n): ");
    scanf(" %c", &choice);
  } while (choice == 'y' ||
           choice == 'Y');  // Συνεχίζουμε αν ο χρήστης εισάγει 'y' ή 'Y'

  // Υπολογισμός και εκτύπωση του μέσου όρου των βαθμών
  float avg = average(head);
  printf("The average grade is: %.2f\n", avg);

  // Αποδέσμευση της μνήμης που δεσμεύθηκε για τη λίστα
  Listptr temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}

// Μεταγλώττιση:
// gcc grades.c -o grades
// Εκτέλεση:
// ./grades
// Αναμενόμενη έξοδος:
// Enter a grade: 10
// Do you want to add another grade? (y/n): y
// Enter a grade: 15
// Do you want to add another grade? (y/n): y
// Enter a grade: 20
// Do you want to add another grade? (y/n): n
// The average grade is: 15.00
