#include <assert.h>
#include <stdlib.h>
#include <string.h>

char *reverse_copy(const char *s){
    char *new = malloc(strlen(s)*sizeof(char));
    for(int i=0;i<strlen(s);i++){
        new[i]=s[strlen(s)-1-i];
    }
    return new;
}
