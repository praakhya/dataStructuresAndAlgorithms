#include <stdio.h>
#include <math.h> 
const int maxN=10;
int board[maxN];
int place(int row, int col) {
    for (int i=0; i<row; ++i) {
        if (board[i]==col) {
            return 0;
        }
        else if (abs(board[i]-col) == abs(i-row)) {
            return 0;
        }
    }
    return 1;
}
void nQueens(int row, int n) {
    for (int col=1; col<n; ++col) {
        if (place(row,col)) {
            board[row] = col;
            if (row = n) {
                printf(n);
            }
            else {
                nQueens(row+1, n);
            }
        }
    }
}
int main() {
    
}