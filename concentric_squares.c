#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int matrix_width(int n)
{
    return ((n*2) -1);
}

int offset(int outermost_number, int working_offset)
{
    return outermost_number - working_offset;    
}

void initialize_matrix(int **matrix, int width, int n)
{
    for(int i=0; i < width; i++)
    {
        for(int j=0; j < width; j++)
        {
            matrix[i][j] = n;
        }
    }
}

void print_matrix(int **matrix, int width, int n)
{
    for(int i=0; i < width; i++)
    {
        for(int j=0; j < width; j++)
        {
            printf("%d", matrix[i][j]);
            if(j == (width-1))
            {
                printf("%c", '\n');
            }
            else {
                printf("%c", ' ');
            }
        }
    }
}

void step_down_matrix(int **matrix, int matrix_width, int outermost_number, int working_offset)
{
    int _offset = offset(outermost_number, working_offset);
    for(int i = _offset; i < matrix_width - _offset; i++)
    {
        for(int j = _offset; i < matrix_width - _offset; i++)
        {
            matrix[i][j] -= 1;
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    int width = matrix_width(n);
    int **matrix = malloc(width * sizeof(int*));
    for(int i=0; i<width; i++)
    {
        matrix[i] = malloc(width * sizeof(int));
    }
    
    initialize_matrix(matrix, width, n);
    for(int i=n-1; i>0; i--)
    {
        step_down_matrix(matrix, width, n, i);
    }
    
    print_matrix(matrix, width, n);
  	// Complete the code to print the pattern.
    return 0;
}
