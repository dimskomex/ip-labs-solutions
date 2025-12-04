#include <stdio.h>
#include <math.h>

int main() {
    /*kane logout next time re bro*/
    float n1, n2;

    printf("Please enter the length of the first side: ");
    scanf("%f", &n1);

    printf("\nPlease enter the length of the second side: ");
    scanf("%f", &n2);

    printf("\nThe area of the triange: %f\n", (n1 + n2)/2);
    printf("The perimeter of the triangle is: %f\n", n1 + n2 + sqrt(n1*n1 + n2*n2));
    return 0;
}