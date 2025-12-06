#include <stdio.h>

// Μεταβλητή που μετράει πόσες αναδρομικές κλήσεις έγιναν
int number_of_rec = 0;

// Αναδρομική υλοποίηση της ακολουθίας Fibonacci
int fib(int n) {
    // Αν n είναι 0 ή 1, επιστρέφουμε n (βασικές περιπτώσεις)
    if (n <= 1)
        return n;

    // Μετράμε μία ακόμη αναδρομική κλήση
    number_of_rec++;

    // Επιστρέφουμε το άθροισμα των δύο προηγούμενων Fibonacci αριθμών
    return fib(n - 1) + fib(n - 2);
}

// Επαναληπτική (iterative) υλοποίηση Fibonacci – πολύ πιο αποδοτική
int fib_it(int n) {
    // Αν n = 0, επιστρέφουμε 0 άμεσα
    if (n == 0)
        return 0;

    // Αρχικές τιμές Fibonacci
    int fn_minus_1 = 1;  // F(1)
    int fn_minus_2 = 0;  // F(0)

    // Το F(2) = F(1) + F(0)
    int result = fn_minus_1 + fn_minus_2;

    // Επανάληψη από το 2 μέχρι το n-1
    for (int i = 2; i < n; ++i) {
        int tmp = fn_minus_1;   // προσωρινή μεταβλητή για ανανέωση τιμών
        fn_minus_1 = result;    // μετακίνηση μίας θέσης μπροστά
        fn_minus_2 = tmp;       // και της προηγούμενης τιμής
        result = fn_minus_1 + fn_minus_2;  // υπολογισμός νέου Fibonacci
    }

    return result;
}

int main(void) {
    printf("How many fibonacci terms would you like: ");
    
    int n;
    scanf("%d", &n);  // διαβάζουμε πόσους όρους θέλει ο χρήστης

    for (int i = 0; i < n; i++) {
        // Αναδρομική έκδοση (απενεργοποιημένη γιατί είναι αργή)
        // printf("fib(%d) = %d\n", i, fib(i));

        // Γρήγορη επαναληπτική έκδοση
        printf("fib(%d) = %d\n", i, fib_it(i));
    }

    // Εκτύπωση του συνολικού πλήθους αναδρομικών κλήσεων
    printf("Total number of recursions: %d\n", number_of_rec);

    return 0;
}
