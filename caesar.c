#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int caesar_decrypter(char *encrypted, char *knownWord) {
    int n=0;
    int count;
    int f=1;
    char *string=(char*)malloc(strlen(encrypted)*sizeof(char));

    for(int j=0;j<strlen(encrypted);j++){
        string[j]=encrypted[j];
    }

    for(int i =1;i<26;i++){

        for(int m=0;m<strlen(encrypted);m++){
            if((string[m]>=65 && string[m]<90)||(string[m]>=97 && string[m]<122)){
                string[m]++;
            } else if(string[m]==90||string[m]==122){
                string[m]-=25;
            }
        }

        for(int j=0;j < strlen(string);j++){
            f=1;
            if(string[j]==knownWord[n]){
                for (int k = j, n=0; n < strlen(knownWord); n++,k++) {
                    if(string[k]!=knownWord[n]){
                        f=0;
                        break;
                    }else if(string[k]==knownWord[n]){
                        continue;
                    }
                }
                if(f) {
                    count = i;
                    free(string);
                    return count;
                }
            }
        }
    }
}

int main(void){
    char orignial []="Hello there!";
    char encrypted []="Lipps xlivi!";
    char known [6]="there";
    printf("%d\n", caesar_decrypter(&encrypted, &known));

    char orignial2 []="There's No Way This Is My Little Sister's";
    char encrypted2 []="Sgdqd'r Mn Vzx Sghr Hr Lx Khsskd Rhrsdq'r";
    known [3]="Can";
    printf("%d\n", caesar_decrypter(&encrypted2, &known));

    return 0;
}


