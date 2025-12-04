#include <stdio.h>

int main() {
    int lines;
    printf("Give number of lines: ");
    scanf("%d", &lines);

    /* 2.1 */
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j <= i; j++) {
            putchar('*');
        }

        // ASCII τιμή για νέα γραμμή
        putchar(10);
    }

    /* 2.2 */
    for (int i = 0; i < lines; i++) {

        int t = i*2;
        for (int j = 1; j <= t - 1; j++) {
            putchar('*');
        }

        putchar(10);
    }

    /* extra */
    int rate;
    printf("Give increment rate: ");
    scanf("%d", &rate);

    for (int i = 0; i < lines; i++) {

        if (i == 0) {
            putchar('*');
            putchar(10);
            continue;
        }

        int t = i*rate + 1;
        for (int j = 0; j < t - 1; j++) {
            putchar('*');
        }

        putchar(10);
    }

    return 0;
}