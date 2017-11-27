/* Ax = b
 * Dimensio n
 * Llegeix n, A i b
*/

#include<stdio.h>    
#include<stdlib.h>  
#include <time.h>  
#include <math.h>
int n;
double tolerancia;

void printsystem(double** A, double* b){
    int i,j;
    /*UTILITZEM n+1 PER AQUEST PROBLEMA CONCRET, NO REUTILITZAR*/
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            printf("%+.4e    ", A[i][j]);
        }
        printf("|   %+.4e", b[i]);
        printf("\n");
    }
     printf("\n");
}


/*Eliminació Gaussiana amb pivotatge parcial*/
int elimGauss(double**A, double *b){
    double max, m;
    int k,v,i,j;
    /*UTILITZEM n+1 PER AQUEST PROBLEMA CONCRET, NO REUTILITZAR*/
    for(k=0;k<n;k++){
        for(i=k+1;i<n+1;i++){
            /*Calculem mik*/
            m = A[i][k] / A[k][k];
            /*Ja sabem que efectuan la resta a i=k obtenim 0:*/
            A[i][k] = 0;
            /*Per a cada j€{k+1,.....,n} fem la resta corresponent, i també per a bi*/
            for(j=k+1;j<n+1;j++) A[i][j] -= m*A[k][j]; 
            b[i] -= m*b[k];
        }
    }
    return 0;
}
/*Resolució del sistema triangular per substitució endarrera:*/
int resoltriangular(double **A, double *b){
    int i, j;
    double sumatori;
    /*UTILITZEM n+1 PER AQUEST PROBLEMA CONCRET, NO REUTILITZAR*/
    if(fabs(A[n][n]) < tolerancia) return 2;
    b[n] = b[n]/A[n][n];
    for(i=n-1;i>=0;i--){
        /*Sumatori*/
        sumatori = 0;
        for(j=i+1;j<n+1;j++) sumatori += A[i][j]*b[j];
        /*Restem b[i] (és a dir, actualment és ci) - sumatori*/
        b[i] = b[i] - sumatori;
        /*Si Aii es major a la tolerancia, dividim per Aii:*/
        if(fabs(A[i][i]) < tolerancia) return 2;
        b[i] = b[i]/A[i][i];
    }
    return 0;
}
int main(void)
{
    /*AA i bb són còpies de A i b que guardarem per fer la comprovacio b-Ax després (no és part de l'enunciat)*/
   double **A, *f;
   int i, j, index;
   tolerancia = 1.e-12;
   /*Llegim n, xi, fi*/
   printf("Escriu l'enter n:");
   scanf("%d", &n);
   A = (double **)malloc((n+1)*sizeof(double*));
   f = (double *)malloc((n+1)*sizeof(double));
   for(i=0;i<n+1;i++){
       A[i] = (double *)malloc((n+1)*sizeof(double));
       printf("Escriu x%d ",i);
       scanf("%le", &A[i][1]);
       A[i][0]=1;
       for(j=2;j<n+1;j++){
           A[i][j] = A[i][1] * A[i][j-1];
        }
       printf("Escriu F%d ",i);
       scanf("%le", &f[i]);
   }
    
    printf("\nResolem el sistema seguent:\n");
    printsystem(A,f);

    /*Fem eliminació Gaussiana. A esdevindrà A(k) i b esdevindrà c */
    
    index = elimGauss(A,f);
    if(index!=0){
        printf("No s'ha pogut triangular la matriu!\n");
        return index;
    };

    /*Fem sustitució triangular. c esdevindrà x (solucio)*/
    
    index = resoltriangular(A,f);
    if(index != 0){
        printf("No s'ha pogut realitzar substitució endarrera!\n");
        return index;
    }
    
    /*Imprimim les solucions*/
    printf("Solucions:\n");
    for(i=0;i<n+1;i++){
        printf("a%d = %+.4e\n", i, f[i]);
    }
    
    /*Imprimim el polinomi interpolador*/
    printf("\nPolinomi interpolador:\n");
    if(fabs(f[n]) > tolerancia){
        printf("%.2f*x^%d ",f[n], n);
    }
    for(i=n;i>=1;i--){
        if(fabs(f[i]) > tolerancia){
            printf("+ %.2f*x^%d ", f[i], i);
        }
    }
    if(fabs(f[i]) > tolerancia){
        printf("+ %.2f ", f[i]);
    }
    printf("\n\n");
    
    return 0;
}

