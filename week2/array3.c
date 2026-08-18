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

void display(int arr[], int n) {
	int i;
	for (i = 0;i < n;i++) {
		printf("%d ", arr[i]);
	}
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
	
	int running = 1;
	printf("\n");
	int ch;
	while(running) {
		printf("\nEnter your choice:\n1. Insert at Beg\n2. Insert at Last\n3. Insert At Position\n4. Delete at First\n5. Delete at Last\n6. Delete from Position\n0. Exit\n");
		scanf("%d", &ch);
		switch(ch) {
			case 1:
				printf("Enter the element to insert: \n");
				scanf("%d", &num);
				insertAtFirst(arr, n, num);
				display(arr, n);
				break;
			case 2:
				printf("Enter the element to insert: \n");
				scanf("%d", &num);
				insertAtLast(arr, n, num);
				display(arr, n);
				break;
			case 3:
				printf("Enter the element to insert: \n");
				scanf("%d", &num);
				printf("Enter the position to insert: \n");
				scanf("%d", &pos);
				insertPosition(arr, n, num, pos);
				display(arr, n);
				break;
			case 4:
				deleteAtFirst(arr, n);
				display(arr, n);
				break;
			case 5:
				deleteAtLast(arr, n);
				display(arr, n);
				break;
			case 6:
				printf("Enter the position to delete: \n");
				scanf("%d", &pos);
				deletePosition(arr, n, pos);
				display(arr, n);
				break;
			case 0:
				running = 0;
				break;
				
			default:
				printf("Enter a valid input!");
				break;
		}
	}
	
}

