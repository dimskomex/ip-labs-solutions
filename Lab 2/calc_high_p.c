#include <stdio.h>

int main() {
    long long int num1, num2;

    // Ζητάμε τον πρώτο μεγάλο αριθμό
    printf("Please enter the first number: ");
    if (scanf("%lld", &num1) != 1) {
        fprintf(stderr, "Invalid input for the first number.\n");
        return 1;
    }

    // Ζητάμε τον δεύτερο μεγάλο αριθμό
    printf("Please enter the second number: ");
    if (scanf("%lld", &num2) != 1) {
        fprintf(stderr, "Invalid input for the second number.\n");
        return 1;
    }

    // Υπολογίζουμε και τυπώνουμε το άθροισμα
    printf("The sum of the two numbers is: %lld\n", num1 + num2);

    return 0;  // Επιστρέφουμε επιτυχία
}

// Μεταγλώττιση:
// gcc calc_high_p.c -o calc_high_p
// Δοκιμές:
// ./calc_high_p
// Please enter the first number: 100000000
// Please enter the second number: 30000000
// The sum of the two numbers is: 130000000
// $ echo $?
// 0