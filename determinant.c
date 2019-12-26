#include <assert.h>

long long f(int n, long long C[n][n],int size){

    long long int sum;
    sum = 0;

    if(size==1){
        return C[0][0];
    }

    for(int r =0; r<size; r++){
        long long D[10][10];
        int dc = 0;
        for(int c =0; c<size;c++){
            if (r!=c) {
                for (int i = 1; i < size; i++) {
                    D[dc][i - 1] = C[c][i];
                }
                dc++;
            }
        }

        if (r % 2 == 0) {
            sum += C[r][0] * f(10, D, size - 1);
        } else if (r % 2 != 0) {
            sum += (-1) * C[r][0] * f(10, D, size - 1);
        }
    }
    return sum;


}

long long determinant(int n, int A[n][n]) {
    long long C [10][10];
    for(int r =0; r<n; r++){
        for(int c =0; c<n;c++){
            C[r][c]=A[r][c];
        }
    }
    return f(10,C,n);
}


