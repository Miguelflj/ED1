/*
 * balanço de paranteses
 * Miguel Freitas
 * ED1 - lista 4
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct tipoFila{
    char Fila[1000];
    int qtd;
    
}tipoFila;

void InsereParentese(tipoFila *filaVet,char Parentese){

    (filaVet)->Fila[(filaVet)->qtd] = Parentese;
    (filaVet)->qtd++;
        
}
int ContaParenteses(tipoFila *filaVet){
    int i,cont1=0,cont2=0;
    for(i=0; i < (filaVet)->qtd; i++){
            if((filaVet)->Fila[i] == '('){
                cont1++;
            
            }else if((filaVet)->Fila[i] == ')'){
                cont2++;  
            }
            if(cont2 > cont1){
                return 0;
            }
    }
    if(cont1 == cont2){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    tipoFila filaVet;
    char entrada[1000];

    
    while(scanf("%s",entrada) != EOF){
        
        tipoFila filaVet;
        int i,tam,flagIn=1,flagCont;
        filaVet.qtd = 0;
        
        scanf("%*c"); 
        
        tam = strlen(entrada);

        for(i=0; i < tam; i++){

            if(entrada[i] == ')'){
                InsereParentese(&filaVet,entrada[i]);
            }
            if(entrada[i] =='(' ){
                InsereParentese(&filaVet,entrada[i]);
            }
        }
        /*
        for(i=0; i < filaVet.qtd; i++){
            printf("[%c]",filaVet.Fila[i]);
        }
            puts("");
        */
        if(filaVet.Fila[0] == ')' ){
            flagIn = 0;
        }
            flagCont = ContaParenteses(&filaVet);
            
       if(flagCont && flagIn){
            puts("correct");
       }else{
            puts("incorrect");
       }
        
        
    }
    return 0;
}