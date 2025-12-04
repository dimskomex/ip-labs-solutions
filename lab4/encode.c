#include <stdio.h>

int main() {
    int c;
    c = getchar();

    while (c != EOF) {
        printf("%2x", c);
        c = getchar();
    }
    return 0;
}