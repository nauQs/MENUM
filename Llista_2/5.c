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
    double **A, **LDL, suma;
    int i, j, k;
    tolerancia = 1.e-14;
    /*Llegim A*/
    printf("Escriu l'enter n:");
    scanf("%d", &n);
    LDL = (double **)malloc(n*sizeof(double*));
    A = (double **)malloc(n*sizeof(double*));
    for(i=0;i<n;i++){
        LDL[i] = (double *)malloc(n*sizeof(double));
        A[i] = (double *)malloc(n*sizeof(double));
        for(j=0;j<n;j++){
        printf("Escriu A%d%d:",i,j);
        scanf("%le", &A[i][j]);
        }
    }
    
    LDL[0][0] = A[0][0];
    for(i=1;i<n;i++){
        LDL[i][0] = A[i][1]/LDL[0][0];
    }
    
    for(j=1;j<n-1;j++){
        suma= 0.;
        for(k=0;k<j-1;k++){
            suma += LDL[j][k]*LDL[j][k]*LDL[k][k];
        }
        LDL[j][j]= A[j][j] - suma;
        for(i=j;i<n;i++){
            suma= 0.;
            for(k=0;k<j-1;k++){
                suma += LDL[i][k]*LDL[k][k]*LDL[j][k];
            }
            LDL[i][j] = (A[i][j]-suma)/LDL[j][j];
        }
    }

    suma= 0.;
    for(k=0;k<n-1;k++){
        suma+= LDL[n-1][k]*LDL[n-1][k]*LDL[k][k];
    }
    LDL[n-1][n-1] = A[n-1][n-1] - suma;
    
    
    printmatrix(A);
    printmatrix(LDL);

    for (i=0; i<n; i++) free(A[i]);
    free(A);
    for (i=0; i<n; i++) free(LDL[i]);
    free(LDL);

    
    return 0;
}
