#include <stdio.h>
#include <stdlib.h>

struct link {
	int data;
	struct link * next;
};

struct link * push(struct link *top, int val) {
	struct link* newnode = (struct link *)malloc(sizeof(struct link));
	if(newnode == NULL) {
		printf("Stack Overflow");
		return top;
	}
	newnode->data = val;
	newnode->next = top;
	top = newnode;
	return top;
}

struct link* pop(struct link * top) {
	if(top == NULL){
		printf("Stack Underflow");
		return NULL;
	}
	struct link* temp = top;
	printf("Popped element: %d",temp->data);
	top = top->next;
	return top;
}

void display(struct link * top) {
	if (top == NULL) {
		printf("Stack is Empty");
	}
	struct link* temp = top;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	struct link * top = NULL;
	int choice, running=1, val;
	
	while(running) {
		printf("Enter 1 for insertion, 2 for deletion, 3 for display and 0 to exit: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Enter the element to insert: ");
				scanf("%d", &val);
				top = push(top, val);
				break;
			case 2:
				top = pop(top);
				break;
			case 3:
				display(top);
				break;
			case 0:
				running = 0;
				break;
			default:
				printf("Invalid input");
				break;
		}
	}
}

