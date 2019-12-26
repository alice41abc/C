#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int num_of_duplicates(const char *s){
    int count = 0; //initialize count to 0
    unsigned char *new = malloc(sizeof(char)*(5000000)); //malloc array
    for(int i = 0;i < strlen(s);i++){
        new[i] = s[i]; //duplicate array
    }

    for(int i = 0;i < strlen(s);i++){ //index counter for char array pointer s
        for(int j = 0;j < strlen(s);j++){ //index counter for char pointer new
            if(i != j && s[i] == new[j]){
                count++; //duplicate of s[i] appears and count increases by 1
                new[i] = '\0'; //turn duplicates of s[i] to null
                
                for(int k = 0;k < strlen(s);k++){
                    if(k != i && s[i] == new[k]){
                        new[k] = '\0'; //searches for other duplicates of s[i] and turns them to null
                    }
                }
            }
        }
    }
    free(new);
    return count;
}

int main(void){
    unsigned char a [6] = "banana";
    printf("%d\n",num_of_duplicates(a));

    unsigned char b [13] = "Y17899==))...";
    printf("%d\n",num_of_duplicates(b));

    unsigned char c [44] = "the quick brown fox jumps over the lazy dog.";
    printf("%d\n",num_of_duplicates(c));
    return 0;
}
