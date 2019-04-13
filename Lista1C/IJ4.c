#include <stdio.h>
#include <stdlib.h>


int main(){
    int i=0, j=1;

    while(i <= 2){

		
        if (j==1){
            j = 1;
        }
        if (j==2){
            j = 2;
        }
        if (j==3){
            j = 3;
        }
        if (j==4){
            j = 4;
        }
        if (j==5){
            j = 5;
        }
        if (i==2){
            i = 2;
        }
        if (i==1){
            i = 1;
        }

        printf('I=%d J=%d, i, j);
        j = j + 1;
		
        if(j == (i + 4)){
                i = i+0.2;
                j = j-2.8;
        }
}

return 0;

}