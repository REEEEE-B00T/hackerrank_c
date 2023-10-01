#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    //the cheeky solution would have just been to change their code to insert into the array backwards :p
    
    
    // 0 1   2
    // 1 2 | 3 4 5
    // 1 2 | 3 4
    // stop needs to be midway

    for(int i=0; i<num/2; i++)
    {
        int temp_a = arr[i];
        int temp_b = arr[num-1-i]; // num - 1 is end of array. we need to work backwards in sync with index.
        arr[i] = temp_b;
        arr[num-1-i] = temp_a;
        
    }
    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
