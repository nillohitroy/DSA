#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};

struct link* createnode() {
    return (struct link*)malloc(sizeof(struct link));
}

struct link* delcount(struct link *head, int count) {
    struct link *node, *prev, *temp;
    int i;

    node = head;
    prev = head;

    while(prev->next != head)
        prev = prev->next;

    for(i = 1; i < count; i++) {
        prev = node;
        node = node->next;
    }

    printf("Removed: %d\n", node->data);

    temp = node->next;
    prev->next = temp;

    if(node == head)
        head = temp;

    free(node);
    return head;
}

int main() {
    struct link *head, *node;
    int i, j, count;

    head = createnode();
    node = head;

    printf("Enter number of people : ");
    scanf("%d", &j);

    head->data = 1;
    head->next = NULL;

    i = 2;

    while(i <= j) {
        node->next = createnode();
        node = node->next;
        node->next = NULL;
        node->data = i;
        i++;
    }

    node->next = head;

    printf("Enter counting number: ");
    scanf("%d", &count);

    while(head != head->next)
        head = delcount(head, count);

    printf("Winner: %d\n", head->data);

    return 0;
}

