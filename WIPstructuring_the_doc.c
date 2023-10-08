#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct word *get_word(char *text, int begin_idx)
{  
    struct word w = {malloc(sizeof(char*))};
    {&char[begin_idx]}; 
    return &word;
    
}

struct sentence *get_sentence(char* text, int begin_idx)
{
    int i = begin_idx;
    int word_count = 1;
    while(text[i] != ".")
    {
        if(text[i] == ' ')
        {
            struct word *w = get_word(text, i);
        }
    }
    
    struct structure s = {malloc(wordcount * sizeof(word*)), word_count};
    return &s;  
}

struct paragraph get_paragraph(char* text, int begin_idx)
{
    int i = begin_idx;
    int sentence_count = 1;
    while(text[i] != "\n" || text[i] != "\0")
    {
        if(text[i] == ' ')
        {
            struct word *w = get_word(text, i);
        }
    }
    
    struct structure s = {malloc(wordcount * sizeof(word*)), word_count};
    return &s;  
}

struct document get_document(char* text) {
    // create nulled array of 5 placeholder pointers for up to 5 paragraph struct pointers
    struct paragraph *paragraphs = calloc(5 * sizeof(paragraph*));
    
    int paragraph_count = 0;
    
    // count paragraphs and set pointers
    int i = 0;
    while(text[i] != '\0')
    {
        // we've encountered a new paragraph
        if(i==0 || text[i-1] == '\n')
        {             
            //initialize paragraph struct
            struct paragraph p = {&text[i], 0}
            //set pointer corresponding to paragraph count to struct
            paragraphs[paragraph_count] = &p; 
            //increase paragraph count
            paragraphs++;
             
             
            int cur_para_sentences = 0;
            struct paragraph p = {}
            
            while(text[i] != '.')
            {
                if(text[j] == ' ')
            }
            //set pointer to paragraph start location;
                   
        }
            
        i++;
    }
    
    //count sentences
    for(int i=0; i < paragraph_count; i++)
    {
        int paragraph_char_offset = 0;
        int sentence_count = 0;
        while(paragrahs[i][paragraph_char_offset] != '\n')
        {
            if(paragraphs[i].data[paragraph_char_offset] == '.')
            {
                
            }
        }
        
    }
    
    
    struct document doc = {paragraphs, paragraph_count};
    
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 

}

struct paragraph kth_paragraph(struct document Doc, int k) {

}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
