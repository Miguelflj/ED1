
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
        while(1){
            char entrada[2000];
            
            scanf("%[^\n]", entrada);
            scanf("%*c");
            char tauto = 'Y';
            
            if(entrada[0] == '*'){
                return 0;
            }
            int i, tamString;
            tamString = strlen(entrada);
            
            for(i=0;i<tamString;i++){
                
                if(isalpha(entrada[i]) && entrada[i] != ' '){
                    entrada[i] = toupper(entrada[i]);
                }
        
            }
            for(i=0;i<tamString;i++){
                if(entrada[i] == ' '){
                    if(entrada[i+1] != entrada[0]){
                        tauto = 'N';

                        break;
                    }
                    
                }
            }
            printf("%c\n", tauto);
        }

       
    return 0;
}