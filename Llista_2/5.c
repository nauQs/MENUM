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

int main(void)
{
    double **A, **LDLt, suma;
    int i, j, k;
    tolerancia = 1.e-14;
    /*Llegim A*/
    printf("Escriu l'enter n:");
    scanf("%d", &n);
    LDLt = (double **)malloc(n*sizeof(double*));
    A = (double **)malloc(n*sizeof(double*));
    for(i=0;i<n;i++){
        LDLt[i] = (double *)malloc(n*sizeof(double));
        A[i] = (double *)malloc(n*sizeof(double));
        for(j=0;j<n;j++){
        printf("Escriu A%d%d:",i,j);
        scanf("%le", &A[i][j]);
        }
    }
    
    LDLt[0][0] = A[0][0];
    for(i=1;i<n;i++){
        LDLt[i][1] = A[i][1]/A[0][0];
    }
    for(j=1;j<n-1;j++){
        suma= 0.;
        for(k=0;k<j-1;k++){
            suma += LDLt[j][k]*LDLt[j][k]*LDT[k][k];
        }
        LDTL[j][j]= A[j]A[j] - suma;
        
        for(i=j;i<n;i++){
            suma= 0.;
            for(k=0;k<j-1;k++){
                suma += LDLt[i][k]*LDLt[k][k]*LDLt[j][k];
            }
            LDLt = (A[i][j]-suma)/LDLt[j][j];
    }
    suma= 0.;
    for(k=0;k<n-1;k++){
        suma+= LDLt[n][k]*LDLt[n][k]*LDLt[k][k]
    }
    LDLt[n-1][n-1] = A[n-1][n-1] - suma;
    
    printmatrix(A);
    printmatrix(LDLt);

    for (i=0; i<n; i++) free(A[i]);
    free(A);
    for (i=0; i<n; i++) free(LDLt[i]);
    free(LDLt);

    
    return 0;
}
