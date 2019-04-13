

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct tipoPilha{
    int Pilha[MAX];
    int qtd;
    
    
}tipoPilha;

// opção 1
void Empilha(tipoPilha *pilhaVet,int valor){
    int i;
    if((pilhaVet)->qtd < MAX){
       (pilhaVet)->Pilha[(pilhaVet)->qtd] = valor;
       (pilhaVet)->qtd++;
    }else{
        puts("Pilha cheia");
    }
    
    
}
// opção 2
int Desempilha(tipoPilha *pilhaVet){
    int i,valor;
    if((pilhaVet)->qtd > 0){
        valor = (pilhaVet)->Pilha[((pilhaVet)->qtd-1)];
        (pilhaVet)->Pilha[(pilhaVet)->qtd-1] = -1;
        (pilhaVet)->qtd--;
        return valor;
        
        
    }else{
        puts("Pilha vazia");
        return -1;
    }
    
}

// opção 4
void ImprimePilha(tipoPilha *pilhaVet){
    int i;
    for(i=(pilhaVet->qtd)-1; i>-1; i--){
            printf("[%d]\n", (pilhaVet)->Pilha[i]);
    }
    
    
}





int main(){
    int op,i,valor;
    tipoPilha pilhaVet;
    // inicialização da pilha
    pilhaVet.qtd = 0;
    for(i=0; i<MAX; i++){
        pilhaVet.Pilha[i] = -1;
        
    }
    do{
        puts("Digite a opção:\n1-Empilhar\n2-Desempilha\n3-Topo\n4-Imprime\n0-Sair");
        scanf("%d",&op);
        system("clear");
        switch(op){
            case 1:
                puts("Digite um valor:");
                scanf("%d", &valor);
                Empilha(&pilhaVet,valor);
                break;
            case 2:
                valor = Desempilha(&pilhaVet);
                if(valor > -1){
                    printf("%d\n",valor);   
                }else{
                    
                }
                break;
            case 3:
                if(pilhaVet.qtd != 0)
                    printf("Topo = %d\n", pilhaVet.Pilha[pilhaVet.qtd-1]);
                else
                    puts("Pilha vazia");
                break;
            case 4:
                ImprimePilha(&pilhaVet);
                break;
            default:
                break;
            
        }
    }while(op != 0);
    
    return 0;
}