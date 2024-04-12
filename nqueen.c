#include <stdio.h>
#include <math.h>
#define N 4

int place(int k, int n, int* x);
void nqueen(int k, int n, int* x, int board[N][N]);
void printSolution(int board[N][N]);

int place(int k, int n, int* x) {
  for (int i = 0; i < k; i++) {
    if ((x[i] == x[k]) || abs(x[i] - x[k]) == abs(i - k)) { // same column or same diagonal
      return 0;
    }
  }
  return 1;
}

void nqueen(int k, int n, int* x, int board[N][N]) {
  for (int i = 0; i < n; i++) {
    x[k] = i;
    if (place(k, n, x)) {
      if (k == n - 1) {
        for (int j = 0; j < n; j++) {
          board[j][x[j]] = 1;
        }
        printSolution(board);
        for (int j = 0; j < n; j++) {
          board[j][x[j]] = 0; // Reset the board for next solution
        }
      } else {
        nqueen(k + 1, n, x, board);
      }
    }
  }
}

void printSolution(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j]) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int n = N;
  int x[N] = {0}; // Initialize x array with 0s
  int board[N][N] = {{0}}; // Initialize board

  nqueen(0, n, x, board);
  return 0;
}
