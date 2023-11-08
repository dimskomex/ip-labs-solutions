/*  
    κάνουμε compile γράφοντας στο terminal: gcc -o ex2_1 ex2_1.c
    τρέχουμε το πρόγραμμα μας γράφοντας στο terminal: ./ex2_1
*/

#include <stdio.h>

unsigned long long collatz(unsigned long long n)
{
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

int main()
{
    printf("%lld\n", collatz(20));       /* 20 άρτιος, άρα πρέπει να εκτυπώσει 20 / 2 = 10 */
    printf("%lld\n", collatz(11));       /* 11 περιττός, άρα πρέπει να εκτυπώσει 11 * 3 + 1 = 34 */
    return 0;
}
