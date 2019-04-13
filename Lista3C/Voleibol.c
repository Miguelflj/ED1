#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[50];
    float totalB=0, totalS=0,totalA=0;
    int auxB, auxS, auxA;
    float pontoB=0,pontoS=0,pontoA=0;
    float porB,porS,porA;
    int jogadores,i;

    scanf("%d",&jogadores);

    for(i=0; i<jogadores; i++){
        scanf("%*c");
        scanf("%[^\n]", nome);
        scanf("%*c");

        scanf("%d %d %d",&auxS,&auxB,&auxA);
        scanf("%*c");
        totalS = totalS + auxS;
        totalB = totalB + auxB;
        totalA = totalA + auxA;

        scanf("%d %d %d",&auxS,&auxB,&auxA);
        
        pontoS = pontoS + auxS;
        pontoB = pontoB + auxB;
        pontoA = pontoA + auxA;

    }
    
    porS = ((pontoS/totalS)*100.0);
    porB = ((pontoB/totalB)*100.0);
    porA = ((pontoA/totalA)*100.0);

    printf("Pontos de Saque: %.2f ", porS);
    puts("%.");
    printf("Pontos de Bloqueio: %.2f ", porB);
    puts("%.");
    printf("Pontos de Ataque: %.2f ", porA);
    puts("%.");

    return 0;
}