#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool checkSudoku(int sudoku[9][9]){


    for(int i =0; i<9;i++){
        for(int j = 0;j<9;j++) {
            for (int l = 1; l < 8; l++) {
                int box[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
                int x = 0;
                if (i % 3 == 0 && j % 3 == 0) {
                    for (int t = i; t < i + 3; t++) {
                        for (int y = j; y < j + 3; y++) {
                            box[x] = sudoku[t][y];
                            x++;
                        }
                    }

                    for (int r = 0; r < 9; r++) {
                        for (int u = 0; u < 9; u++) {
                            if (box[r] != 0 && box[r] == box[u] && u != r)
                                return false;
                        }
                    }

                }


                if (l != i && sudoku[i][j] == sudoku[l][j]) {
                    if (sudoku[i][j] != 0) {
                        return false;
                    }
                }

                if (l != j && sudoku[i][j] == sudoku[i][l]) {
                    if (sudoku[i][j] != 0) {
                        return false;
                    }
                }
            }
        }
            }


    return true;
}

