#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

 // Merge Function
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }


  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

}


void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}


void printArray(int A[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
}


int main() {
  /*Array Size Declaration*/
  int size1, size2, size3;
  double time_spent;

   clock_t begin = clock();
  printf("\nEnter the size for the first array: ");
  scanf("%d", & size1);

  printf("\nEnter the size for the second array: ");
  scanf("%d", & size2);


  size3 = size1 + size2;

  int array1[size1], array2[size2], array3[size3];


  for (int i = 0; i < size1; i++) {

    array1[i] = rand() % 1000;
    array3[i] = array1[i];
  }

  int k = size1;

  //printf("\nEnter the elements for 2nd array:");
  /*Array Initialized*/

  for (int i = 0; i < size2; i++) {
    array2[i] = rand() % 1000;

    array3[k] = array2[i];
    k++;
  }

  printf("Given array is \n");
  printArray(array3, size3);



  mergeSort(array3, 0, size3 - 1);
  //sleep(2);

  clock_t end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\nSorted array is \n");
  printArray(array3, size3);

  printf("\n\nElapsed time: %f secs\n\n",time_spent);



  return 0;
}
