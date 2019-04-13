
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aux{
    int pos;
    int tam;
}Aux;

int main(){
    char dic[50][50];
    char fim;
    int n,i,j;
    int h,g;
    int tam;
    Aux aux[50];
    Aux ajudaNois;
    scanf("%d", &n);
    
    for(h=0; h < n; h++){
        j=0;
        do{
            scanf("%s%c", dic[j],&fim);
            aux[j].tam = strlen(dic[j]);
            aux[j].pos = j;
            j++;

        }while(fim != '\n');
            
        tam = j;
        // francisco sort
        for(j=j-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(aux[i].tam < aux[i+1].tam){
                            ajudaNois = aux[i];
                            aux[i] = aux[i+1];
                            aux[i+1] = ajudaNois;
                        }
                }
        }
        
	for(i=0;i<tam;i++){
            if(i == tam -1)
                printf("%s\n",dic[aux[i].pos]);
            else
                printf("%s ",dic[aux[i].pos]);
        }
    }

    return 0;
}