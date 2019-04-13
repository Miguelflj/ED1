

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



int main(){
    char palavra[100], palavraNova[100];
    int i, tamPalavra, bool=0;
    
    scanf("[^\n]", palavra);
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
    printf("%s\n", palavraNova);



    return 0;

}