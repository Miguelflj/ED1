

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12

int main(){
    int linha, i, j;
    char op, lixo;
    double media, soma=0, mtz[TAM][TAM];
    scanf("%d%c", &linha, &lixo);
    scanf("%c", &op);

    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            scanf("%lf", &mtz[i][j]);
            
        }
    
    }
    
    for(i=0;i<TAM;i++){
        soma = soma + mtz[linha][i];            
        }
    
    
    if(op == 'S'){
        printf("%.1lf\n", soma);
    }
    if(op == 'M'){
        printf("%.1lf\n", soma/TAM);
    
    }


    return 0;
}