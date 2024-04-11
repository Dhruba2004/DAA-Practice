//A1 = 30*35
//A2 = 35&15
// A3 = 15*5
// A4 = 5*10
// A5 = 10*20
// A6 = 20*25

#include<stdio.h>
#include<limits.h>

int matrixChainOrder ( int p[],int n){
	int m[n][n];
	int s[n][n];
	int i, j, k, L, q;
	
	for (i=1;i<n;i++)
	m[i][i]=0;
	
	for (L=2;L<n;L++){
		for ( i=1;i<n-L+1;i++){
			j=i+L-1;
			m[i][j]= INT_MAX;
			for (k=i;k<=j-1;k++){
				q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				m[i][j]=q;
				s[i][j]=k;
				
			}
		}
	}
	return m[1][n-1];
}

// void print_optimal_parens(int s[][], int i, int j) {
// 	if(i==j)
// 	printf("A%d",i);
// 	else{
// 		printf("(");
// 		print_optimal_parens(s,i,s[i][j]);
// 		print_optimal_parens(s,s[i][j]+1,j);
// 		printf(")");
// 	}}

int main(){
	int arr[]= {30,35,15,5,10,20,25};
	int n = sizeof(arr)/sizeof(arr[0]);
	int s[n][n];
	printf("Minimum number of multiplications is %d ",
           matrixChainOrder(arr, n));
           getchar();
		//    print_optimal_parens(s,1,n-1);
	return 0;
	
}
 
 