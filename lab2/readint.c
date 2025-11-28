/* File: readint.c */

#include <stdio.h>

int main() {
  int number;

  printf("Please give me a number: ");
  scanf("%d", &number);

  printf("I just read this number: %d\n", number);
  return 0;
}

/*
    Απαντήσεις
    1) Τι συμβαίνει αν αντί για αριθμό δώσετε μια λέξη ή μια κενή γραμμή;
        
    2) Τι συμβαίνει αν αντί για αριθμό πληκτρολογήσουμε Ctrl+D (EOF);

    3) Τι θα συμβεί αν τυπώσουμε την μεταβλητή number πριν την διαβάζουμε;

    4) Γιατί να μην δώσουμε μια σταθερά τιμή στην μεταβλητή number στο πρόγραμμά 
    μας - γιατί να ζητήσουμε από τον χρήστη να δώσει μια τιμή;

    5) Αν χρειαζόταν να διαβάσετε έναν αριθμό κινητής υποδιαστολής, πως θα το κάνατε;
        int number -> float number
        scanf("%d", &number); -> scanf("%f", &number);
        printf("I just read this number: %d\n", number); -> printf("I just read this number: %f\n", number);
*/