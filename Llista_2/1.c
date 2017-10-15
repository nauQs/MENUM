/* Ax+y.c 
CAlcul de l'ActuAlitzAcio y <- y+Ax
A mxn, x nx1, y mx1
Dos Algorismes: orientAt per files / orientAt per columnes
GenerAcio AleAtoriA de dAdes
Temps d'execucio
*/

#include<stdio.h>    
#include<stdlib.h>  
#include <time.h>  

int main(void)
{
   double **A, **B, **C, t;
   int n, i, j, k;
   clock_t init, fint;

   srand( time(NULL) );
   printf("Introdueix n: ");
   scanf("%d", &n);
  
   while (n>0) {

   A = (double **)malloc( n*sizeof(double *) );
   B = (double **)malloc( n*sizeof(double *) );
   C = (double **)malloc( n*sizeof(double *) );
   if ( A==NULL || B==NULL || C==NULL) return 2;
   for (i=0; i<n; i++) {
      A[i] = (double *)malloc( n*sizeof(double) );
      B[i] = (double *)malloc( n*sizeof(double) );
      C[i] = (double *)malloc( n*sizeof(double) );
      if ( A[i]==NULL || B[i]==NULL || C[i]==NULL) return 3; 
   }

   for (i=0; i<n; i++) {
      for (j=0; j<n; j++){
          A[i][j] = ((double)rand())/RAND_MAX;
          B[i][j] = ((double)rand())/RAND_MAX;
      }
   }
       
   for (i=0; i<n; i++) {
      for (j=0; j<n; j++){
                C[i][j]=0;
      }
   }

   /* IJK*/
   init = clock();
   for (i=0; i<n; i++) { 
      for (j=0; j<n; j++) {
          for (k=0; k<n; k++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("IJK: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));

   /* IKJ*/
   init = clock();
   for (i=0; i<n; i++) { 
      for (k=0; k<n; k++) {
          for (j=0; j<n; j++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("IKJ: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));
       
   /*KJI*/   
   init = clock();
   for (k=0; k<n; k++) { 
      for (j=0; j<n; j++) {
          for (i=0; i<n; i++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("KJI: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));
       
    /*KIJ*/   
   init = clock();
   for (k=0; k<n; k++) { 
      for (i=0; i<n; i++) {
          for (j=0; j<n; j++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("KIJ: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));
               
   /*JKI*/   
   init = clock();
   for (j=0; j<n; j++) { 
      for (k=0; k<n; k++) {
          for (i=0; i<n; i++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("JKI: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));
               
   /*JKI*/   
   init = clock();
   for (j=0; j<n; j++) { 
      for (i=0; i<n; i++) {
          for (k=0; k<n; k++){
              C[i][j] += A[i][k]*B[k][j];
          }
      }
   }
   fint = clock();
   t = (double)(fint-init)/CLOCKS_PER_SEC;
   printf("JIK: n=%4d, t=%+8.2f, t/mn= %+.2e\n",n, t, t/(n*n));

   printf("\n");
   
   for (i=0; i<n; i++) free(A[i]);
   free(A);
   for (i=0; i<n; i++) free(B[i]);
   free(B);
   for (i=0; i<n; i++) free(C[i]);
   free(C);
       
   printf("(0 per tancar el programa)\n");
   printf("Introdueix n: ");
   scanf("%d", &n);
   }

   return 0;
}
