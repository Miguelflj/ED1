

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam, *vet, i;
    scanf("%d", &tam);
    vet = (int*)(malloc(tam*sizeof(int)));
    
    for(i=0;i<tam;i++){
        scanf("%d", &vet[i]);


    }
    for(i=0;i<tam;i++){
        printf("funfouuuu: %d\n", vet[i]);

    }



return 0;
}