#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define WORDLENGTH 4
#define TABLESIZE 20

typedef struct {
    char word[WORDLENGTH];
    int points;
    char *phrase;
} words;

// declare the hash table as pointer
words *hash_table[TABLESIZE];

int makeHash(char *word) {
    int hash_val = 0;
    for (int i = 0; i < WORDLENGTH; i++) {
        hash_val += (word[i]);
        hash_val = (hash_val  * word[i] * 2 ) % TABLESIZE;
    }
    return hash_val;
}

// initialize all pointers in table to NULL
void init_hash_table() {
    for (int i = 0; i < TABLESIZE; i++) {
        hash_table[i] = NULL;
    }
}

void print_hash() {
    puts("\tWORDS");
    for (int i = 0; i < TABLESIZE; i++) {
        printf("%d\t%s\n", i, hash_table[i]->word); // access fields from pointers to structs
    }
}

bool insert_hash(words *w) {
    // iterate over this in main
    int index = makeHash(w->word);
    if (hash_table[index] != NULL) {
        printf("%s did not succeed\n", w->word);
        return false;
    }
    hash_table[index] = w;
    return true;

}

//lookup!
words *hash_lookup(char *word) {
    int index = makeHash(word);
    if (hash_table[index] != NULL && 
            strncmp(hash_table[index]->word, word, WORDLENGTH) == 0)
    {
        return hash_table[index];
    } else return NULL;
}

int main(void) {
    init_hash_table();
    //print_hash();

    // maybe make a parent struct to hold all of these later...
    words poop = {.word="poop",.points=20,.phrase="nice..."};
    words shit = {.word="shit",.points=40,.phrase="that's a bad word..."};
    words crap = {.word="crap",.points=5,.phrase="that's not a swear"};
    words dung = {.word="dung",.points=50,.phrase="very technical"};
    words turd = {.word="turd",.points=10,.phrase="cheap."};
    words kuso = {.word="kuso",.points=80,.phrase="nihongo ha jouzu!"};
    words fart = {.word="fart",.points=5,.phrase="that's not even poop.."};
    words scat = {.word="scat",.points=60, .phrase="are you a scientist??"};


    //insert_hash(&poop);
    insert_hash(&shit);
    insert_hash(&crap);
    insert_hash(&dung);
    insert_hash(&turd);
    insert_hash(&kuso);
    insert_hash(&fart);
    insert_hash(&scat);

    //print_hash();

    int point_sum = 0; // initialize points
    words *temp;
    while (1) {
        char s[10];
        puts("Guess a 4 character word related to poop: ");
        char *input = fgets(s, sizeof s, stdin);
        if (hash_lookup(input)) {
            temp = hash_lookup(input);
            point_sum += temp->points;
            printf("\n\t\033[96;3m%s\033[0m\nYou have %d points.\n", temp->phrase, point_sum);
        } else puts("\n\t\033[91;1;5mWRONG! ! !\033[0m");
    }
}

