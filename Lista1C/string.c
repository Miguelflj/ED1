#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char string[100], paranaue[100];
    scanf("%[^\n]", string);
    //expressão regular para ler string (leia tudo até o \n)
    scanf("%*c");
    // gambiarra mas num é, remover do input, economia de memória.
    scanf("%[^\n]",paranaue);
    //amostrando pro usuário de drogas
    printf("%s\n", string);
    printf("%s\n", paranaue);








    return 0;

}
