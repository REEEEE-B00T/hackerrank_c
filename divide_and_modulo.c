#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n, decakilos, kilos, hundos, tens, singles;
    scanf("%d", &n);
    
    
    //Complete the code to calculate the sum of the five digits on n.
    decakilos = n / 10000;
    kilos = (n / 1000) % 10;
    hundos = (n / 100) % 10;
    tens = (n / 10) % 10;
    singles = n % 10; 
    
    printf("%d", decakilos+kilos+hundos+tens+singles);
    return 0;
}
