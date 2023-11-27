#include <stdio.h>
#include <math.h>

int main() {

    int t; 
    double i, A;

    scanf("%d", &t); 
    scanf("%lf", &A);
    scanf("%lf", &i);

    for (int mes = 1; mes <= t; ++mes) {
        double V = A * (1 + i) * (pow(1 + i, mes) - 1) / i;
        printf("Montante ao fim do mes %d: R$ %.2f\n", mes, V);
    }

    return 0;
}