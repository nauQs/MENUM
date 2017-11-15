#include<stdio.h>    
#include<stdlib.h>  
#include <time.h>  
#include <math.h>

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

int elimGauss(double**A, double*b){
    double m;
    int k,i,j;
    /*Cal fer n-1 etapes: */
    for(k=0;k<n-1;k++){
        if(fabs(A[k][k]) < tolerancia) return 1;
        /*Calculem per a cada fila i€{k+1,.....,n} mik  i fem la resta:*/
        for(i=k+1;i<n;i++){
            /*Calculem mik*/
            m = A[i][k] / A[k][k];
            /*Ja sabem que efectuan la resta a i=k obtenim 0:*/
            A[i][k] = m;
            /*Per a cada j€{k+1,.....,n} fem la resta corresponent, i també per a bi*/
            for(j=k+1;j<n;j++){
                A[i][j] -= m*A[k][j];
            }
            b[i] -= m*b[k];
          
        }
    }
    return 0;
}

void printldlt(double** A){
    int i, j;
    printf("L = \n");
    for (i = 0; i < n; i++){
        for (j = 0; j<n; j++){
            if (i>j){
                printf("%+1.4f       ", A[i][j]);
            }else if (i==j){
                printf("%+1.4f       ", 1.);
            }else {
                printf("%+1.4f       ", 0.);
            }
        }
        printf("\n");
        
    }
    
    printf("\n");
    printf("D = ");
    printf("\n");
    for (i = 0; i < n; i++){
        for (j = 0; j<n; j++){
            if (i==j){
                printf("%+1.4f       ", A[i][j]);
            }else {
                printf("%+1.4f       ", 0.);
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("Lt = ");
    printf("\n");
    for (i = 0; i < n; i++){
        for (j = 0; j<n; j++){
            if (i<j){
                printf("%+1.4f       ", A[j][i]);
            }else if (i==j){
                printf("%+1.4f       ", 1.);
            }else {
                printf("%+1.4f       ", 0.);
            }
        }
        printf("\n");
    }
}
            
        
void resolucioLDLt(double** A, double* b){
    int sumatori, i, j;
    /*LDLt*x = b 
     Ly = b -> y
     
     Dz= y ->z
     Ltx = z -> x
     */

    for(i=1; i<n; i++){
        sumatori = 0;
        for(j=0; j<i; j++){
            sumatori+= A[i][j]*b[j];
        }
        b[i] = b[i]-sumatori;
    
    }
    
    for(i=0; i < n; i++){
        b[i] = b[i]/A[i][i];
    }

    for(i=n-2; i >= 0; i--){
        for (j = i+1; j<n; j++){
            b[i]  -= A[j][i]*b[j];
        }
    }
            
    for (i = 0; i<n; i++){
        printf("%+1.4f ", b[i]);
    }
}
        
        
int main(void)
{
   double **A, *b;
   int i, j;
   tolerancia = 1.e-12;
   /*Llegim A*/
   printf("Escriu l'enter n:");
   scanf("%d", &n);
   A = (double **)malloc(n*sizeof(double*));
   b = (double *)malloc(n*sizeof(double));
   for(i=0;i<n;i++){
       A[i] = (double *)malloc(n*sizeof(double));
       for(j=0;j<n;j++){
        printf("Escriu A%d%d:",i,j);
        scanf("%le", &A[i][j]);
        }
   }
   
   for(i=0;i<n;i++){
    printf("Escriu b%d:",i);
    scanf("%le", &b[i]);
    }
    
    /*Fem eliminació Gaussiana. A esdevindrà A(k) i b esdevindrà c */
    if(elimGauss(A,b) != 0){
        printf("No s'ha pogut realitzar eliminacio gaussiana sense pivotatge.\n");
    }else{
        printf("Matriu triangulada amb m a sota la diagonal inferior:\n");
        printmatrix(A);
        printf("A=LU\nL=\n");
        
        printf("A=LDLt\n");
        printldlt(A);
        printf("\n");
        resolucioLDLt(A,b);
    /*
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
    */
    }
    
    return 0;
} 
