#include <stdio.h>
#include <stdlib.h>

void insertAtFirst(int arr[], int n, int x) {
    int i;
    for (i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}

void insertAtLast(int arr[], int n, int x) {
    arr[n - 1] = x;
}

void insertPosition(int arr[], int n, int x, int pos) {
    int i;

    for (i = n - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = x;
}

int main() {
	int i, pos, n, num;
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
	
	printf("Enter the position to insert: \n");
	scanf("%d", &pos);
	
	printf("Enter the number to insert: \n");
	scanf("%d", &num);
	
	insertAtFirst(arr, n, num);
	insertAtLast(arr, n-1, num);
	insertPosition(arr, n, num, pos);
	
	
	for (i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
	
}

