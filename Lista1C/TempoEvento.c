
/*Miguel Freitas
 * ED1 - aprendendo C em duas semanas :D
 * Tempo de um Evento
 */




#include <stdio.h>
#include <stdlib.h>



int main(){
    char desc[100];
    int diaInicio, horaInicio, minuInicio, segInicio;
    int diaFim, horaFim, minuFim, segFim;
    int inicioEvento, fimEvento, tempo;
    int EventoD, EventoH, EventoM, EventoS;
    
    
    scanf("%s %d", desc, &diaInicio);
    scanf("%d : %d : %d", &horaInicio, &minuInicio, &segInicio);
    scanf("%s %d", desc, &diaFim);
    scanf("%d : %d : %d", &horaFim, &minuFim, &segFim);
 
    inicioEvento = (segInicio + (minuInicio*60) + (horaInicio*60*60) + (diaInicio*60*60*24));
    
    fimEvento = (segFim + (minuFim*60)+ (horaFim*60*60)+ (diaFim*60*60*24));
    
    tempo = (fimEvento - inicioEvento);
    
    
    EventoD = tempo/86400;
    
    printf("%d dia(s)\n", EventoD);
    
    tempo = tempo%86400;
    
    EventoH = tempo/3600;
    
    printf("%d hora(s)\n", EventoH);
    
    tempo=tempo%3600;
    
    EventoM = tempo/60;
    
    printf("%d minuto(s)\n", EventoM);
    
    EventoS = tempo%60;
    
    printf("%d segundo(s)\n", EventoS);


return 0;
}