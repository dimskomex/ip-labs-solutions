#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    char **p = malloc(n * sizeof(char*));
    for (int i = 0; i < n; ++i)
        p[i] = malloc(m * sizeof(char));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            scanf("%c", &p[i][j]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%c", p[i][j]);
        
        printf("\n");
    }
    
    int count[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            count[i][j] = 0;
    }

    // από τους πιο άσχημους κώδικες που έχω γράψει.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) {
                if (j == 0) {
                    if (p[i][j + 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j + 1] == '*')
                        ++count[i][j];

                } else if (j == m - 1) {
                    if (p[i][j - 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j - 1] == '*')
                        ++count[i][j];
                } else {
                    if (p[i][j - 1] == '*')
                        ++count[i][j];

                    if (p[i][j + 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j + 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j - 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j] == '*')
                        ++count[i][j];
                }
            } else if (i == n - 1) {
                if (j == 0) {
                    if (p[i][j + 1] == '*')
                        ++count[i][j];

                    if (p[i - 1][j + 1] == '*')
                        ++count[i][j];
                } else if (j == m - 1) {
                    if (p[i][j - 1] == '*')
                        ++count[i][j];

                    if (p[i - 1][j - 1] == '*')
                        ++count[i][j];
                } else {
                    if (p[i - 1][j - 1] == '*')
                        ++count[i][j];

                    if (p[i - 1][j + 1] == '*')
                        ++count[i][j];

                    if (p[i - 1][j] == '*')
                        ++count[i][j];

                    if (p[i][j - 1] == '*')
                        ++count[i][j];

                    if (p[i][j + 1] == '*')
                        ++count[i][j];
                }
            } else {
                if (j == 0) {
                    if (p[i][j + 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j + 1] == '*')
                        ++count[i][j];
                } else if (j == m - 1) {
                    if (p[i][j - 1] == '*')
                        ++count[i][j];

                    if (p[i + 1][j - 1] == '*')
                        ++count[i][j];

                    if (p[i - 1][j - 1] == '*')
                        ++count[i][j];
                } else {
                    if (p[i][j - 1] == '*')
                    ++count[i][j];

                    if (p[i + 1][j - 1] == '*')
                        ++count[i][j];

                    if (p[i][j + 1] == '*')
                            ++count[i][j];

                    if (p[i + 1][j + 1] == '*')
                        ++count[i][j];
                }

                if (p[i + 1][j] == '*')
                    ++count[i][j];

                if (p[i - 1][j] == '*')
                    ++count[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            p[i][j] != '*' ? printf("%d", count[i][j]) : printf("*");
        
        printf("\n");
    }

    for (int i = 0; i < n; ++i)
        free(p[i]);

    free(p);
    return 0;
}