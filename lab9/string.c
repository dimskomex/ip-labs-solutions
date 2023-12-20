#include <stdio.h>
#include <string.h>

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
    char strA[80] = "This is a string.";
    char strB[80] = "This is another string.";
    // strcpy(strA, strB);
    mystrcat(strA, strB);

    printf("1st string: %d\n", mystrlen(strA));
    printf("2st string: %ld\n", strlen(strB));

    printf("strA %s strB\n", !strcmp(strA, strB) ? "==" : strcmp(strA, strB) > 0 ? ">" : "<");

    for (char *p = strtok(strB, ",."); p != NULL; p = strtok(NULL, ",."))
        printf("%s\n", p);

    return 0;
}