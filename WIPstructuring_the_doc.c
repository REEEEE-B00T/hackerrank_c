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
    int i=0;
    while(text[i] != ' ' || text[i] != '.')
    {
        i++;
    }
    
    struct word w = {calloc(i, sizeof(char))};
    memcpy(w.data, text, i-1);
    return w;
}


struct sentence get_sentence(char* text)
{
    struct sentence s = {calloc(1000 * sizeof(char*), 1000)};
    int i = 0, words = 0;
    while(text[i] != '.')
    {
        if(text[i] == ' ')
        {
            struct word w = get_word(&text[i]);
            s.data[words] = w;
            words++;
        }
        
        i++;
    }
    
    s.data = realloc(s.data, sizeof(struct word) * words);
    s.word_count = words;
    return s;
}


struct paragraph get_paragraph(char* text)
{
    
    struct paragraph p = {calloc(1000, sizeof(struct sentence)), 1000};
    
    int i=0, sentence_count=0;
    
    while(text[i] != '\n' || text[i] != '\0')
    {
        if(text[i] == '.')
        {
            struct sentence s  = get_sentence(&text[i]);
            p.data[sentence_count] = s;
            sentence_count++;
        }
        
        i++;
    }
    
    //realloc actual sentence count
    p.data = realloc(p.data, sizeof(struct sentence) * sentence_count);
    p.sentence_count = sentence_count;
    return p;
}


struct document get_document(char* text) {
    struct document doc = {calloc(5, sizeof(struct paragraph)), 5};
    
    int i = 0, paragraphs = 0;
    while(text[i] != '\0')
    {
       //new paragraph
       if(i==0 || text[i] == '\n')
       {
           struct paragraph p = get_paragraph(&text[i]);
           doc.data[paragraphs] = p;
           paragraphs++;
       }
       i++;
    }
    
    doc.data = realloc(doc.data, sizeof(struct paragraph) * paragraphs);
    doc.paragraph_count = paragraphs;
    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n].data[m].data[k];
}
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m].data[k];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k];
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
