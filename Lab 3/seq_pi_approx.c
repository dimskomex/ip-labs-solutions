#include <stdio.h>
#include <math.h>  // Απαιτείται για τη χρήση της συνάρτησης sqrt

void pi_approx() {
    // Αρχικοποίηση του αθροίσματος
    double sum_total = 0.0;
    double current_term;  // Ενδιάμεση μεταβλητή για τον τρέχοντα όρο
    int i = 1;

    // Χρήση της επανάληψης do...while για τον υπολογισμό του αθροίσματος
    do {
        current_term = 1.0 / (i * i);  
        sum_total += current_term;  
        i++;
    } while (i <= 100);

    // Υπολογισμός της προσέγγισης του π
    double pi = sqrt(6 * sum_total);

    // Εκτύπωση του αποτελέσματος
    printf("Approximate value of pi: %.10f\n", pi);
}

int main() {
    // Κλήση της συνάρτησης
    pi_approx();
    return 0;
}

// Μεταγλώττιση: gcc seq_pi_approx.c -o seq_pi_approx -lm
// Εκτέλεση: ./seq_pi_approx
// Έξοδος:
// Approximate value of pi: 3.1320765318