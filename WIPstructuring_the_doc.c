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


struct word get_word(char* text)
{
    int i = 0;
    while(text[i] != ' ' && text[i] != '.')//word ends in either a ' ' or a '.'
    {
        i++;
    }
    
    struct word w = {calloc(i+1, sizeof(char))}; //account for null terminator
    memcpy(w.data, text, i); //copy word chars
    return w;
}


struct sentence get_sentence(char* text)
{
    struct sentence s = {calloc(100, sizeof(struct word)), 100};
    int i = 0, words = 0;
    while(text[i] != '.') // every sentence ends in a '.'
    {
        if(i==0)//words start at the beginning of a sentence
        {
            s.data[words] = get_word(&text[i]);
            words++;
        }
        else if (text[i] == ' ')//or with a ' '
        {
            s.data[words] = get_word(&text[i+1]);//start of a new word is after ' '
            words++;
        }

        i++;
    }
    
    //s.data = realloc(s.data, words * sizeof(struct word));
    s.word_count = words;
    return s;
}


struct paragraph get_paragraph(char* text)
{
    struct paragraph p = {calloc(30, sizeof(struct sentence)), 30};
    int i=0, sentences=0;
    while(text[i] != '\n' && text[i] != '\0') //paragraphs end with either a '\n' or a '\0'
    {
        if(i == 0)//first sentence
        {
            p.data[sentences] = get_sentence(&text[i]);
            sentences++;
        }
        //periods not followed by a newline (end of paragraph) or '\0' (end of doc) are new sentences
        else if(text[i] == '.' && text[i+1] != '\n' && text[i+1] != '\0' )
        {
            p.data[sentences] = get_sentence(&text[i+1]); //start of a new sentence
            sentences++;
        }
        
        i++;
    }
    
    //realloc to actual sentence count
    //p.data = realloc(p.data, sentences * sizeof(struct sentence));
    p.sentence_count = sentences;
    return p;
}


struct document get_document(char* text) {
    struct document doc = {calloc(5, sizeof(struct paragraph)), 5};
    int i = 0, paragraphs = 0;
    while(text[i] != '\0')
    {
        if(i == 0)//first paragraph
        {
            doc.data[paragraphs] = get_paragraph(&text[i]);
            paragraphs++;
        }
        else if (text[i] == '\n')//last paragraph doesn't end in '\n'
        {
            doc.data[paragraphs] = get_paragraph(&text[i+1]); //the start of a new paragraph
            paragraphs++;
        }

        i++;
    }
    
    //doc.data = realloc(doc.data, paragraphs * sizeof(struct paragraph));
    doc.paragraph_count = paragraphs;
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
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
