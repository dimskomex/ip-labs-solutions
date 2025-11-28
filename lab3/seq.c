#include <stdio.h>
#include <math.h>

int sum() {
    int i = 1, sum = 0;
    while (i <= 100) {
        sum += i;
        i++;
    }

    return sum;
}

float basel() {
    int i = 1;
    float sum = 0;
    
    for (i; i <= 100; i++) {
        sum += 1.0/(i*i);
    }

    return sum;
}

double pi_approx() {
    return sqrt(6*basel());
}

long double pi_approx2() {
    int i = 1;
    long double sum = 0;
    while (1.0/(i*i) >= 0.000000000000001) {
        sum += 1.0/(i*i);
        i++;
    }

    return sqrt(6*sum);
}

void eta_two() {
    int sign = 1, am;
    float sum = 0;
    printf("Give amount of digits: ");
    scanf("%d", &am);

    for (int i = 1; i <= am; i++) {
        sum += sign * 1.0/(i*i);
        sign *= (-1);
    }

    printf("eta two: %f\n", sum);
}

float harmonic() {
    int i = 1, sign = 1;
    float sum = 0;
    
    for (i; i <= 100; i++) {
        sum += sign * 1.0/i;
        sign *= (-1);
    }

    return sum;
}

float liebniz() {
    int i = 1, sign = 1;
    float sum = 0;
    
    for (i; i <= 100; i+=2) {
        sum += sign * 1.0/i;
        sign *= (-1);
    }

    return sum;
}

float zeta_four() {
    int i = 1;
    float sum = 0;
    
    for (i; i <= 100; i++) {
        sum += 1.0/(i*i*i*i);
    }

    return sum;
}

float wallis() {
    int num = 2, den = 1;
    float sum = 1;
    for (int i = 1; i <= 100; i++) {
        sum *= (float)num/den;
        if (num > den) {
            den += 2;
        } else {
            num += 2;
        }
    }

    return sum;
}

int main() {
    printf("sum: %d\n", sum());
    printf("basel: %f\n", basel());
    printf("pi approx: %f\n", pi_approx());
    printf("pi_approx 2: %0.8Lf\n", pi_approx2());
    eta_two();
    printf("harmonic: %f\n", harmonic());
    printf("zeta four: %f\n", zeta_four());
    printf("liebniz: %f\n", liebniz());
    printf("wallis: %f\n", wallis());
    return 0;
}