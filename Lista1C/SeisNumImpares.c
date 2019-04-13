#include <stdio.h>
#include <stdlib.h>



int main(){
    int valor, i;
    scanf("%d", &valor);
    if((valor % 2) != 0){
        for(i=0;i<6;i++){
        printf("%d\n", valor);
        valor = valor + 2;

        }
    }
    else if((valor%2) == 0){
    valor = valor + 1;
    for(i=0;i<6;i++){
        printf("%d\n", valor);
        valor = valor + 2;
    }


    }

return 0;
}