
#include <stdio.h>
#include <stdlib.h>

int main(){
    char vendedor;
    double salariofix, vendastotal, comissao;
    scanf("%s", &vendedor);
    scanf("%lf", &salariofix);
    scanf("%lf", &vendastotal);
    comissao = (salariofix + ((vendastotal* 15.0)/100));
    printf("TOTAL = R$ %0.2lf\n", comissao);




return 0;
}