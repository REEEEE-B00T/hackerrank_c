#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int numbers[n];
    int sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }
    
    printf("%d", sum);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
