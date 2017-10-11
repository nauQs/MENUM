/* rang.c
Aquest programa, quan arriba a l'enter més gran que pot guardar en format int, pararà de sumar, i mostrarà per pantalla el més gran possible, i el que passa quan li sumem +1 al nombre més gran possible.
Per fer-ho utilitzarem un while que continuarà fins que el nombre n sigui més petit o igual que l'anterior.
*/

#include <stdio.h> 
#include <math.h> 

int main(void)
{
   int n, m;
     
    n=0;
    m=1;
    while(n<m){
        n=m;
        m++;
    }
    printf("n= %d  m= %d \n", n, m);

   return 0;
}
