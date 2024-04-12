#include <stdio.h>
#include <math.h>
// n is the number of queens
// x is the global array to store the column no of the queen in the row i
// j is the previous queen row no and k is next queen row no
// x[j] is the previous queen column no and i is the next queen column no
// Function prototype for place (to avoid implicit declaration warning)
int place(int k, int n, int* x);
void nqueen(int k, int n, int* x, int board[4][4]);
void printSolution(int board[4][4]);

int place(int k, int n, int* x) {
  int i;
  for (int j = 1; j < k; j++) {
    if ((x[j] == i) || abs(x[j] - i) == abs(j - k)) { // same column or same diagonal
      return 0;
    }
  }
  return 1;
}

void nqueen(int k, int n, int* x, int board[4][4]) {
  if (place(k, n, x)) {
    if (k == n) {
      printSolution(board);
    } else {
      nqueen(k + 1, n, x, board); // same row checking
    }
  }
}

void printSolution(int board[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (board[i][j]) {
        printf("Q ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  int n = 4;
  int x[n];
  int board[4][4] = {{0}, {0}, {0}, {0}}; // Initialize board

  nqueen(1, n, x, board);
  return 0;
}