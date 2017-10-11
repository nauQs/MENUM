/* rang.c
Aquest programa, quan arriba a l'enter més gran que pot guardar en format int, pararà de sumar, i mostrarà per pantalla el més gran possible, i el que passa quan li sumem +1 al nombre més gran possible.
Per fer-ho utilitzarem un while que continuarà fins que el nombre n sigui més petit o igual que l'anterior.
*/

#include <stdio.h> 
#include <math.h> 
#include <limits.h>

int main(void)
{
   int k, a;
   float s;
   double b;
   b=0.;
   s=0.;
   a=10;
   for(k=1; k <INT_MAX-10; k++){
       s+=1./k;
   }
   for(k=INT_MAX-10; k < INT_MAX; k++){
       s+=1./k;
       printf("%d. Successio = %f \n", a, s);
       a--;
   }
   printf("------ \n");
   a=10;
   s=0.;
   for(k=INT_MAX; k >10; k--){
       s+=1./k;
   }
   
   for(k=10; k >=1; k--){
       s+=1./k;
       printf("%d. Successio inversa= %f \n", a, s);
       a--;
   }
   
   printf("------ \n");
   for(k=1; k <INT_MAX; k++){
       b+=1./pow(k,2);
   }
   printf("Segona successio = %f \n", b);
   return 0;
}
