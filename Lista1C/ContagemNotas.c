#include <stdio.h>
#include <stdlib.h>
//nota de 100, 50, 20, 10, 5, 2 e 1

int main(){
    int valor, i, valorAux;
    int cont100=0, cont50=0, cont20=0, cont10=0, cont5=0, cont2=0, cont1=0;
    scanf("%d", &valor);
    valorAux = valor;
    while(valor>=100){
        valor = valor - 100;
        cont100++;
            
    }
    while(valor>=50){
        valor = valor - 50;
        cont50++; 

    }
    while(valor>=20){
        valor = valor - 20;
        cont20++;
    
    }
    while(valor>=10){
        valor = valor - 10;
        cont10++;

    }
    while(valor>=5){
        valor = valor -5;
        cont5++;
    
    }
    while(valor>=2){
        valor = valor -2;
        cont2++;

    }
    while(valor>=1){
        valor = valor -1;
        cont1++;

    }
    
    printf("%d\n", valorAux);
    printf("%d nota(s) de R$ 100,00\n", cont100);
    printf("%d nota(s) de R$ 50,00\n", cont50);
    printf("%d nota(s) de R$ 20,00\n", cont20);
    printf("%d nota(s) de R$ 10,00\n", cont10);
    printf("%d nota(s) de R$ 5,00\n", cont5);
    printf("%d nota(s) de R$ 2,00\n", cont2);
    printf("%d nota(s) de R$ 1,00\n", cont1);


return 0;
}