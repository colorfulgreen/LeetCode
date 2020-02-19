#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 62

int Hash(char c) {
    if(c >= 'a' && c <= 'z')
        return c - 'a';
    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 26;
    return -1;
}

int numJewelsInStones(char * J, char * S){
    int table[TABLE_SIZE];
    int i;
    for(i = 0; i < TABLE_SIZE; i++) 
        table[i] = 0;
    for(i = 0; i < strlen(J); i++) 
        table[Hash(J[i])] = 1;
    int num = 0;
    for(i = 0; i < strlen(S); i++)
        num += table[Hash(S[i])];
    return num;
}

int main(void) {
    char *J = "aA";
    char *S = "aAAbbbb";
    int num = numJewelsInStones(J, S);
    printf("%d\n", num);
    return 0;
}
