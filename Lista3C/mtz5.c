

#include <stdio.h>
#include <stdlib.h>



int main(){
        int n,i,quad,quad2,j,x,y;
        int **mtz;
        
        while(scanf("%d",&n) != EOF){
            mtz = (int**)(malloc(n*sizeof(int*)));
            for(i=0; i < n; i++){
            mtz[i] = (int*)(malloc(n*sizeof(int)));
            }
            quad = (n/3);
            quad2 = (n-quad-quad);
            
            
            for(i=0; i < n; i++){
                for(j=0; j < n; j++){
                    if(i == j){
                    mtz[i][j] = 2;
                    }
                    if(i + j == n-1){
                        mtz[i][j] = 3;
                    }
                    if(i == j && i + j == n-1){
                            mtz[i][j] = 4;
                    }
                }
                
            }
            for(i=quad,y=1; y <= quad2; i++,y++){
                for(j=quad,x=1; x <= quad2; j++,x++){
                    if(i == j && i + j == n-1){
                    }else{
                        mtz[i][j] = 1;
                    }
                }
            }
            
                
            for(i=0; i < n; i++){
                for(j=0; j < n; j++){
                    printf("%d",mtz[i][j]);
                }
                puts("");
            }
            puts("");

        }




    return 0;
}