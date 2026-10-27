#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value, pos, choice;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    printf("\n1. Insert First");
    printf("\n2. Insert Last");
    printf("\n3. Insert Any Position");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    scanf("%d", &value);
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    if(choice == 1) {
        newNode->next = head;
        head = newNode;
    }
    else if(choice == 2) {
        newNode->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    else if(choice == 3) {
        printf("Enter position: ");
        scanf("%d", &pos);
        temp = head;
        for(i = 1; i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\nLinked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}
