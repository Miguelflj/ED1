


#include <stdio.h>
#include <stdlib.h>


int main(){
    int a, b, aux, soma=0, i;
    scanf("%d", &a);
    scanf("%d", &b);
    if(a > b){
        aux = b;
        b = a;
        a = aux;
    }
    for(i=a+1; i < b;i++){
        if(i%2 != 0){
            soma = soma + i;

        }
    }
        
    printf("%d\n", soma);




return 0;
}