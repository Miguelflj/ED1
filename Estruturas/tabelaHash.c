
#include <stdio.h>
#include <stdlib.h>

#define MAX 15

typedef struct tipoAluno{
    char nome[60];
    int ra;

}tipoAluno;

#define ALUNO_NULO (tipoAluno) {"",-1}

typedef struct tipoTabHash{
    tipoAluno tabHash[MAX];
    int qtd;

}tipoTabHash;

void inicializaTabHash(tipoTabHash *tabela){
    int i;
    for(i=0; i < MAX; i++){
        (tabela)->tabHash[i] = ALUNO_NULO;
    }
    (tabela)->qtd = 0;
};


int funcaoHash(int key){
    int index;
    index = (key%MAX);
    return index;

};

void GuardarAluno(tipoTabHash *tabela){
    int key,pos;
    if((tabela)->qtd < 10){
        puts("Digite o ra do aluno");
        scanf("%d",&key);
        
        pos = funcaoHash(key);

        while((tabela)->tabHash[pos].ra != -1){
            if(pos == MAX-1){
                pos = 0;
            }else{
                pos++;
            }
        }
        scanf("%s",(tabela)->tabHash[pos].nome);
        (tabela)->tabHash[pos].ra = key;
        (tabela)->qtd++;
    }else{
        puts("Numero máximo de alunos inseridos");
    }
};

int Busca(tipoTabHash *tabela){
    int key,pos;
    puts("Digite o ra");
    scanf("%d",&key);
    pos = funcaoHash(key);
    while( (tabela)->tabHash[pos].ra !=   key){
        if((tabela)->tabHash[pos].ra == -1){
                return -1;
        }
        if(pos == MAX-1){
            pos = 0;
        }else{
            pos++;
        }
        
    }
        return pos;

};



int main(){
    int op,pos;
    tipoTabHash tabela;
    inicializaTabHash(&tabela);
    do{
        puts("Digite a opção:\n 1-Guardar\n 2-Buscar\n 0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                GuardarAluno(&tabela);
                break;
            case 2:
                pos = Busca(&tabela);
                if( pos == -1){
                    puts("RA nao existe");
                }else{
                    printf("%s\n",tabela.tabHash[pos].nome);
                    printf("%d\n",tabela.tabHash[pos].ra);
                }

                break;
            default:
                break;
        
        }
    }while(op != 0); 
    return 0;
}