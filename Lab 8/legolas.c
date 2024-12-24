#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για να βρει και να εκτυπώσει όλους τους συνδυασμούς 3 υποψηφίων
void find_combinations(long long goal, long long *candidates,
                       int num_candidates) {
  int found = 0;

  for (int i = 0; i < num_candidates - 2; i++) {
    for (int j = i + 1; j < num_candidates - 1; j++) {
      for (int k = j + 1; k < num_candidates; k++) {
        if (candidates[i] + candidates[j] + candidates[k] == goal) {
          printf("Candidates combination found: %lld + %lld + %lld = %lld\n",
                 candidates[i], candidates[j], candidates[k], goal);
          found = 1;
        }
      }
    }
  }

  if (!found) {
    printf("No combination of candidates leads to %lld\n", goal);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 5) {
    fprintf(stderr,
            "Usage: %s <goal> <candidate1> <candidate2> ... <candidateN>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  long long goal = atoll(argv[1]);
  int num_candidates = argc - 2;
  long long *candidates = malloc(num_candidates * sizeof(long long));

  if (candidates == NULL) {
    perror("Error allocating memory");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_candidates; i++) {
    candidates[i] = atoll(argv[i + 2]);
  }

  find_combinations(goal, candidates, num_candidates);

  free(candidates);
  return EXIT_SUCCESS;
}

// Μεταγλώττιση:
// gcc legolas.c -o legolas
// Εκτέλεση:
// ./legolas 42 19 21 3 5 12
// ./legolas 42 19 21 3 5 12 11
// ./legolas 42 27 25 12 31 5 26 40 34 3 18
// ./legolas 37372082074 9238742398 82934723 27893492387 127863435 239847289