#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void odd_even(int n)
{
    if(n % 2 == 0)
    {
        printf("even");
    }
    else 
    {
        printf("odd");
    }
    
}


int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	for(int i=a; i<b+1; i++)
      {
          switch (i) {
            case 1:
                printf("one");
                break;
            case 2:
                printf("two");
                break;
            case 3:
                printf("three");
                break;
            case 4:
                printf("four");
                break;
            case 5:
                printf("five");
                break;
            case 6:
                printf("six");
                break;
            case 7:
                printf("seven");
                break;
            case 8:
                printf("eight");
                break;
            case 9:
                printf("nine");
                break;
            default:
                odd_even(i);
          }
      printf("%c", '\n');
      }
      
    
    return 0;
}
