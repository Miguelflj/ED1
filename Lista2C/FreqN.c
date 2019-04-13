

#include <stdio.h>
#include <stdlib.h>


int main(){
    int *vet;
    int comp,cont;
    int i,j,n,aux;
    

        
    scanf("%d", &n);
    vet = (int*)(malloc(n*sizeof(int)));
    for(i=0; i < n ; i++){
        scanf("%d", &vet[i]);

    }
    for(j=n-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vet[i] > vet[i+1]){
                            aux = vet[i];
                            vet[i] = vet[i+1];
                            vet[i+1] = aux;
                        }
                }
    }
    for(i=0; i < n ; i++){
         
            cont=0;
            if(vet[i] != -1){
                comp = vet[i];
                for(j=i; j < n ; j++){
                        if(comp == vet[j]){
                            vet[j] = -1;
                            cont++;
                        }
                    }
                printf("%d aparece %d vez(es)\n",comp,cont);
            }
           
    }
    return 0;
}