#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// Συνάρτηση για υπολογισμό του κόστους (Μανχάταν απόσταση)
int calculate_cost(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
  int N, i, j, x, y;
  int snow_piles[MAX_N][2];  // Θέσεις των σωρών χιονιού
  int min_cost = -1;
  int best_x = -1, best_y = -1;

  // Διαβάζουμε το μέγεθος του κήπου
  if (scanf("%d", &N) != 1) {
    fprintf(stderr, "Error reading garden size\n");
    return 1;
  }

  // Διαβάζουμε τις συντεταγμένες των σωρών χιονιού
  i = 0;
  while (scanf("%d %d", &x, &y) == 2) {
    if (i >= MAX_N) {
      fprintf(stderr, "Too many snow piles\n");
      return 1;
    }
    snow_piles[i][0] = x;
    snow_piles[i][1] = y;
    i++;
  }

  // Υπολογίζουμε το κέντρο του κήπου
  double center_x = (N - 1) / 2.0;
  double center_y = (N - 1) / 2.0;

  // Υπολογίζουμε το συνολικό κόστος για κάθε θέση (tx, ty) στον κήπο
  for (int tx = 0; tx < N; tx++) {
    for (int ty = 0; ty < N; ty++) {
      int total_cost = 0;

      // Υπολογίζουμε το κόστος από κάθε σωρό στην θέση (tx, ty)
      for (int k = 0; k < i; k++) {
        total_cost +=
            calculate_cost(tx, ty, snow_piles[k][0], snow_piles[k][1]);
      }

      // Ελέγχουμε αν το τρέχον κόστος είναι το μικρότερο
      if (min_cost == -1 || total_cost < min_cost) {
        min_cost = total_cost;
        best_x = tx;
        best_y = ty;
      }
      // Αν το κόστος είναι ίδιο, επιλέγουμε τη θέση που είναι πιο κοντά στο
      // κέντρο
      else if (total_cost == min_cost) {
        double current_distance =
            sqrt(pow(tx - center_x, 2) + pow(ty - center_y, 2));
        double best_distance =
            sqrt(pow(best_x - center_x, 2) + pow(best_y - center_y, 2));
        if (current_distance < best_distance) {
          best_x = tx;
          best_y = ty;
        }
      }
    }
  }

  // Εκτύπωση του αποτελέσματος
  printf(
      "We will position the snowman on (%d, %d) with a minimum cost of %d.\n",
      best_x, best_y, min_cost);

  return 0;
}

// Μεταγλώττιση:
// gcc olaf.c -o olaf -lm
// Εκτέλεση:
// ./olaf < map.txt
// We will position the snowman on (4, 4) with a minimum cost of 22.