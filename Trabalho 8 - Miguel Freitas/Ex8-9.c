/*Exercicio 8 de 9
Estrutura de dados 1 - UFMT
Miguel Freitas de Vinícius Magno
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMN 25

typedef struct tipo_familia {
	char nome[TAMN];
	char *vet_raça[capacidade];
	int qtd_raça;
	int capacidade;
}tipo_familia;

typedef struct tipo_classe{
	char nome[TAMN];
	struct tipo_familia *vet_familia[capacidade];
	int qtd_familia;
	int capacidade;
tipo_classe;


typedef struct tipo_animal {
	char nome[TAMN];
	struct tipo_classe *vet_classe[5];
	int qtd_classe;	

}tipo_animal;


void InsereAnimal(tipo_animal **animal,char classe[],char familia[],char raca[]);
tipo_animal *inicializaAnimal(tipo_animal *animal);

int main(){
	int i;
	tipo_animal *animal;

	animal = inicializaAnimal(animal,"Animal");
	

	return 0;
}




tipo_animal *inicializaAnimal(tipo_animal *animal,char s[]){
	int i;

	animal = (animal*) malloc( sizeof(animal) );
	animal->qtd_classe = 0;
	strcpy(animal->nome,s);
	for(i = 0; i < 5; i++){
		animal->*vet_classe[i] = NULL;
	}
	return animal;

}


tipo_classe *inicializaClasse(tipo_classe *classe,char s[]){
	tipo_classe *nova;

	nova = (tipo_classe*) malloc( sizeof(tipo_classe) );
	strcpy(nova->nome,classe);
	novo->qtd_familia = 0;
	novo->capacidade = 0;
	return novo;
}

void InsereClasse(tipo_classe **classe,char familia[],char raca[]){

	
}



void InsereAnimal(tipo_animal **animal,char classe[],char familia[],char raca[]){
	tipo_classe *aux, *nova;
	int pos = -1;
	int i;
	if(animal->qtd_classe < 5){
		for (i = 0; i < 5; i++){
			aux = animal->classe[i];
			if( (aux != NULL ) && (strcmp(aux->nome,classe)) ){
				pos = i;
				i = 5;
			} 
		}
		if( pos != -1){
			// chama a função passando a posição 'pos' acessando a classe ja adicionada
		} else {
			animal->vet_classe[qtd_classe] = inicializaClasse(novo,classe);
			animal->qtd_classe++;
		}
	} else {
		for (i = 0; i < 5; i++){
			aux = animal->classe[i];
			if( (aux != NULL ) && (strcmp(aux->nome,classe)) ){
				pos = i;
				i = 5;
			}
		}
		if( pos != -1){
			// chama a função passando a posição 'pos' acessando a classe ja adicionada
		}
	}


}