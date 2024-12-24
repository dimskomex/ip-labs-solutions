#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main(int argc, char *argv[]) {
  // Έλεγχος σωστού αριθμού ορισμάτων
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <moves>\n", argv[0]);
    return 1;
  }

  // Ανάγνωση διάστασης πλέγματος
  int N;
  if (scanf("%d", &N) != 1 || N <= 0 || N > MAX_SIZE) {
    fprintf(stderr, "Error: Invalid grid size\n");
    return 1;
  }

  // Δήλωση και αρχικοποίηση του πλέγματος
  char grid[MAX_SIZE][MAX_SIZE];
  memset(grid, ' ', sizeof(grid));

  // Ανάγνωση πλέγματος από την πρότυπη είσοδο
  int pacman_x = -1, pacman_y = -1;
  int pacman_count = 0;
  for (int i = 0; i < N; i++) {
    char line[256];
    if (!fgets(line, sizeof(line), stdin)) {
      fprintf(stderr, "Error: Not enough lines in input\n");
      return 1;
    }
    int len = strlen(line);
    int col = 0;
    for (int j = 0; j < len && col < N; j++) {
      if (line[j] == '.' || line[j] == 'P') {
        grid[i][col] = line[j];
        if (line[j] == 'P') {
          pacman_x = i;
          pacman_y = col;
          pacman_count++;
        }
        col++;
      }
    }
  }

  // Έλεγχος ύπαρξης ακριβώς ενός Pacman
  if (pacman_count != 1) {
    fprintf(stderr, "Error: There must be exactly one 'P' in the grid\n");
    return 1;
  }

  // Επεξεργασία κινήσεων
  char *moves = argv[1];
  int moves_len = strlen(moves);
  for (int i = 0; i < moves_len; i++) {
    char move = moves[i];
    // Διαγραφή παλιάς θέσης Pacman
    grid[pacman_x][pacman_y] = '.';
    if (move == 'U') {
      pacman_x = (pacman_x - 1 + N) % N;
    } else if (move == 'D') {
      pacman_x = (pacman_x + 1) % N;
    } else if (move == 'L') {
      pacman_y = (pacman_y - 1 + N) % N;
    } else if (move == 'R') {
      pacman_y = (pacman_y + 1) % N;
    } else {
      fprintf(stderr, "Error: Invalid move '%c' in moves\n", move);
      return 1;
    }
    // Ενημέρωση θέσης Pacman
    grid[pacman_x][pacman_y] = 'P';
  }

  // Εκτύπωση τελικής κατάστασης του πλέγματος
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      putchar(grid[i][j]);
    }
    putchar('\n');
  }

  return 0;
}

// Μεταγλώττιση:
// gcc pacman.c -o pacman
// Εκτέλεση:
// ./pacman RRD < level.txt
// ./pacman RRDDLL < level.txt
// ./pacman RRDDLLUU < level.txt
// ./pacman RRDDLLUULLLL < level.txt