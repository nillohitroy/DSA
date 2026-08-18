#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sort(int arr[], int n){
	int i,temp, j;
	bool swapped;
	
	for(i = 0;i < n-1;i++) {
		swapped = false;
		for(j = 0;j < n - i - 1;j++) {
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = true;
			}
		}
		if(!swapped)
			break;
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
