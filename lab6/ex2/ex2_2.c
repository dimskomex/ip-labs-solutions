#include <stdio.h>

#define N 6

int main(void)
{
    for (int i = N; i >= 1; --i) {
        // εκτυπώνουμε τα πρώτα κενά
        for (int j = 1; j < i; ++j)
            putchar(' ');

        // μετά τα αστέρια αριστερά του μέσου (μαζί και το μεσαίο)
        for (int j = N; j >= i; --j)
            putchar('*');

        // και τέλος όλα τα αστέρια αριστερά του μέσου
        for (int j = N; j >= i + 1; --j)
            putchar('*');

        putchar('\n');
    }

    return 0;
}