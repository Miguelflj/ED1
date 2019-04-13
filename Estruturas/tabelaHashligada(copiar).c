#include <stdio.h>
#include <stdlib.h>

#define MAX 15

struct estAluno {
    char nome[60];
    int m;
    struct estAluno *prox;

};

typedef struct estAluno tipoAluno;




typedef struct tipoTabHash{
    tipoAluno *tabHash[MAX];

}tipoTabHash;


void inicializaTabHash(tipoTabHash *tabela){
    int i;
    for(i=0; i < MAX; i++){
        (tabela)->tabHash[i] = NULL;
    }
};


int funcaoHash(int key){
    int index;
    index = (key%MAX);
    return index;

};

tipoAluno novoAluno(char nome[],int ra){
    tipoAluno *novo;
    novo = (tipoAluno*) malloc(sizeof(tipoALuno));

    strcpy(novo->nome,nome);
    novo->ra = ra;
    novo->prox = NULL;
    return novo;
};

void InsereNaTabela(tipoTabHash *tabela,int chave, tipoAluno *aluno){
    int pos;
    tipoAluno *aux;
    pos = funcaoHash(chave);
    aux = tabela[pos];
    while( aux->prox != NULL){
            aux = aux->prox;
    }
    aux->prox = aluno;
}


tipoAluno Busca(tipoTabHash *tabela,int chave) {
    int pos;
    tipoAluno *aluno;

    pos = funcaoHash(chave);
    aluno = tabela->tabelaHash[pos]
    while(aluno != NULL){
        if(aluno->ra == chave){
            return aluno;
        }
        aluno = aluno->prox;
    }

    return NULL;
};



int main(){
    int op,pos;
    tipoTabHash *tabela;
    tipoAluno *aluno;
    char nome[60];
    int ra;

    inicializaTabHash(tabela);


    do{
        puts("Digite a opção:\n 1-Guardar\n 2-Buscar\n 0-Sair");
        scanf("%d", &op);
        system("clear");
        switch(op){
            case 1:
                scanf("%s",nome);
                scanf("%d",&ra);
                aluno = novoAluno(&nome,ra);
                InsereNaTabela(&tabela,ra,&aluno);
                break;
            case 2:
                puts("Digite o ra do aluno");
                scanf("%d",&ra);
                aluno = Busca(&tabela,ra);
                if(aluno == NULL){
                    puts("Nao cadastrado");
                }else{
                    printf("%s",aluno.nome);
                    printf("%d",aluno.ra);
                    
                }
                break;
            default:
                break;
        
        }
    }while(op != 0); 
    return 0;
}