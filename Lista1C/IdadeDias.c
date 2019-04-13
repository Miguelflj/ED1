

#include <stdio.h>
#include<stdlib.h>


int main(){
    int dias, contAno=0, contMes=0, contDia=0;
    scanf("%d", &dias);
    while(dias>=365){
        dias -= 365;
        contAno++;
    
    }
    while(dias>=30){
        dias -= 30;
        contMes++;
    }
    while(dias>=1){
        dias -= 1;
        contDia++;

    }
    
    printf("%d ano(s)\n", contAno);
    printf("%d mes(es)\n", contMes);
    printf("%d dia(s)\n", contDia);



    

return 0;
}