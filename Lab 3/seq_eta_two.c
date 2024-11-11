#include <stdio.h>
#include <math.h>  // Απαιτείται για τον υπολογισμό του τετραγώνου

void eta_two(int terms) {
    double sum_total = 0.0;
    double current_term;
    
    for (int i = 1; i <= terms; i++) {
        // Υπολογισμός του τρέχοντα όρου (-1)^(i-1) / i^2
        current_term = pow(-1, i - 1) / (i * i);
        sum_total += current_term;  // Προσθήκη του όρου στο άθροισμα
    }

    // Εκτύπωση του αποτελέσματος με ακρίβεια 6 δεκαδικών ψηφίων
    printf("Approximate value of η(2): %.6f\n", sum_total);
}

int main() {
    int terms;

    // Ζητάμε από τον χρήστη τον αριθμό των όρων
    printf("Enter the number of terms to use: ");
    scanf("%d", &terms);

    // Κλήση της συνάρτησης
    eta_two(terms);
    
    return 0;
}


// Μεταγλώττιση:
// gcc seq_eta_two.c -o seq_eta_two -lm
// Εκτέλεση:
// ./seq_eta_two
// Έξοδος για 1-100:
// Approximate value of η(2): 0.822418
// Έξοδος για 1-1000:
// Approximate value of η(2): 0.822467
//
//
// Η σειρά συγκλίνει στον αριθμό η(2), που σχετίζεται με τη συνάρτηση Dirichlet 
// η, η οποία είναι μια εναλλασσόμενη σειρά που συγκλίνει πιο γρήγορα από την αντίστοιχη Riemann 
// ζ για τον ίδιο δείκτη, λόγω της εναλλασσόμενης φύσης των προσήμων.