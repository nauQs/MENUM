/*
*/

#include<stdio.h>    
#include<stdlib.h>  
#include <time.h>  
#include <math.h>

int main(void){
    double *diagonal,*superdiagonal,*subdiagonal,*b;
    int n, i;
    
    printf("Digues n: ");
    scanf("%d",&n);
    
    diagonal = (double*)malloc(n*sizeof(double));
    superdiagonal = (double*)malloc((n-1)*sizeof(double));
    subdiagonal = (double*)malloc((n-1)*sizeof(double));
    b = (double*)malloc(n*sizeof(double));

    
    for(i=0;i<n;i++){
        printf("Escriu l'element %d de b :",i+1);
        scanf("%le", &b[i]);
    }
    for(i=0;i<n;i++){
        printf("Escriu l'element %d de diagonal :",i+1);
        scanf("%le", &diagonal[i]);
    }
    for(i=0;i<n-1;i++){
        printf("Escriu l'element %d de superdiagonal :",i+1);
        scanf("%le", &superdiagonal[i]);
    }
    for(i=0;i<n-1;i++){
        printf("Escriu l'element %d de subdiagonal :",i+1);
        scanf("%le", &subdiagonal[i]);
    }
    
    superdiagonal[0]= superdiagonal[0]/diagonal[0];
    for(i=1;i<n-1;i++){
        superdiagonal[i]= superdiagonal[i]/ (diagonal[i] - superdiagonal[i-1]*subdiagonal[i-1]);
    }
    
    b[0]=b[0]/diagonal[0];
    for(i=1;i<n;i++){
        b[i]= (b[i]-b[i-1]*subdiagonal[i-1])/(diagonal[i] - superdiagonal[i-1]*subdiagonal[i-1]);
    }
    
    for(i=n-2;i>=0;i--){
        printf("b[%d]: %le \n",i,b[i]);
        b[i]=b[i]-superdiagonal[i]*b[i+1];
    }
    
    for(i=0;i<n;i++){
        printf("x%d: %le \n",i,b[i]);
    }
    
    free(superdiagonal);
    free(diagonal);
    free(subdiagonal);
    free(b);
    
    return 0;
}
