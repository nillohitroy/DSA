#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *createNode(int value) {
	struct Node *newNode = (struct Node *) malloc (sizeof(struct Node));
	if (newNode == NULL)
		printf("Memory Allocation failed");
	newNode -> data = value;
	newNode -> next = NULL;
	return newNode;	
}

void display(struct Node *head) {
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int value) {
	struct Node *newNode = createNode(value);
	newNode -> next = head;
	return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value) {
	struct Node *newNode = createNode(value);
	struct Node *temp = head;
	while (temp -> next != NULL) {
		temp = temp->next;
	}
	temp -> next = newNode;
}

struct Node *insertAtPosition(struct Node *head, int value, int pos) {
	int i;
	if(pos == 0)
		return insertAtBeginning(head, value);
	
	struct Node *newNode = createNode(value);
	struct Node *temp = head;
	
	for (i = 0;i < pos - 1 && temp != NULL;i++)
		temp = temp->next;
	if(temp == NULL) {
		printf("Position out of bound");
		return head;
	}
	newNode -> next = temp->next;
	temp->next = newNode;
	return head;
}

struct Node *deleteAtFirst(struct Node *head){
	if (head == NULL) {
		printf("Empty List.\n");
		return NULL;
	}
	struct Node *temp = head;
	head = head -> next;
	return head;
}

struct Node *deleteAtLast(struct Node *head) {
	if (head == NULL) {
		printf("Empty list.\n");
		return NULL;
	}
	
	if (head -> next == NULL) {
		return NULL;
	}
	
	struct Node *temp = head;
	while (temp -> next -> next != NULL) {
		temp = temp -> next;
	}
	temp -> next = NULL;
	return head;
}

struct Node *deletePosition(struct Node *head, int pos) {
	int i;
	if (head == NULL) {
		printf("Empty List. \n");
		return NULL;
	}
	
	if (pos == 0) {
		return deleteAtFirst(head);
	}
	
	struct Node *temp = head;
	for (i = 0;i < pos - 1 && temp != NULL;i++) {
		temp = temp->next;
	}
	if(temp == NULL || temp->next == NULL) {
		printf("Out of Bound");
		return head;
	}
	
	struct Node *target = temp -> next;
	temp -> next = target -> next;
	return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position, target, index;
	int running = 1;
    while (running) {
        printf("\n================ LINKED LIST MENU ================\n");
        printf("1. Insert at Beginning\t\t5. Delete First Node\n");
        printf("2. Insert at End\t\t6. Delete Last Node\n");
        printf("3. Insert at Position\t\t7. Delete at Position\n");
        printf("4. Display List\t\t0. Exit\n");
        printf("==================================================\n");
        printf("Enter your choice (0-7): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                printf("Inserted %d at the beginning.\n", value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                if (head == NULL) {
                    head = insertAtBeginning(head, value);
                } else {
                    insertAtEnd(head, value);
                }
                printf("Inserted %d at the end.\n", value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0-indexed): ");
                scanf("%d", &position);
                head = insertAtPosition(head, value, position);
                break;

            case 4:
                printf("Current Linked List: \n");
                display(head);
                break;

            case 5:
                head = deleteAtFirst(head);
                break;

            case 6:
                head = deleteAtLast(head);
                break;

            case 7:
                printf("Enter position to delete (0-indexed): ");
                scanf("%d", &position);
                head = deletePosition(head, position);
                break;
                
            case 0:
            	running = 0;
            	break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 10.\n");
        }
    }

    return 0;
}
