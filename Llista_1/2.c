/*
*/

#include <stdio.h> 
#include <math.h> 

int main(void)
{
    
    for (double x=1./8; x<8.; x=x+0.1) {
        float y=x;
        printf("error=%+.16le\n", y-x);
    }

   return 0;
}
