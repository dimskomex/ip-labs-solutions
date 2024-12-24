#include <stdio.h>
#include <stdlib.h>

// Ορισμός της αυτοαναφορικής δομής δυαδικού δένδρου
typedef struct tnode *Treeptr;
struct tnode {
  int data;       // Ακέραιος αριθμός στον κόμβο
  Treeptr left;   // Δείκτης στο αριστερό παιδί
  Treeptr right;  // Δείκτης στο δεξί παιδί
};

// Συνάρτηση για την προσθήκη ενός αριθμού x στο ταξινομημένο δυαδικό δένδρο
Treeptr addtree(Treeptr p, int x) {
  if (p == NULL) {  // Αν το δένδρο είναι κενό, δημιουργούμε έναν νέο κόμβο
    p = (Treeptr)malloc(sizeof(struct tnode));
    if (p == NULL) {
      printf("Memory allocation failed.\n");
      return NULL;
    }
    p->data = x;
    p->left = p->right = NULL;
  } else if (x < p->data) {  // Αν ο αριθμός x είναι μικρότερος, πάμε στο
                             // αριστερό παιδί
    p->left = addtree(p->left, x);
  } else if (x > p->data) {  // Αν ο αριθμός x είναι μεγαλύτερος, πάμε στο δεξί
                             // παιδί
    p->right = addtree(p->right, x);
  }
  // Αν x == p->data, δεν κάνουμε τίποτα (δεν εισάγουμε διπλότυπα)
  return p;
}

// Συνάρτηση για την εκτύπωση του δένδρου με in-order διάσχιση
void treeprint(Treeptr p) {
  if (p != NULL) {
    treeprint(p->left);  // Επισκεπτόμαστε το αριστερό παιδί
    printf("%d ", p->data);  // Εκτυπώνουμε την τιμή του τρέχοντος κόμβου
    treeprint(p->right);  // Επισκεπτόμαστε το δεξί παιδί
  }
}

int main() {
  Treeptr root = NULL;  // Αρχικοποιούμε το δένδρο ως κενό (NULL)
  int num;
  char c;

  // Διαβάζουμε αριθμούς από το πληκτρολόγιο μέχρι το τέλος της εισόδου
  printf("Enter numbers to insert into the tree (Ctrl+D to finish):\n");
  while (scanf("%d%c", &num, &c) == 2) {
    // Προσθέτουμε τον αριθμό στο δένδρο
    root = addtree(root, num);

    // Ελέγχουμε αν έχουμε φτάσει στο τέλος της γραμμής (για να διαβάσουμε μόνο
    // έναν αριθμό ανά γραμμή)
    if (c == '\n') {
      continue;
    }
  }

  // Εκτύπωση του δένδρου με in-order διάσχιση
  printf("In-order traversal of the tree:\n");
  treeprint(root);
  printf("\n");

  return 0;
}

// Μεταγλώττιση:
// gcc tree.c -o tree
// Εκτέλεση:
// ./tree
// Αναμενόμενη έξοδος:
// Enter numbers to insert into the tree (Ctrl+D to finish):
// 5 3 7 2 4 6 8
// In-order traversal of the tree:
// 2 3 4 5 6 7 8