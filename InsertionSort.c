#include <stdio.h>  
  
void insSort(int arr[], int n) /* function to sort an aay with insertion sort */  
{  
int i, j, temp;  
for (i = 1; i < n; i++) {  
temp = arr[i];  
j = i - 1;  

while(j>=0 && temp <= arr[j])  /* Move the elements greater than temp to one position ahead from their current position*/  
{    
    arr[j+1] = arr[j];     
    j = j-1;    
}    
arr[j+1] = temp;    
}  
}  
  
void printArr(int arr[], int n) /* function to print the array */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", arr[i]);  
}  
  
int main()  
{  
    int arr[] = { 12, 31, 25, 8, 32, 17 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    printf("Before sorting array elements are - \n");  
    printArr(arr, n);  
    insSort(arr, n);  
    printf("\nAfter sorting array elements are - \n");    
    printArr(arr, n);  
  
    return 0;  
}    
