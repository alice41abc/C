#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *reverse_copy(const char *s){
    char *new = malloc(strlen(s)*sizeof(char));
    for(int i=0;i<strlen(s);i++){
        new[i]=s[strlen(s)-1-i];
    }
    return new;
}

int main(void){
    unsigned char a [6] = "banana";
    printf("%s\n",reverse_copy(a));

    unsigned char b [13] = "Y17899==))...";
    printf("%s\n",reverse_copy(b));

    unsigned char c [44] = "the quick brown fox jumps over the lazy dog.";
    printf("%s",reverse_copy(c));
    
    return 0;
}
