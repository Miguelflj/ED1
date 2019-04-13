/*Metodo de ordenação do tipo bolha
 * ineficiente para grandes listas de dados
 * 
 * miguel freitas/
 * 
 * 
 * utilizavel para ordenar decrescente o algoritmo Lista.c
 * bublle sort
 */



void bolha(tipoLista *listaVet){
    int i, j,aux;
    for(j=(listaVet)->qtd-1; j>= 1; j--){
        for(i=0; i<j; i++){
                if((listaVet)->lista[i] < (listaVet)->lista[i+1]){
                    aux = (listaVet)->lista[i];
                    (listaVet)->lista[i] = (listaVet)->lista[i+1];
                    (listaVet)->lista[i] = aux;
                }
        }
        
    }
    
}