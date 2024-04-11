#include <stdio.h>
#include <math.h>
// n is the number of queens
// x is the global array to store the column no of the queen in the row i
// j is the previous queen row no and k is next queen row no
// x[j] is the previous queen column no and i is the next queen column no
// Function prototype for place (to avoid implicit declaration warning)
int place(int k, int n, int* x);

void nqueen(int k, int n, int* x) {
  if (place(k, n, x)) {
    if (k == n) {
      for (int i = 1; i <= n; i++) {
        printf("%d\t", x[i]);
      }
      printf("\n");
    } else {
      nqueen(k + 1, n, x);//same row checking
    }
  }
}

int place(int k, int n, int* x) {
  int i;
  for (int j = 1; j < k; j++) {
    if ((x[j] == i) || abs(x[j] - i) == abs(j - k)) { // same column or same diagonal
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  printf("Enter the number of queens: ");
  scanf("%d", &n);
  int x[n];
  nqueen(1, n, x);
  return 0;
}
