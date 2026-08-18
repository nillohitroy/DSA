#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n){
	int i, min_idx, temp, j;
	
	for(i = 0;i < n-1;i++) {
		min_idx = i;
		
		for(j = i+1;j < n;j++) {
			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		
		if(min_idx != i) {
			temp = arr[min_idx];
			arr[min_idx] = arr[i];
			arr[i] = temp;
		}
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
