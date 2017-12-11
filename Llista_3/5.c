#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double fun(double x){
    double y;
    y = sin(x);
    return y;
}
int main (void){
    int n, i, j;
    double **M,a,h;
    printf("Digues n:");
    scanf("%d",&n);
    printf("Digues a: \n");
    scanf("%le", &a);
    printf("Digues h: \n");
    scanf("%le", &h);
    /*Agafem n+1 parells (xi, fi)*/
    M = (double**)malloc((n+1)*sizeof(double*));
    /*Donem valors als parells. Utilitzem abscisses equidistants*/
    for(i=0;i<n+1;i++){
        M[i] = (double*)malloc(2*sizeof(double));
        M[i][0] = a + ((i-n/2)*h);
        M[i][1] = fun(M[i][0]);
    }
    /*Ara tenim una matriu amb tots els parells (xi,fi) de 0 a n*/
    /*Fem la diferenciacio*/
    for(i=0;i<n+1;i++){
        printf("x%d=%le  f%d=%le\n",i+1,M[i][0],i+1,M[i][1]);
    }
    
    return 0;
}