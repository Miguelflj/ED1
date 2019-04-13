


#include <stdio.h>
#include <stdlib.h>



int main(){
    int tempoSeg,contSeg=0,contMin=0,contH=0;
    scanf("%d", &tempoSeg);
    while(tempoSeg>=3600){
        tempoSeg = tempoSeg - 3600;
        contH++;
    }
    while(tempoSeg>=60){
        tempoSeg = tempoSeg - 60;
        contMin++;
    }
    while(tempoSeg>=1){
        tempoSeg = tempoSeg -1;
        contSeg++;

    }
    printf("%d:%d:%d\n", contH, contMin, contSeg);
return 0;
}