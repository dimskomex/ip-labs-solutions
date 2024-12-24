#ifndef STRING_H
#define STRING_H

// Δήλωση της συνάρτησης mystrlen που υπολογίζει το μήκος μιας συμβολοσειράς
int mystrlen(char *str);

// Δήλωση της συνάρτησης mystrcat που προσαρτά μια συμβολοσειρά στο τέλος μιας
// άλλης
char *mystrcat(char *s1, char *s2);

// Δήλωση της συνάρτησης strtok_example για να εκτυπώσουμε τις λέξεις από τη
// συμβολοσειρά χωρίς στίξη
void strtok_example(char *str);

#endif  // STRING_H
