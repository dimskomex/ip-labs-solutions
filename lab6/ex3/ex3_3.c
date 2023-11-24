/*
    Αν καταλάβεις τα δύο προηγούμενα προγράμματα η λύση εδώ είναι πολύ απλή.
    Οπότε πάρε μια "μικρή" ως προς τις γραμμές κώδικα λύση.
*/

#include <stdio.h>

int main(void)
{ 
    for (int ch = getchar(); ch != EOF; ch = getchar()) {
        ch = (ch >= 'A' && ch <= 'Z') ? ch + ('a' - 'A') : (ch >= 'a' && ch <= 'z') ? ch - ('a' - 'A') : ch;
        putchar(ch);
    }

    return 0;
}