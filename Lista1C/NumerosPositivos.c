



#include <stdio.h>
#include <stdlib.h>


int main(){
    int i=0, cont=0;
    float  valores;
    while(i<=5){
        scanf("%f", &valores);
        if(valores > 0){
            cont++;
        }
        i++;
    }
    printf("%d valores positivos\n", cont);

return 0;
}