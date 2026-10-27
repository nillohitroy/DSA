#include <stdio.h>
#include <stdlib.h>


struct link {
    int data;
    struct link *next;
};

struct link* create_node() {
    struct link *new_node = (struct link*)malloc(sizeof(struct link));
   
   
    return new_node;
}
 

void put_data(struct link *node) {
    printf("Enter data: ");
    scanf("%d", &node->data);
    node->next = node;
}

int get_ans() {
    int choice;
    printf("Do you want to add another node? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    return choice;
}

void show_data(struct link *head) {
    struct link *current = head;
    printf("\nLinked List Contents: ");
    while (current != head) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("head\n");
}

int main() {
    struct link *head, *node;
   
    head = create_node();
    put_data(head);
   
    node = head;
   
    while (get_ans()) {
        node->next = create_node();
        node = node->next;
        put_data(node);
    }
   
    show_data(head);
   

    return 0;
}


