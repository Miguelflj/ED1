
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j,p;
    int total;
    int inL,inC,max;
    int **mtz;
    int inicia=1,cont=1;
    scanf("%d %d %d", &n,&inL,&inC);
    max = (n*n);
    //aloca mtz tamanho n x n
    mtz = (int**)(malloc(n*sizeof(int*)));
    for(i=0; i < n; i++){
        mtz[i] = (int*)(malloc(n*sizeof(int)));
    }
    

    for(i=0; i < n; i++){
        for(j=0; j < n; j++){
            mtz[i][j] = inicia;
            inicia++;
        }
    }
    
    printf ( "%d", mtz[inL][inC] );
    p=1;
    total=1;
    while(total < max){
            // direita
            for(i=0; i < p; i++){
                if(total < max){
                    cont++;
                    inC++;
                    if(inC >= 0 && inL >=0 && inC < n && inL < n){
                        printf(" %d", mtz[inL][inC]);
                        total++;
                    }
                }
            }
            
            // baixo
            for(i=0; i < p; i++){
                if(total < max){
                    cont++;
                    inL++;
                    if(inC >= 0 && inL >=0 && inC < n && inL < n){
                        printf(" %d", mtz[inL][inC]);
                        total++;
                    }
                }
            }
            p++;
            
            // esquerda
            for(i=0; i < p; i++){
                if(total < max){
                    cont++;
                    inC--;
                    if(inC >= 0 && inL >=0 && inC < n && inL < n){
                        printf(" %d", mtz[inL][inC]);
                        total++;
                    }
                }
            }
            // cima
            for(i=0; i < p; i++){
                if(total < max){
                    cont++;
                    inL--;
                    if(inC >= 0 && inL >=0 && inC < n && inL < n){
                        printf(" %d", mtz[inL][inC]);
                        total++;
                    }
                }
            }
            
        
            
        p++;
    }
    printf("\n%d\n",cont);

    return 0;
}