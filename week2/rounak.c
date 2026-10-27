#include <stdio.h>
#include <stdlib.h>

struct link {
    int data;
    struct link *next;
};

struct link* createNode();
void Data(struct link *node);
void get(struct link *head);
void printData(struct link *head);

int main()
{
    struct link *head, *node;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createNode();
    addData(head);

    node = head;
    for(i = 1; i < n; i++)
    {
        node->next = createNode();
        node = node->next;
        addData(node);
    }
    printData(head);

    return 0;
}
struct link* createNode()
{
    struct link *newNode;

    newNode = (struct link*)malloc(sizeof(struct link));

    newNode->next = NULL;

    return newNode;
}

void addData(struct link *node)
{
    printf("Enter data: ");
    scanf("%d", &node->data);
}

void get(struct link *head)
{
    struct link *node = head;

    while(node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
   printf("NULL\n");
}
void printData(struct link *head)
{
    get(head);
}
