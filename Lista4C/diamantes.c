

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[1000];
    int i, n,contIn, contFim,output,j,tam;
    
    scanf("%d",&n);
    for(i=0; i < n; i++){
        contIn = 0;
        contFim = 0;
        scanf("%s",input);
        scanf("%*c");
        tam = strlen(input);
        for(j=0; j < tam; j++){
            if((input[j]) == ('<')){
                contIn++;
               // printf("< conta -%d\n", contIn);
            
            }else if(input[j] == '>'){
                    contFim++;
                   // printf("> conta -%d\n", contFim);
            }
            if(contFim > contIn){
                contFim--;
            }
            
        }
        if(contIn > contFim){
            output = contFim;
        }else{
            output = contIn;
        }
        
        printf("%d\n", output);
    }

    return 0;
}