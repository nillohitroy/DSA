



#include <stdio.h>
#include <stdlib.h>

struct link{
    int data;
    struct link *next;
};

struct link* createnode(){
    struct link *temp;
    temp = (struct link*)malloc(sizeof(struct link));
    return temp;
}

void putdata(struct link *node){
    printf("Enter Data: ");
    scanf("%d", &node->data);
    node->next = NULL;
}

int get_ans(){
    char ch;
    printf("Continue? (y/n): ");
    scanf(" %c", &ch);

    return (ch=='y' || ch=='Y');
}

void showdata(struct link *head){
    struct link *temp;
    if(head == NULL)
        return;
    temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main(){
    struct link *head, *node;

    head = createnode();
    putdata(head);
    node = head;

    while(get_ans()){
        node->next = createnode();
        node = node->next;
        putdata(node);
    }


    node->next = head;

    printf("\nCircular Linked List: ");
    showdata(head);

    return 0;
}

