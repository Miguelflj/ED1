


#include <stdio.h>
#include <stdlib.h>


int main(){
    double a,b,c, areaTra,areaTri, areaC, areaQua, areaRet, pi=3.14159;
    scanf("%lf %lf %lf", &a, &b, &c);

    areaTri = (a * c / 2.0);
    areaC = (pi*c*c);
    areaTra = (c*(a+b)/2.0);
    areaQua = (b * b);
    areaRet = (a * b);
    
    printf("TRIANGULO: %0.3lf\n", areaTri);
    printf("CIRCULO: %0.3lf\n", areaC);
    printf("TRAPEZIO: %0.3lf\n", areaTra);
    printf("QUADRADO: %0.3lf\n", areaQua);
    printf("RETANGULO: %0.3lf\n", areaRet);



return 0;
}