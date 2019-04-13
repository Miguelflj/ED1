#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12

int main(){
    int i, j, cont=0;
    char op;
    double media, soma=0, mtz[TAM][TAM];
    scanf("%c%*c", &op);

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            scanf("%lf", &mtz[i][j]);
            
        }
    
    }
    
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(j > i && (i + j) > 11){
                soma = soma + mtz[i][j];
                cont++;
            }
            
        }
    }
    
    
    if(op == 'S'){
        printf("%.1lf\n", soma);
    }
    if(op == 'M'){
        printf("%.1lf\n", soma/cont);
    
    }


    return 0;
}