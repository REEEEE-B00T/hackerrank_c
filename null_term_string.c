#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for(int i=0; i<1024; i++)
    {
        if(s[i] == ' ') // print newline instead of space
        {
            printf("%c", '\n');
        }
        else if(s[i] == '\0') // null terminated
        {
            break;
        }
        else //print char stream
        {
            printf("%c", s[i]);
        }
    }
    //Write your logic to print the tokens of the sentence here.
    return 0;
}
