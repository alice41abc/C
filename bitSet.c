#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool contains(unsigned int num, unsigned int len, long int set[len])
{
    for(int i = 0; i< len;i++) {
        if ((i * 64) <= num && num < (64 * (i + 1))) {
            if (set[i] >> (num-i*64) & 1){
                return true;
            }
            break;
        }
    }
    return false;
}

void setAdd(unsigned int num, unsigned int len, long int set[len])
{
    long int pow=1;
    for(int i = 0; i < len;i++) {
        if (i*64 <= num && num < 64 * (i + 1)) {
            if(num==((i+1)*64-1)){

            }
            if(num!=64*i) {
                for (int j = 0; j < (num - i * 64); j++) {
                    pow *= 2;
                }
            }
            set [i]+=pow;
            break;
        }
    }
}

void setRemove(unsigned int num, unsigned int len, long int set[len])
{
    long int pow=1;
    for(int i = 0; i < len;i++) {
        if (i*64 <= num < 64 * (i + 1)) {
            if(num!=64*i && contains(num,len,set)==1) {
                for (int j = 0; j < (num - i * 64); j++) {
                    pow *= 2;
                }
                set[i] -= pow;
                break;
            }
        }
    }
}


int main(void) {
    const unsigned int SIZE = 4;
    long int set[4] = {0, 0, 0, 0};

    assert(contains(5, SIZE, set)==false);
    setAdd(5, SIZE, set);
    assert(contains(5, SIZE, set)==true);

    setAdd(127, SIZE, set);
    setAdd(203, SIZE, set);
    setAdd(0, SIZE, set);
    setAdd(128, SIZE, set);

    assert(contains(5, SIZE, set)==true);
    assert(contains(127, SIZE, set)==true);
    assert(contains(203, SIZE, set)==true);
    assert(contains(0, SIZE, set)==true);
    assert(contains(128, SIZE, set)==true);

    setRemove(5, SIZE, set);
    assert(contains(5, SIZE, set)==false);
}
