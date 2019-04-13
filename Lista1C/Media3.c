

#include <stdio.h>
#include <stdlib.h>

int main(){
    double n1, n2, n3, n4, ne, media, mediaex;
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    
    media = (((n1*2) + (n2*3) + (n3*4) + (n4*1))/10.0);
    
    printf("Media: %0.1lf\n", media);
    
    if(media >= 7.0){
        printf("Aluno aprovado.\n");

    }
    if(media > 5.0 && media <= 6.9){
        printf("Aluno em exame.\n");
        
        scanf("%lf", &ne);
        mediaex = ((media + ne)/2.0);
        printf("Nota do exame: %0.1lf\n", ne);

        if(mediaex > 5.0){
            printf("Aluno aprovado.\n");
        }
        else{
            printf("Aluno reprovado.\n");
            
        }
        printf("Nota final: %0.1lf\n", ((media + ne)/2.0));
        
    }
    if(media < 5.0){
        printf("Aluno reprovado.\n");
            
            
    }
        
    



return 0;
}

            