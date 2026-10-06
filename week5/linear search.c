#include <stdio.h>
#include <stdlib.h>

int * unique (int *arr, int n, int *count) {
	int * ans;
	ans = (int *) malloc (n * sizeof(int));
	int i, j, k = 0;
	
	for (i = 0; i < n; i++) {
		int duplicate = 0;
		for (j = 0; j < k; j++) {
			if (arr[i] == ans[j]) {
				duplicate = 1;
				break;
			}
		}
		
		if (!duplicate) {
			ans[k] = arr[i];
			k++;
		}
	}
	
	*count = k;
	return ans;
}

int main() {
	int n, i, *arr, num, pos = -1;
	printf("Enter the number of elements: ");
	if (scanf("%d", &n) != 1) return 1;
	
	arr = (int *) malloc (n * sizeof(int));
	
	printf("Enter the elements: ");
	for (i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) return 1;
	}
	
	int count = 0;
	int * ans = unique(arr, n, &count);
	
	printf("Unique elements: ");
	for (i = 0; i < count; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	printf("Enter the element to be searched: ");
	if (scanf("%d", &num) != 1) return 1;
	
	for (i = 0; i < n; i++) {
		if (ans[i] == num) {
			pos = i + 1;
			break;
		}
	}
	
	if (pos != -1) {
		printf("Element found at position: %d\n", pos);
	} else {
		printf("Element not found.\n");
	}
	
	return 0;
}

