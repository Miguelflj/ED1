

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int qtd, h;
    scanf("%d", &qtd);

    for(h=0;h<qtd;h++){
        
        char palavra[100], palavraNova[100];
        int tam, tamMeio,i , controle = 0;
        
        scanf("%*c");
        
        scanf("%[^\n]", palavra);
        
        tam = strlen(palavra);
        tamMeio = ((tam/2)-1);

        for(i=tamMeio;i > -1;i--){
            
            palavraNova[controle] = palavra[i];
            controle++;
        }
    
        
        for(i=tam-1;i>=tamMeio+1;i--){
            
            
            palavraNova[controle] = palavra[i];
            controle++;
            
        }
        palavraNova[tam] = '\0';


        printf("%s\n", palavraNova);

}

    return 0;
}