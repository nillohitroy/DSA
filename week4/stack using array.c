#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int top;
	int *arr;
} Stack;

Stack* init(int n) {
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	stack->arr = (int *) malloc (stack->n * sizeof(int));
	stack->top = -1;
	
	return stack;
}

void push(Stack * stack, int ele) {
	if(stack->top == (stack->n)-1)
		printf("Stack Overflow\n");
	stack->top++;
	stack->arr[stack->top] = ele;
}

int pop(Stack* stack) {
	if (stack->top == -1){
		printf("Stack Underflow\n");
		return -1;
	}
	int ele = stack->arr[stack->top];
	stack->top--;
	return ele;
}

void display(Stack *stack) {
	int i;
	for (i = stack->top;i >= 0;i--) {
		printf("%d ", stack->arr[i]);
	}
	printf("\n");
}

int main() {
	int n, ch, running=1, ele, poped;
	printf("Enter the numnber of elements: ");
	scanf("%d", &n);
	Stack * stack = init(n);
	while(running) {
		printf("\nEnter 1 to insert, 2 to delete, 3 to display and 0 to exit: \n");
		
		if (scanf("%d", &ch) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
		switch(ch) {
			case 1:
				printf("\nEnter an element: \n");
				scanf("%d", &ele);
				push(stack, ele);
				break;
			case 2:
				poped = pop(stack);
				printf("\nThe number popped: %d", poped);
				break;
			case 3:
				display(stack);
				break;
			case 0:
				running = 0;
				break;
			default:
				printf("Wrong input.\n");
		}
	}
}
