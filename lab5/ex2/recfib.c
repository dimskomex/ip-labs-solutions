#include <stdio.h>

/* 
    Οι global μεταβλητές είναι μεταβλητές που ορίζονται εκτός της main ή οποιασδήποτε άλλης συνάρτησης.
    Το θετικό είναι ότι είναι ορτατές από όλες τις συναρτήσεις και μπορούν να τις χρησιμοποιήσουν όλες.
    Το κακό είναι ότι καλό θα ήταν να τις αποφεύγουμε, μαθαίνοντας νέα πράγματα για την C θα μπορέσεις
    να λύσεις αυτό το πρόβλημα με πιο καλές πρακτικές!
*/

int counter = 0;

int fib(int n)
{
    counter++;              // κάθε φορά που καλείται η fib, αυξάνουμε τον counter
    if (n == 0 || n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main(void)
{
    for (int i = 28; i <= 35; ++i) {
        printf("Fibonacci for n = %d is: %d\n", i, fib(i));
        counter--;          // μειώνουμε το πλήθος για να μην έχουμε προσθέσει την κλήση της συνάρτησης που κάναμε εμείς οι ίδιοι
    }

    printf("The fib was called %d times\n", counter);

    return 0;
}

/*
    Ο χρόνος υπολογισμού του προγράμματος αυξάνεται επειδή όπως δείχνει το σχήμα, το 2 υπολογίζεται 2 φορές!
    Άρα, η συνάρτηση θα πρέπει να ξανά "στηθεί" για n τα οποία το έχει ξανά κάνει!
    Αυτό για μικρά n δεν δημιουργεί μεγάλο πρόβλημα, όμως όταν το n έχει τιμή πχ 50, η διαφορά στον χρόνο φαίνεται.
*/