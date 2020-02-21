#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 997
#define KEY_LEN 9
#define PREFIX "http://tinyurl.com/"
#define PREFIX_LEN strlen(PREFIX)

typedef struct {
    char *values[TABLE_SIZE];
} Table;

Table *table = NULL;

int hash(char *key) {
    unsigned int hashVal;
    while(*key != '\0')
        hashVal = (hashVal << 5) * *key++;
    return hashVal % TABLE_SIZE;
}

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    if(table == NULL)
        table = malloc(sizeof(Table));
    char key[KEY_LEN + 1];
    char *tinyURL = malloc(sizeof(char) * (PREFIX_LEN + KEY_LEN + 1));
    for(int i=0; i<KEY_LEN; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LEN] = '\0';
    table->values[hash(key)] = longUrl;
    tinyURL = strcpy(tinyURL, PREFIX);
    tinyURL = strcat(tinyURL, key);
    return tinyURL;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    char *key = shortUrl + PREFIX_LEN;
    return table->values[hash(key)];
}

int main(void) {
    char *s = encode("https://leetcode.com/problems/design-tinyurl");
    puts(s);
    s = decode(s);
    puts(s);
    return 0;
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
