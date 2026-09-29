#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int front;
	int rear;
	int count;
	int size;
	int *arr;
} Queue;

Queue * init(int n) {
	Queue * queue = (Queue *) malloc (n * sizeof(Queue));
	queue->size = n;
	queue->front = 0;
	queue->rear = -1;
	queue->count = 0;
	queue->arr = (int *) malloc (sizeof(int));
	return queue;
}

void enqueue(Queue * queue, int val) {
	if(queue->count == queue->size) {
		printf("Queue is Full.");
	}
	queue->rear = (queue->front + queue->count) % queue->size;
	queue->arr[queue->rear] = val;
	queue->count++;
}

int deque(Queue* queue) {
	if(queue->count == 0) {
		printf("Queue is Empty.");
		return -1;
	}
	
	int res = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->size;
	queue->count--;
	return res;
}

void display(Queue * queue) {
	int i;
	if(queue -> count == 0){
		printf("Empty Queue");
	}
	for (i = 0;i < queue->count;i++) {
		int index = (queue->front + 1) % queue->size;
		printf("%d ", queue->arr[index]);
	}
	printf("\n");
}

int main() {
	int n, running = 1, choice, res, val;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	Queue * queue = init(n);
	while(running) {
		printf("Enter 1 for enqueue 2 for deque 3 for display and 0 for exit: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter an element: ");
				scanf("%d", &val);
				enqueue(queue, val);
				break;
			case 2:
				res = deque(queue);
				printf("The element removed: %d", res);
				break;
			case 3:
				display(queue);
				break;
			case 0:
				running = 0;
				break;
			default:
				printf("Invalid Input");
		}
	}
}
