#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *largest_square(const char *s){
    char * new = calloc(strlen(s)/2 + 1, sizeof(char));
    int count = 0;
    int num = 0;
    for(int i = (strlen(s)/2);i > 0;i--){
        for(int j = 0;j <= strlen(s)-i*2;j++){
            count = 0;
            num = 0;
            for(int k = 0;k <= strlen(s)/2;k++){
                new[k]=0;
            }
            for(int k = j+i;k < j + 2 * i;k++){
                if(s[j+num] == s[k]){
                    new[num++] = s[k];
                    count++;
                }
            }
            if(count == i){
                new[num] = '\0';
                return new;
            }
        }
    }
    return new;
}

int main(void){
    unsigned char a [6]= "banana";
    printf("%s\n",largest_square(a));

    unsigned char b [13]= "YY11899==)...";
    printf("%s\n",largest_square(b));

    unsigned char c [48]= "the the quick brown fox jumps over the lazy dog.";
    printf("%s\n",largest_square(c));

    unsigned char d [100]= "the police police police the police police police the police police";
    printf("%s\n",largest_square(d));
    return 0;
}

