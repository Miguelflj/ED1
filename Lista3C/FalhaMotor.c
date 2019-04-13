#include <stdio.h>
#include <stdlib.h>



int main(){
    int tam, *vet, i;
    int comp, pos;
    scanf("%d", &tam);
    vet = (int*)(malloc(tam*sizeof(int)));
    for(i=0;i<tam;i++){
        scanf("%d",&vet[i]);
    }
    comp = vet[0];
    for(i=1;i<tam;i++){
        if(comp <= vet[i]){
            pos = 0;
            comp = vet[i];
        }else{
            pos = (i+1);
            i = tam;
        }


    }
    printf("%d\n", pos);





    return 0;
}