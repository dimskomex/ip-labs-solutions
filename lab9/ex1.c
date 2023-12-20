#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *str)
{
    int len;
    for (len = 0; str[len] != '\0'; ++len);         // Μην ξεχνάς: ένα string είναι ένας πίνακας χαρακτήρων!

    return len;
}

char *mystrcat(char *s1, char *s2)
{
    int offset = mystrlen(s1);
    
    int i;
    for (i = 0; i < mystrlen(s2); ++i)
        s1[offset + i] = s2[i];

    s1[offset + i] = '\0';
    return s1;
}

int main(void)
{
    char str[BUFSIZ] = "This is a string";
    printf("%d\n", mystrlen(str));

    printf("%s\n", mystrcat(str, "This is another string"));
    printf("The new len is: %d\n", mystrlen(str));

    return 0;
}
