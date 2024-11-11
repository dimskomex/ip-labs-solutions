#include <stdio.h>

void harmonic(int terms) {
    double sum_total = 0.0;
    double current_term;

    for (int i = 1; i <= terms; i++) {
        // Υπολογισμός του τρέχοντα όρου (-1)^(i+1) / i
        current_term = (i % 2 == 0 ? -1.0 : 1.0) / i;
        sum_total += current_term;  // Προσθήκη του όρου στο άθροισμα
    }

    // Εκτύπωση του αποτελέσματος με ακρίβεια 6 δεκαδικών ψηφίων
    printf("Approximate value of S2 with %d terms: %.6f\n", terms, sum_total);
}

int main() {
    int terms;

    // Ζητάμε από τον χρήστη τον αριθμό των όρων
    printf("Enter the number of terms to use: ");
    scanf("%d", &terms);

    // Κλήση της συνάρτησης
    harmonic(terms);

    return 0;
}

// Μεταγλώττιση:
// gcc seq_harmonic.c -o seq_harmonic
// Εκτέλεση:
// ./seq_harmonic
// Έξοδος για 1-100:
// Approximate value of S2 with 100 terms: 0.688172
// Έξοδος για 1-1000:
// Approximate value of S2 with 1000 terms: 0.692647
