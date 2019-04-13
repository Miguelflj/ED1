

#include <stdio.h>
#include <stdlib.h>


int main(){
    double raio, area,pi=3.14159;
    scanf("%lf", &raio);
    area = (pi*raio*raio);
    printf("A=%0.4lf\n", area);

return 0;
}