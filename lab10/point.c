#include <stdio.h>

// Κλασσικά, ένα σημείο στον δισδιάστατο χώρο χρειάζεται ένα x και ένα y.
struct point {
	double x;
	double y;
};

// Όπως μια συνάρτηση τύπου int πρέπει να επιστρέψει έναν ακέραιο,
// έτσι κι εδώ μια συνάρτηση τύπου struct point πρέπει να επιστρέψει ένα σημείο.
struct point middle(struct point a, struct point b)
{
	struct point m;
	m.x = (a.x + b.x) / 2;
	m.y = (a.y + b.y) / 2;

	return m;
}

int main(void)
{
	struct point p1;
	p1.x = 1.2;
	p1.y = 5.4;

	// Ένας άλλος τρόπος για να γεμίσουμε με δεδομένα ενός struct είναι αυτός εδώ,
	// στο p2.x θα βάλει το 7.3 και στο p2.y το 1.8.
	struct point p2 = {7.3, 1.8};

	struct point mid = middle(p1, p2);
	printf("%f %f\n", mid.x, mid.y);
	return 0;
}
