#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1

 int main(){
    int i, j, n, ins, lteste, cteste, flag, linhain, colunain, linhafim, colunafim, lteste2, cteste2;
    int ***mtz;
    scanf("%d", &n);
    mtz = (int***) malloc(n*sizeof(int**));

    for(i=0;i<n;i++){
        mtz[i] = (int**) malloc(9*sizeof(int*));
        for(j=0;j<9;j++){
            mtz[i][j] = (int*) malloc(10*sizeof(int));
        }
    }

    for(ins=0;ins<n;ins++){
        for(i=0;i<9;i++){
            scanf("%d %d %d %d %d %d %d %d %d", &mtz[ins][i][0], &mtz[ins][i][1], &mtz[ins][i][2], &mtz[ins][i][3], &mtz[ins][i][4], &mtz[ins][i][5], &mtz[ins][i][6], &mtz[ins][i][7], &mtz[ins][i][8]);
        }
    }
    for(ins=0;ins<n;ins++){
        flag = TRUE;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){

                for(cteste=0;cteste <9; cteste++){
                    if(cteste != j){
                        if(mtz[ins][i][j] == mtz[ins][i][cteste]){
                            flag = FALSE;

                        }
                    }
                }
                for(lteste=0;lteste<9;lteste++){
                    if(lteste != i){
                        if(mtz[ins][i][j] == mtz[ins][lteste][j]){
                            flag = FALSE;

                        }
                    }
                }


            }
        }
        linhain = colunain= 0;
        linhafim = colunafim = 3;
        lteste=cteste=0;
        for(i=0;i<9;i++){


                while(linhafim<=9){

                    while(colunafim<=9){


                            for(lteste = linhain; lteste<linhafim;lteste++){
                                for(cteste=colunain; cteste<colunafim;cteste++){
                                    for(lteste2 = linhain;lteste2<linhafim;lteste2++){
                                        for(cteste2 = colunain; cteste2<colunafim; cteste2++){
                                            if(cteste!=cteste2 && lteste!= lteste2){


                                                if(mtz[ins][lteste][cteste]==mtz[ins][lteste2][cteste2]){
                                                flag = FALSE;

                                                }
                                            }
                                        }
                                    }


                                }

                            }
                                colunain = colunain +3;
                                colunafim = colunafim+3;
                    }



                    linhain = linhain +3;
                    linhafim = linhafim+3;
                    colunafim = 3;
                    colunain = 0;
                }

        }

        if(flag){
            printf("Instancia %d\n", (ins+1));
            printf("SIM\n");
            printf("\n");

        }
        else{
            printf("Instancia %d\n", (ins+1));
            printf("NAO\n");
            printf("\n");
        }
    }










 return 0;

}
