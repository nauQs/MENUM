#include<stdio.h>    
#include<stdlib.h>  
#include <time.h>  
#include<math.h>

int n;
double tolerancia;
void printmatrix(double** A){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%+1.4f       ", A[i][j]);
        }
        printf("\n");
    }
     printf("\n");
}
/*Eliminació Gaussiana sense pivotatge*/
int elimGauss(double**A){
    double m;
    int k,i,j;
    /*Cal fer n-1 etapes: */
    for(k=0;k<n-1;k++){
        if(A[k][k] < tolerancia) return 1;
        /*Calculem per a cada fila i€{k+1,.....,n} mik  i fem la resta:*/
        for(i=k+1;i<n;i++){
            /*Calculem mik*/
            m = A[i][k] / A[k][k];
            /*Ja sabem que efectuan la resta a i=k obtenim 0:*/
            A[i][k] = m;
            /*Per a cada j€{k+1,.....,n} fem la resta corresponent, i també per a bi*/
            for(j=k+1;j<n;j++) A[i][j] -= m*A[k][j];
        }
    }
    return 0;
}
int main(void)
{
    double **A, **AA, **L, **U;
    int i, j, k;
    tolerancia = 1.e-14;
    /*Llegim A*/
    printf("Escriu l'enter n:");
    scanf("%d", &n);
    U = (double **)malloc(n*sizeof(double*));
    L = (double **)malloc(n*sizeof(double*));
    AA= (double **)malloc(n*sizeof(double*));
    A = (double **)malloc(n*sizeof(double*));
    for(i=0;i<n;i++){
        L[i] = (double *)malloc(n*sizeof(double));
        U[i] = (double *)malloc(n*sizeof(double));
        AA[i] = (double *)malloc(n*sizeof(double));
        A[i] = (double *)malloc(n*sizeof(double));
        for(j=0;j<n;j++){
        printf("Escriu A%d%d:",i,j);
        scanf("%le", &A[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            AA[i][j]=A[i][j];
        }
    }
    /*Fem eliminació Gaussiana. A esdevindrà A(k) i b esdevindrà c */
    if(elimGauss(A) != 0){
        printf("No s'ha pogut realitzar eliminacio gaussiana sense pivotatge.\n");
    }else{
    printf("Matriu triangulada amb m a sota la diagonal inferior:\n");
    printmatrix(A);
    printf("A=LU\nL=\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j<i) printf("%+1.3e   ", A[i][j]);
            if(i==j) printf("%+1.3e   ",1.);
            if(j>i) printf("%+1.3e   ", 0.);
        }
        printf("\n");
    }
    printf("U=\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j<i) printf("%+1.3e   ", 0.);
            if(i==j) printf("%+1.3e   ",A[i][j]);
            if(j>i) printf("%+1.3e   ", A[i][j]);
        }
        printf("\n");
    }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>j){
                L[i][j]=A[i][j];
                U[i][j]=0;
            }
            else if(i==j){
                L[i][j]=1;
                U[i][j]=A[i][j];
            }else{
                U[i][j]=A[i][j];
                L[i][j]=0;
            }
        }
    }
    
    for (i=0; i<n; i++) { 
        for (j=0; j<n; j++) {
            for (k=0; k<n; k++){
                A[i][j] += L[i][k]*U[k][j];
            }
        }
    }
    printmatrix(L);
    printmatrix(U);
    printmatrix(A);
    
    
    for (i=0; i<n; i++) free(A[i]);
    free(A);
    for (i=0; i<n; i++) free(AA[i]);
    free(AA);
    for (i=0; i<n; i++) free(L[i]);
    free(L);
    for (i=0; i<n; i++) free(U[i]);
    free(U);
    
    return 0;
}
