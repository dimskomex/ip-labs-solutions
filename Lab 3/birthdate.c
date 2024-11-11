#include <stdio.h>
#include <math.h>  // Για τη συνάρτηση floor()

int calculate_day(int day, int month, int year) {
    int NYYYY, NMM, day_of_week;
    int IDAY;

    // Υπολογισμός NYYYY και NMM ανάλογα με τον μήνα
    if (month <= 2) {
        NYYYY = year - 1;
        NMM = 0;
    } else {
        NYYYY = year;
        NMM = (4 * month + 23) / 10;
    }

    // Υπολογισμός του 1DAY
    IDAY = 365 * year + day + 31 * (month - 1) - NMM + (int)floor(NYYYY / 4.0) - (int)floor(NYYYY / 100.0) + (int)floor(NYYYY / 400.0);

    // Υπολογισμός της ημέρας της εβδομάδας
    day_of_week = IDAY % 7;

    return day_of_week;
}

void print_day_of_week(int day_of_week) {
    // Εκτύπωση της ημέρας της εβδομάδας
    switch(day_of_week) {
        case 0: printf("Saturday\n"); break;
        case 1: printf("Sunday\n"); break;
        case 2: printf("Monday\n"); break;
        case 3: printf("Tuesday\n"); break;
        case 4: printf("Wednesday\n"); break;
        case 5: printf("Thursday\n"); break;
        case 6: printf("Friday\n"); break;
    }
}

int main() {
    int day, month, year;

    // Εισαγωγή της ημερομηνίας από τον χρήστη
    printf("Enter day (DD): ");
    scanf("%d", &day);
    printf("Enter month (MM): ");
    scanf("%d", &month);
    printf("Enter year (YYYY): ");
    scanf("%d", &year);

    // Υπολογισμός της ημέρας της εβδομάδας
    int day_of_week = calculate_day(day, month, year);

    // Εκτύπωση της ημέρας της εβδομάδας
    printf("The day of the week is: ");
    print_day_of_week(day_of_week);

    return 0;
}

// Μεταγλώττιση:
// gcc birthdate.c -o birthdate -lm
// Εκτέλεση:
// ./birthdate
// Εξόδος για 1/2/2004:
// Enter day (DD): 1
// Enter month (MM): 2
// Enter year (YYYY): 2004
// The day of the week is: Sunday
// Εξόδος για 16/2/1923:
// Enter day (DD): 16
// Enter month (MM): 2
// Enter year (YYYY): 1923
// The day of the week is: Friday