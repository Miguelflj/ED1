

#include <stdio.h>
#include <stdlib.h>



int main(){
    int n, **mtz, i, j,cont,tam,y;
    do{
        scanf("%d",&n);
        cont=0;
        mtz = (int**)(malloc(n*sizeof(int*)));
        for(i=0; i < n; i++){
            mtz[i] = (int*)(malloc(n*sizeof(int)));
        }
        tam = n;
        for(i=0; i < n; i++){
            for(j=0; j < tam; j++){
                    mtz[j+cont][j] = mtz[j][j+cont] = cont+1;
                    
            }
            cont++;
            tam--;
            
        }
        for(i=0; i < n; i++){
            for(j=0; j < n; j++){
                
               if(mtz[i][j] < 10){
                   if(j == 0){
                    printf("  %d",mtz[i][j]);
                   }else{
                       printf("   %d",mtz[i][j]);
                   }
               }else if(mtz[i][j] < 100){
                   if(j == 0){
                    printf(" %d",mtz[i][j]);
                   }else{
                       printf("  %d",mtz[i][j]);
                   }
               }else if(mtz[i][j] < 1000){
                   if(j == 0){
                    printf("%d",mtz[i][j]);
                   }else{
                       printf(" %d",mtz[i][j]);
                   }
               }
            }   
            puts("");
        }
        
        
        if(n != 0){
            puts("");
        
        }else{
        }
        
    }while(n != 0);
    


    return 0;
}