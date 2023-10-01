#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch[3]; // char, newline, null
    char word[100];
    char sentence[100];
    
    fgets(ch, 3, stdin);
    fgets(word, 100, stdin);
    fgets(sentence, 100, stdin);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    printf("%s%s%s", ch, word, sentence);
    return 0;
}
