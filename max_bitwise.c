#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n+1; j++)
        {    
            int b_and = i & j;
            int b_or = i | j;
            int b_xor = i ^ j;
            
            max_and = b_and > max_and && b_and < k ? b_and : max_and;
            max_or = b_or > max_or && b_or < k ? b_or : max_or;
            max_xor = b_xor > max_xor && b_xor < k ? b_xor : max_xor;
        }
        
    }
    
    printf("%d\n%d\n%d", max_and, max_or, max_xor);

  //Write your code here.
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
