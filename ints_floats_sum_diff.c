#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	
    int a,b;
    float f,g;
    
    scanf("%d%d%f%f", &a,&b,&f,&g);
    
    printf("%d %d\n%.1f %.1f", a+b, a-b, f+g, f-g);
    
    return 0;
}
