#include <stdio.h>
#include <stdlib.h>



int main(){
    int i,teste,output=1;;
    int comp,flag=0,q;
    scanf("%d",&q);
    scanf("%d",&comp);
    scanf("%d", &teste);
    if(comp > teste){
        flag = 1;
        comp = teste;
    }else if(comp < teste){
        flag = 0;
        comp = teste;
    }else{
        output = q = 0;
    }
        
    for(i=1; i < q-1; i++){
        scanf("%d", &teste);
        if(flag == 0){
            if(comp > teste){
                flag = 1;
            }else{
                output = 0;
                i = q;
            }
            
        }else{
            if(comp < teste){
                flag = 0;
            }else{
                output = 0;
                i = q;
            }
        }
    

        comp = teste;
    
    }
    printf("%d\n", output);

    return 0;
}