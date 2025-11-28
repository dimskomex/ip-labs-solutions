#include <stdio.h>

int main() {
    int c;
    while(scanf("%02x", &c) > 0) {
        putchar(c);
    }
    putchar(10);
    return 0;
}