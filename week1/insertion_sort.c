#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n){
	int i, j, key;
	for (i = 1;i < n;i++) {
		key = arr[i];
		j = i-1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int i, n;
	
	printf("Enter the size of the array: \n");
	scanf("%d", &n);
	printf("\n");
	
	int *arr = (int *)malloc(n * sizeof(int));
	
	printf("Enter the elements: ");
	for(i = 0;i < n;i++) {
		scanf("%d", &arr[i]);
	}
	
	printf("Original Array: \n");
	for (i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	sort(arr, n);
	
	printf("Sorted Array: \n");
	for (i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
}
