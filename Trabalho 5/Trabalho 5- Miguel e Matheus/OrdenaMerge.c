
/*  UFMT - Ciencia da Computação
 * Estrutura de Dados 1
 * Professor Ivairton
 * 
 * Trabalho 5 - Metodos de ordenação ( 27 nov 2017)
 */





#include <stdio.h>
#include <stdlib.h>


// MAX recebe valor de acordo com a quantidade de valores do arquivo de entrada. 
#define MAX 1000


typedef struct tipoLista{
    int lista[MAX];
    int qtd;
    
}tipoLista;

// faz o merge e volta as galhas ordenando
void Merge(tipoLista *vet,int inicio, int meio, int fim,long int *vetAux2){
        int *vetAux,tam;
        int i,j,k;
        long int contComp=0,contTroca=0;
        tam = (fim - inicio) + 1;
        
        vetAux = (int*) malloc(sizeof(int)*tam);
        // i com o inicio do subvetor a esquerda
        i=inicio;
        // j com o inicio do subvetor a direita
        j=meio+1;
        // tamanho do vetor inicial
        for(k=0; k < tam; k++){
            // verifica se os lados dos meus subvetores ainda tem valores a direita
            
            if(i < (meio+1) && j <= fim){
                // faz a ordenacao crescente
                contComp++;
                if(vet->lista[i] < vet->lista[j]){
                    vetAux[k] = vet->lista[i++];
                    
                }else{
                    contTroca++;
                    vetAux[k] = vet->lista[j++];
                    
                }
                
            // se um dos subvetores chegou ao fim completa com o outro
            }else if(i < (meio+1) && j > fim){
                vetAux[k] = vet->lista[i++];
                
            }else{
                vetAux[k] = vet->lista[j++];
                
            }
                
        }
        vetAux2[0] = contComp;
        vetAux2[1] = contTroca;
        i = 0;
        for(k=inicio; k <= fim; k++){
            vet->lista[k] = vetAux[i++];
            
        }
        free(vetAux);
            
}

void Sort(tipoLista *vet,int inicio, int fim,long int *vetAux2){
    int meio;
    if( inicio < fim){
        meio = ( (inicio + fim)/ 2);
        // quebra pro lado esquerdo
        Sort(vet, inicio, meio,vetAux2);
        // quebra pro lado direito
        Sort(vet, meio+1, fim,vetAux2);
        // faz o merge
        Merge(vet,inicio, meio, fim,vetAux2);
    }
    
}

int main(){
    tipoLista listaVet;
    listaVet.qtd = 0;
    int n;
    long int vetAux2[2];
    int i;
    FILE *arqv;
    //recebe nome de arquivo com valores desordenados
    // ex.: 1000-arq1.txt 
    arqv = fopen("nome_arquivo_input.txt","rt");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    i=0;
    while( fscanf(arqv,"%d",&n) != EOF){
        listaVet.lista[i++] = n;
        listaVet.qtd++;

    }
    
    Sort(&listaVet,0,MAX-1,vetAux2);
    
    fclose(arqv);

    //nome do arquivo que receberá valores ordenados
    arqv = fopen("nome_arquivo_output(ordenado Merge).txt","w");
    if(arqv == NULL){
        printf("Erro na abertura do arquivo.\n");
    }
    for(i=0; i < listaVet.qtd; i++){
         fprintf(arqv,"%d\n", listaVet.lista[i]);
    }
    fprintf(arqv,"Comparações = %ld\n", vetAux2[0]);
    fprintf(arqv,"Troca = %ld\n", vetAux2[1]);

    fclose(arqv);
    

    return 0;
}
