#include <stdio.h>
#include <stdlib.h>

struct link {
	int data;
	struct link * next;
};

struct link* createnode();
void putdata(struct link* node);
void showdata(struct link* head);
int getans();

int main() {
	struct link *head, *node;
	head = createnode();
	putdata(head);
	node = head;
	
	while(getans()) {
		node->next = createnode();
		node = node->next;
		putdata(node);
	}
	node -> next = head;
	showdata(head);
}

struct link *createnode(){
	struct link *n;
	n = (struct link *) malloc (sizeof(struct link));
	return n;
}

void putdata(struct link *node) {
	int n;
	printf("Enter the value: ");
	scanf("%d", &n);
	node->data = n;
	node->next = NULL;
}

void showdata(struct link* head) {

	struct link *temp = head;
	do {
		printf("%d -> ", temp->data);
		temp = temp->next;
	} while (temp != head);
	printf("%d", temp->data);
}

int getans() {
	int n;
	printf("Enter 1 or any number to continue and 0 to stop: ");
	scanf("%d", &n);
	if(n != 0){
		return 1;
	}
	else{
		return 0;
	}
}
