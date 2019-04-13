#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    
    int controle, h;
    
    scanf("%d", &controle);
    
    for(h=0;h<controle;h++){
        
    char string1[100], string2[100], stringnova[100];
    int bool=0,tamstr1, tamstr2, tamtotal, i, str1=0, str2=0, k;
        
        scanf("%s %s", string1, string2);
        
        tamstr1 = strlen(string1);
        tamstr2 = strlen(string2);
        
        tamtotal = tamstr1 + tamstr2;
        
        for(i=0;i<=tamtotal;i++){
            
            if(string1[str1] == '\0'){
                for(k=i; string2[str2] != '\0'; k++){
                    stringnova[k] = string2[str2];
                    str2++;
                }
                    i = tamtotal;
            }
            if(string2[str2] == '\0'){
                for(k=i; string1[str1] != '\0'; k++){
                    stringnova[k] = string1[str1];
                    str1++;
                }
                    i = tamtotal;
            }
            
            
            if(bool == 0){
                stringnova[i] = string1[str1];
                str1++;
                bool = 1;
                
            }else
            {
                
                stringnova[i] = string2[str2];
                str2++;
                bool = 0;
            
            }
            
        }
        stringnova[tamtotal+1] = '\0';
        printf("%s\n", stringnova);
    }





    return 0;

}