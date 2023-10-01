#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int temp_a = *a, temp_b = *b;
    int sum = temp_a + temp_b;
    int diff = (temp_a - temp_b);
    *a = sum;
    *b = diff < 0 ? (diff * -1) : diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
