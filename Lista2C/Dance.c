

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // biblioteca para tratar string
#include <string.h>



int main(){
    
    char palavra[100];
    
    
    while(scanf("%[^\n]", palavra) != EOF){
        
        char palavraNova[100];
        int i, tamPalavra;
        int bool=0;
        scanf("%*c");
        tamPalavra = strlen(palavra);
        
        for(i=0;i<tamPalavra;i++){
            if(isalpha(palavra[i]) && palavra[i] !=  ' '){
                if(bool == 0){
                    palavraNova[i] = toupper(palavra[i]);
                    bool = 1;
                }else{
                    palavraNova[i] = tolower(palavra[i]);
                    bool = 0;
                
        
                }
                
        
            }else{
            
                palavraNova[i] = palavra[i];
                
            }
        

    } 
    palavraNova[tamPalavra] = '\0';
    
        printf("%s\n", palavraNova);
    
    }
    return 0;
}