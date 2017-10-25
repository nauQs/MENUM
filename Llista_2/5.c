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
    double **A, **L, **D, suma;
    int i, j, k;
    tolerancia = 1.e-14;
    /*Llegim A*/
    printf("Escriu l'enter n:");
    scanf("%d", &n);
    L = (double **)malloc(n*sizeof(double*));
    D = (double **)malloc(n*sizeof(double*));
    A = (double **)malloc(n*sizeof(double*));
    for(i=0;i<n;i++){
        L[i] = (double *)malloc(n*sizeof(double));
        D[i] = (double *)malloc(n*sizeof(double));
        A[i] = (double *)malloc(n*sizeof(double));
        for(j=0;j<n;j++){
        printf("Escriu A%d%d:",i,j);
        scanf("%le", &A[i][j]);
        }
    }
    
    D[0][0] = A[0][0];
    for(i=1;i<n;i++){
        L[i][1] = A[i][1]/D[0][0];
        printf("%le",L[i][1]);
    }
    
    for(j=1;j<n-1;j++){
        suma= 0.;
        for(k=0;k<j-1;k++){
            suma += L[j][k]*L[j][k]*D[k][k];
        }
        D[j][j]= A[j][j] - suma;
        
        for(i=j;i<n;i++){
            suma= 0.;
            for(k=0;k<j-1;k++){
                suma += L[i][k]*D[k][k]*L[j][k];
            }
            L[i][j] = (A[i][j]-suma)/D[j][j];
        }
    }
    
    suma= 0.;
    for(k=0;k<n-1;k++){
        suma+= L[n-1][k]*L[n-1][k]*D[k][k];
    }
    D[n-1][n-1] = A[n-1][n-1] - suma;
    
    printmatrix(A);
    printmatrix(L);
    printmatrix(D);

    for (i=0; i<n; i++) free(A[i]);
    free(A);
    for (i=0; i<n; i++) free(L[i]);
    free(L);

    
    return 0;
}
