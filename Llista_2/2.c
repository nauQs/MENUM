/* 
Resolucio sistemes d'equacions amb pivotatge parcial
*/

#include<stdio.h>    
#include<stdlib.h>  
#include<time.h>
#include<math.h>

int main(void)
{
    double **A, *aux, a, m, sum;
    int n, i, j, k, l, t, it, jt, r;
    clock_t init, fint;

    srand( time(NULL) );
    printf("Introdueix n: ");
    scanf("%d", &n);
    
    /*Reservem memoria per la matriu*/
    A = (double **)malloc( n*sizeof(double *) );
    if ( A==NULL) return 2;
    for (i=0; i<n; i++) {
        A[i] = (double *)malloc( (n+1)*sizeof(double) );
        if ( A[i]==NULL) return 3; 
    }
    
    /*Emplenem la matriu*/
    for (i=0; i<n; i++) {
        for (j=0; j<n+1; j++){
            if(j!=n){
                printf("Introdueix A%d%d ",i,j);
                scanf("%lf", &a);
            }else{
                printf("Introdueix C%d ",i);
                scanf("%lf", &a);
            }
            A[i][j] = a;
        } 
    }
    
    /*Eliminacio Gauss*/
    for (k=0; k<n-1; k++) {
        /*Pivotatge
        for(l=0; l<n; l++){
            for(it=k+1, r=k; it<n; it++){
              if(fabs(A[it][k])>fabs(A[r][k])){
                  r=i;
              }  
            } 
            if(r!=k){
                aux=A[r];
                A[r]=A[k];
                A[k]=aux;
            }
        }
        Final pivotatge*/
        if(fabs(A[k][k])<1.e-14) return 1;
        for (i=k+1; i<n; i++) {
            m = A[i][k]/A[k][k]; 
            for (j=k; j<n+1; j++){
                A[i][j]= A[i][j] - m*A[k][j];
            }
        }
    }
    
    /*Imprimim la matriu*/
    for (i=0; i<n; i++) {
        for (j=0; j<n+1; j++){
            printf("%2lf ",A[i][j]);
        } 
        printf("\n");
    }
    
    /*Resolem la matriu superior triangular*/
    for(i=n-1; i>=0; i--){
		for(j=i+1, sum=0.; j<n; j++){
           sum+=A[i][j]*A[j][n]; 
        } 
        A[i][n]=1./A[i][i]*(A[i][n]-sum);
    }
    
    /*Imprimim les solucions*/
    for (i=0; i<n; i++) {
        printf("x%1d: %4lf ",i,A[i][n]);
        printf("\n");
    }
    
    /*Alliberem memoria matriu*/
    for (i=0; i<n; i++) free(A[i]);
    free(A);

    return 0;

}