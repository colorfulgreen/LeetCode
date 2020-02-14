#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char * s, char * t){
    if(s == NULL || *s == '\0')
        return true;
    if(t == NULL || *t == '\0')
        return false;

    char *ps = s, *pt = t;
    while(*pt != '\0') {
        if(*ps == *pt) 
            ps++;
        if(*ps == '\0')
            return true;
        pt++;
    }
    return false;
}

int main(void) {
    char *s = "axc";
    char *t = "ahbgdc";
    bool r = isSubsequence(s, t);
    printf("%d\n", r);
    return 0;
}


