#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char int_to_char(int a)
{
    return a + 48;
}

int main() {
    char input[1000];
    fgets(input, 1000, stdin);
    
    for(int i=0; i<10; i++)
    {
        int count = 0;
        int index = 0;
        while(!(input[index]== '\0'))
        {          
            if(input[index] == int_to_char(i))
            {
                count++;
            }
            
            index++;
        }
        
        printf("%d", count);
        if(i < 9)
        {
            printf("%c", ' ');
        }     
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
