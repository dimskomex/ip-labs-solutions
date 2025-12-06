#include <stdio.h>

// Η συνάρτηση αυτή, όπως ορίζει η εκφώνηση
// παίρνει έναν ακέραιο (δηλαδή int) n και επιστρέφει:
// 1 αν n περιττός
// 0 αν n άρτιος
// Η συνάρτηση αυτή γίνεται πολύ εύκολα με μία if
int isodd(int n) {
    if (n % 2 == 1)
        return 1;
    else
        return 0;
}

// Η λογική της collatz με επανάληψη είναι αρκετά απλή.
// Έχουμε έναν μετρητή που ουσιαστικά περιέχει τον αριθμό
// βημάτων που θα κάνει η επανάληψη.
// Για το εσωτερικό της επανάληψης, εφαρμόζουμε τις
// κατάλληλες πράξεις με βάση τι είναι το n (άρτιος ή περιττός)
int collatz_it(int n) {
    int steps = 1;
    while (n != 1) {
        if (isodd(n) == 1)
            n = 3 * n + 1;
        else
            n /= 2;
        steps++;
    }

    return steps;
}

// Η αναδρομή είναι δύσκολη στην αρχή, αλλά
// πρόκειται για ένα από τα πιο ισχυρά εργαλεία
// ενός προγραμματιστή. Υπάρχουν διάσημες γλώσσες όπως η Prolog και η Haskell
// που δεν διαθέτουν βρόχους επανάληψης, οπότε τα πάντα πρέπει να γίνουν
// αναδρομικά. Η υλοποίηση της Collatz με αναδρομή, μας δίνει μία μικρή γεύση στο πως
// σκεφτόμαστε την αναδρομή.

// Στην αναδρομή η μεθοδολογία είναι η εξής:
// base case + step όπου:
// base case κάτι το οποίο γνωρίζουμε πως να το χειριστούμε &
// step τι φίλτρο πρέπει να περάσουμε στην συνάρτηση ώστε να πετύχει.
int collatz(int n) {
    if (n == 1)                         // base case: όταν έχουμε φτάσει στον αριθμό 1, η ακολουθία Collatz έχει μήκος 1
        return 1;

    int next_n;
    if (isodd(n) == 1)
        next_n = n * 3 + 1;
    else
        next_n = n / 2;

    return 1 + collatz(next_n);      // step: το μήκος είναι 1 + το μήκος της ακολουθίας με βάση το νεό n.
}


int main(void) {
    int n;
    printf("Number to find the length of the collatz sequence: ");
    scanf("%d", &n);
    int result_it = collatz_it(n);
    printf("Iterative result: %d\n", result_it);
    int result_rec = collatz(n);
    printf("Recursive result: %d\n", result_rec);
    return 0;
}