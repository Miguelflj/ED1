
#include <stdio.h>
#include <stdlib.h>


int main(){
    double n1,n2,n3, media;
    //n1 tem peso 2.
    //n2 tem peso 3.
    //n3 tem peso 5.
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    scanf("%lf", &n3);
    
    media = (((2*n1) + (3*n2) + (5*n3))/10.0);
    
    printf("MEDIA = %0.1lf\n", media);




return 0;
}