#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float calculate_area(triangle *t)
{
    float a = (float)(t->a);
    float b = (float)(t->b);
    float c = (float)(t->c);
    float p = (float)(t->a + t->b + t->c) / (float)2;
    
    float result = sqrt(p*(p-a)*(p-b)*(p-c));
    
    //printf("%f %d %d %d \n", result, t->a, t->b, t->c);
    return result;
}

int compare_areas(const void *a, const void *b)
{
    triangle *t_a = (triangle*)a;
    triangle *t_b = (triangle*)b;
    
    float area_a = calculate_area(t_a);
    float area_b = calculate_area(t_b);
    
    if(area_a > area_b)
    {
        return 1;
    }
    else if(area_a < area_b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void sort_by_area(triangle* tr, int n) 
{
    
	/**
	* Sort an array a of the length n
	*/
    qsort(tr, n, sizeof(triangle), compare_areas);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
