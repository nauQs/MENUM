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

int main(void)
{
    /*AA i bb són còpies de A i b que guardarem per fer la comprovacio b-Ax després (no és part de l'enunciat)*/
   double *x, *f, a, b, h;
   int i, j, index;
   tolerancia = 1.e-12;
   /*Llegim n, a, b*/
   printf("Escriu l'enter n:");
   scanf("%d", &n);
   printf("Escriu a:");
   scanf("%le", &a);
   printf("Escriu b:");
   scanf("%le", &b);
   h = (b-a)/n;
    
   x = (double *)malloc((n+1)*sizeof(double));
   f = (double *)malloc((n+1)*sizeof(double));
   for(i=0;i<n+1;i++){
       x[i]= a + i*h;
       f[i]= 1./x[i];
   }

   /*Si volem escriure nosaltres la taula de x's i f's...
   for(i=0;i<n+1;i++){
       printf("Escriu x:");
       scanf("%le", &x[i]);
       printf("Escriu f:");
       scanf("%le", &f[i]);
   }*/
    
   for(i=0;i<n+1;i++){
       printf("x=%+.4e, f=%+.4e \n", x[i], f[i]);
   }
    
   /*Fem diferencies dividides*/
    for(i=0; i<n; i++){
        for(j=n-1;j>=i;j--){
            printf("%d,%d",i,j);
            printf("\n(%+.4e-%+.4e)/(%+.4e-%+.4e)= %+.4e\n",f[j+1],f[j],x[j+1],x[j-i],(f[j+1]-f[j]) / (x[j+1]-x[j-i]));
            f[j+1]= (f[j+1]-f[j]) / (x[j+1]-x[j-i]);
        }
    }
    
    /*Imprimim les solucions*/
    printf("Solucions:\n");
    for(i=0;i<n+1;i++){
        printf("c%d = %+.4e\n", i, f[i]);
    }
    
    /*Imprimim el polinomi interpolador
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
    */
    
    return 0;
}

