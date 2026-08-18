#include <stdio.h>
#include <stdlib.h>

void deleteAtFirst(int arr[], int n) {
    int i;
    for (i = 0;i < n-1;i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = 0;
}

void deleteAtLast(int arr[], int n) {
    arr[n - 1] = 0;
}

void deletePosition(int arr[], int n, int pos) {
	int i;
    for (i = pos;i < n-1;i++) {
    	arr[i] = arr[i+1];
	}
	arr[n-1] = 0;
}

int main() {
	int i, pos, n;
	
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
	
	printf("Enter the position to delete: \n");
	scanf("%d", &pos);
	
	deleteAtFirst(arr, n);
	deleteAtLast(arr, n-1);
	deletePosition(arr, n, pos);
	
	
	for (i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	
}

