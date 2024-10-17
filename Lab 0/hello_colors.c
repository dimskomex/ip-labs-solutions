#include <stdio.h>

int main() {
    // Εκτύπωση του "Hello world!" με διάφορα χρώματα χρησιμοποιώντας ANSI codes
    
    // Μαύρο χρώμα
    printf("\033[30mHello world!\033[0m\n");

    // Κόκκινο χρώμα
    printf("\033[31mHello world!\033[0m\n");

    // Πράσινο χρώμα
    printf("\033[32mHello world!\033[0m\n");

    // Κίτρινο χρώμα
    printf("\033[33mHello world!\033[0m\n");

    // Μπλε χρώμα
    printf("\033[34mHello world!\033[0m\n");

    // Μωβ χρώμα
    printf("\033[35mHello world!\033[0m\n");

    // Κυανό χρώμα
    printf("\033[36mHello world!\033[0m\n");

    // Λευκό χρώμα
    printf("\033[37mHello world!\033[0m\n");

    return 0;
}

// Μεταγλώττιση:
// gcc hello_colors.c -o hello_colors
// Εκτέλεση:
// ./hello_colors
// Έξοδος:
// Hello world! (μαύρο χρώμα)
// Hello world! (κόκκινο χρώμα)
// Hello world! (πράσινο χρώμα)
// Hello world! (κίτρινο χρώμα)
// Hello world! (μπλε χρώμα)
// Hello world! (μωβ χρώμα)
// Hello world! (κυανό χρώμα)
// Hello world! (λευκό χρώμα)
