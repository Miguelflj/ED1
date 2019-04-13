#include <stdio.h>
#include <stdlib.h>

#include <time.h>

//define constante
#define TAM 10

int main(){
        // Declara matriz 10x10
        int i, j;
        int mtz[TAM][TAM];

        // inicializa a semente dos sorteios
        srand(time(NULL));
        //srand(1);
        

        for(i=0; i<TAM; i++){
            for(i=0; j<TAM; j++){
                mtz[i][j] = rand() % 100;
                
            }

        }

        for(i=0; i<TAM; i++){
            for(i=0; i<TAM; i++){
                printf("linha: (%d) \ caluna: (%d) \ [%d]", i, j, mtz[i][j]);
                
            }
            printf("\n");
        }

return 0;
}