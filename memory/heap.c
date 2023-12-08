#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 2

// Γεμίζει έναν δισδιάστατο πίνακα n * m με: τον τρέχοντα χρόνο σε δευτερόλεπτα από την 1η Ιανουαρίου 1970.
// Κάθε στοιχείο του πίνακα διαφέρει κατά 1 δευτερόλεπτο. Αν array[0][0] == x, τότε array[0][1] == x + 1, array[0][2] == x + 2 κοκ.
// Η συνάρτηση πρέπει να διαρκεί παραπάνω από n * m seconds.
// Αν ο πίνακας είναι κενός ή δεν είναι σωστά τα n, m με τις γραμμές και τις στύλες του πίνακα,
// η συμπεριφορά της συνάρτησης είναι μη προσδιορισμένη (undefined behaviour).
void add_data(int **array, int n, int m);

int main(void)
{
    int **p = malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i)
        p[i] = malloc(M * sizeof(int));

    add_data(p, N, M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            printf("%d\t", p[i][j]);

        printf("\n");
    }

    free(p);
    return 0;
}