

#include <stdio.h>
#include <stdio.h>

int main(){
    int tipoComb, contG=0, contA=0, contD=0,bool=0;
    
    while(bool == 0){
        do
        {
        scanf("%d", &tipoComb);

        }while(tipoComb < 1 && tipoComb > 4);
        if(tipoComb == 4){
            bool = 1;
        }
        if(tipoComb == 1){
            contA++;
        }
        if(tipoComb == 2){
            contG++;
        }
        if(tipoComb == 3){
            contD++;
        }

    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", contA);
    printf("Gasolina: %d\n", contG);
    printf("Diesel: %d\n", contD);
return 0;
}