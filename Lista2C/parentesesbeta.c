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
            }
            if((filaVet)->Fila[i] == ')'){
                cont2++;  
            }
    }
    if(cont1 == cont2){
        return 1;
    }else{
        return 0;
    }
}
int VerificaParenteses(tipoFila *filaVet){
    int i,j=0, flag=1;
    char compara;
    while(flag == 1){
        flag = 0;
        if((filaVet)->Fila[j] != 'l'){
            if((filaVet)->Fila[j] == '(');
                for(i=j; i < (filaVet)->qtd; i++){
                    if((filaVet)->Fila[i] == ')'){
                        (filaVet)->Fila[i] = 'l';
                        flag = 1;
                        i = (filaVet)->qtd;
                    }
                }
            if((filaVet)->Fila[j] == ')');
                for(i=j; i < (filaVet)->qtd; i++){
                    if((filaVet)->Fila[i] == '('){
                        (filaVet)->Fila[i] = 'l';
                        flag = 1;
                        i = (filaVet)->qtd;
                    }
                }
            (filaVet)->Fila[j] = 'l';
            j++;
        }
    }
    for(i=0; i <  (filaVet)->qtd; i++){
        if((filaVet)->Fila[i] != 'l'){
            return 0;
        }
    }
    return 1;
}

int main(){
    tipoFila filaVet;
    char entrada[1000];
    int i,tam, flag=1;

    filaVet.qtd = 0;

    scanf("%s",entrada);
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
        if(filaVet.Fila[0] == ')'){
            puts("incorrect");
            return 0;
        }
        flag = ContaParenteses(&filaVet);
        if(flag == 0){
            puts("incorrect");
            return 0;
        }
        flag = VerificaParenteses(&filaVet);
        if(flag == 0){
            puts("incorrect");
        }else{
            puts("correct");
        }
    return 0;
}