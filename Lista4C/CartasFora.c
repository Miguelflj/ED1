#include <stdio.h>
#include <stdlib.h>




typedef struct tipoPilha{
    int Pilha[50];
    int qtd;
    
    
}tipoPilha;

void Empilha(tipoPilha *pilhaVet,int valor){
    int i;
    if((pilhaVet)->qtd < 50){
       (pilhaVet)->Pilha[(pilhaVet)->qtd] = valor;
       (pilhaVet)->qtd++;
   
    }
    
}
int Desempilha(tipoPilha *pilhaVet){
    int i,valor;
    if((pilhaVet)->qtd > 0){
        valor = (pilhaVet)->Pilha[((pilhaVet)->qtd-1)];
        (pilhaVet)->Pilha[(pilhaVet)->qtd-1] = -1;
        (pilhaVet)->qtd--;
        return valor;
        
    }
    
}

/*
void ImprimePilha(tipoPilha *pilhaVet){
    int i;
    for(i=(pilhaVet)->qtd-1; i>-1; i--){
            printf("[%d]\n", (pilhaVet)->Pilha[i]);
    }
    
    
}
*/
int main(){
    int i, n,descarte, valor;
    tipoPilha pilhaVet;
    int j;
    scanf("%d",&n);
    while(n != 0){
        pilhaVet.qtd = 0;
        for(i=n; i >= 1; i--){
            Empilha(&pilhaVet,i);
        }
        if(n == 1)
            printf("Discarded cards:\n");
        else
             printf("Discarded cards: ");
        for(i=0; i < n-1; i++){
            if(pilhaVet.qtd >= 2){
                descarte = Desempilha(&pilhaVet);
                valor = (pilhaVet).Pilha[(pilhaVet).qtd -1];
                for(j=(pilhaVet).qtd;j>0;j--){
                    (pilhaVet).Pilha[j] = (pilhaVet).Pilha[j-1];
                }
                (pilhaVet).Pilha[0] = valor;
                if(i != (n-2)){
                    printf("%d, ", descarte);
                }else{
                    printf("%d\n", descarte);
                }
                
            }
        
        }
        printf("Remaining card: %d\n",pilhaVet.Pilha[0]);  
            
       scanf("%d",&n);     
    }
        
    return 0;
}