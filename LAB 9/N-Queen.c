#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;
int solutionCount = 0;

void printBoard() {
    int i, j;
    printf("\nSolution %d:\n\n", solutionCount);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i, j;
    for(i = 0; i < col; i++) {
        if(board[row][i])
            return 0;
    }
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j])
            return 0;
    }
    for(i = row, j = col; i < N && j >= 0; i++, j--) {
        if(board[i][j])
            return 0;
    }
    return 1;
}
void solveNQueen(int col) {
    if(col == N) {
        solutionCount++;
        printBoard();
        return;
    }
    int i;
    for(i = 0; i < N; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            solveNQueen(col + 1);
            board[i][col] = 0;
        }
    }
}
int main() {
    int i, j;
    printf("Enter number of queens: ");
    scanf("%d", &N);

    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    solveNQueen(0);
    if(solutionCount == 0) {
        printf("No solution exists.\n");
    }
    else {
        printf("\nTotal Solutions = %d\n", solutionCount);
    }
    return 0;
}