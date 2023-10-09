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
struct word get_word(char *text, int begin_idx )
{  
    struct word w = {&text[begin_idx]};
    return w;
}

struct sentence get_sentence(char* text, int begin_idx)
{
    struct sentence s = {malloc(1000 * sizeof(struct word)), 0};
    
    //construct words
    int word_count = 0;
    int i = begin_idx;
    while(text[i] != '.')
    {
        if(i == begin_idx) 
        {  
            s.data[word_count] = get_word(text, i);
            word_count++;
        }
        else if(text[i] == ' ')
        {
            s.data[word_count] = get_word(text, i+1);
            word_count++;
        }
        
        i++;
    }
    
    s.data = realloc(s.data, word_count * sizeof(struct word));
    s.word_count = word_count;
    return s;  
}

struct paragraph get_paragraph(char* text, int begin_idx)
{
    struct paragraph p = {malloc(1000 * sizeof(struct sentence)), 0};
    
    //construct sentences
    int sentence_count = 0;
    int i = begin_idx;
    while(text[i] != '\n' && text[i] != '\0')
    {
        if(i == begin_idx)
        {
            p.data[sentence_count] = get_sentence(text, i);
            sentence_count++;
        }
        else if(text[i] == '.' && text[i+1] != '\n' && text[i+1] != '\0') //have to make sure we're not at the boarder of the document or paragraph
        {
            p.data[sentence_count] = get_sentence(text, i+1);
        }   sentence_count++;
        
        i++;
    }
    
    p.data = realloc(p.data, sentence_count * sizeof(struct sentence));
    p.sentence_count = sentence_count;
    return p;  
}

struct document get_document(char* text) {
    struct document d = {malloc(5 * sizeof(struct paragraph)), 0};
    
    //construct paragraphs
    int paragraph_count = 0;
    int i = 0;
    while(text[i] != '\0')
    {
        if(i == 0)
        {
            d.data[paragraph_count] = get_paragraph(text, i);
            paragraph_count++;
        }
        else if(text[i]=='\n') //this is okay because the last paragraph doesn't end with a newline
        {
            d.data[paragraph_count] = get_paragraph(text, i+1);
            paragraph_count++;
        }
        
        i++;
    }

    d.data = realloc(d.data, paragraph_count * sizeof(struct paragraph));
    d.paragraph_count = paragraph_count;
    return d;
    
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
