
#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int main(){
    double valor, vet[TAM];
    int i;
    scanf("%lf", &valor);
    vet[0] = valor;
    for(i=1;i<TAM;i++){
        vet[i] = (vet[i-1]/2);


    }
    for(i=0;i<TAM;i++){
        printf("N[%d] = %0.4lf\n",i ,vet[i]);
    }


    return 0;
}