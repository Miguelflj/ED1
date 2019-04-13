
#include <stdio.h>
#include <stdlib.h>



int main(){
    int DistanPer;
    double combGasto, consumoMedio;
    scanf("%d", &DistanPer);
    scanf("%lf", &combGasto);

    consumoMedio = (DistanPer/combGasto);
    
    printf("%0.3lf km/l\n", consumoMedio);












return 0;
}