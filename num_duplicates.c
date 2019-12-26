#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define CHAR_POSS 256

int num_of_duplicates(const char *s){
    int count=0;
    unsigned char *new=malloc(sizeof(char)*(5000000));
    for(int i =0;i<strlen(s);i++){
        new[i]=s[i];
    }

    for(int i=0;i<strlen(s);i++){
        for(int j=0;j<strlen(s);j++){
            if(i!=j&&s[i]==new[j]){
                count++;
                new[i]='\0';
                for(int k=0;k<strlen(s);k++){
                    if(k!=i&&s[i]==new[k]){
                        new[k]='\0';
                    }
                }
            }
        }
    }
    free(new);
    return count;
}
