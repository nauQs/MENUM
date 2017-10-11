/* 
*/

#include <stdio.h> 
#include <math.h> 
#include <limits.h>

int main(void)                                                                      
{
    int i;
    double c, y, min, max;
    
    c=18071996./1e+7;
    y = (1./c)*log((c+7)/7);
    printf("y0 = %+.10le \n", y);
    for(i=1; i<=40; i++){
        y = (1./c)*((1./i)-7*y);
        min = 1./((7+c)*(i+1));
        max = 1./((7*(i+1)));
        printf("y%2d = %+.10le; min=%+.6le; max=%+.6le\n", i, y, min, max);
        
    }
    
    y= 0;
    printf("\n\ny80 = %f \n", y);
    for(i=79; i>=30; i--){
        y = (1./7)*(1./(i+1)-c*y);
        min = 1./((7+c)*(i+1));
        max = 1./((7*(i+1)));
        printf("y%2d = %+.10le; min=%+.6le; max=%+.6le\n", i, y, min, max);
    }
  
   return 0;
}
