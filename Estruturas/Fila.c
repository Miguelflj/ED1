#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct tipoFila{
    int Fila[MAX];
    int qtd;
    
    
}tipoFila;
// opção 1
void Insere(tipoFila *filaVet,int valor){
    int i;
    if((filaVet)->qtd  < MAX){
        (filaVet)->Fila[(filaVet)->qtd] = valor;
        (filaVet)->qtd++;
        
    }else{
        puts("Fila Cheia");
    }
}
//Opção 2
int Remove(tipoFila *filaVet){
    int i,valor;
    if((filaVet)->qtd > 0){
            valor = (filaVet)->Fila[0];
            for(i=0; i < ((filaVet)->qtd-1); i++){
                (filaVet)->Fila[(filaVet)->qtd-1] = 0;
                (filaVet)->Fila[i] = (filaVet)->Fila[i+1];
                return valor;
            }   

    }else{
        puts("Fila vazia");
        return -1;
    }
    
}

// opção 3
int PrimeiroElemento(tipoFila *filaVet){
     if((filaVet)->qtd > 0){
        return (filaVet)->Fila[0];
    }else{
        
        puts("Fila vazia");
        return 0;
    }
}


//opção 5
void ImprimeFila(tipoFila *filaVet){
    int i;
    for(i=0;i<MAX;i++){
        printf("[%d]",(filaVet)->Fila[i]);
    }
    puts("");
}



int main(){
    int op,i;
    int valor,elemento;
    tipoFila filaVet;
    
    //inicialização fila
    filaVet.qtd = 0;
    for(i=0;i<MAX;i++){
        filaVet.Fila[i] = -1;
        
    }
    
    do{
        puts("Digite a opção:\n1-Inserção\n2-Remoção\n3-Primeiro elemento\n4-Quantidade de Ele.\n5-Imprimir fila\n0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                puts("Digite um valor");
                scanf("%d",&valor);
                Insere(&filaVet,valor);
                break;
            case 2:
                 valor = Remove(&filaVet);
                 if(valor == -1){
                     
                }else{  
                     printf("%d\n",valor);
                }
                break;
            case 3:
                elemento = PrimeiroElemento(&filaVet);
                if(elemento == 0){
                }else{
                printf("%d\n", elemento);
                }
                break;
            case 4:
                if((filaVet).qtd > 0)
                    printf("elemento(s) = %d\n",(filaVet).qtd);
                else
                    puts("Fila vazia");
                break;
            case 5:
                ImprimeFila(&filaVet);
                break;
            default:
                break;
                
        }
        
    }while(op != 0);
    
    return 0;
}