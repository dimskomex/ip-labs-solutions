#include <stdio.h>

void basel() {
    // Αρχικοποίηση του αθροίσματος
    double sum_total = 0.0;
    double current_term;  // Ενδιάμεση μεταβλητή για τον τρέχοντα όρο

    // Χρήση της επανάληψης for για τον υπολογισμό του αθροίσματος
    for (int i = 1; i <= 100; i++) {  // Μπορούμε να αλλάξουμε το 100 σε οποιοδήποτε θετικό ακέραιο.
        current_term = 1.0 / (i * i);  
        sum_total += current_term;  
    }

    // Εκτύπωση του αποτελέσματος
    printf("Sum of the series: %.10f\n", sum_total);
}

int main() {
    // Κλήση της συνάρτησης
    basel();
    return 0;
}

// Μεταγλώττιση:
// gcc seq_basel.c -o seq_basel -lm
// Εκτέλεση:
// ./seq_basel
// Έξοδος για 1-100:
// Sum of the series: 1.6349839002
// Έξοδος για 1-1000:
// Sum of the series: 1.6439345667