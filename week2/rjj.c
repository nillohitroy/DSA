#include<stdio.h>
#include<stdlib.h>
struct link {
	int data;
	struct link*next 
};
struct link *createNode();
void putData(struct link*Node);
void get(struct link*head);
void printData(struct link*head);
int main() {
	struct link*head ,node;
	int n,i;
	printf("enter number of nodes:");
	scanf("%d",&n);
	head = createNode();
	putData(head);
	
	for(i=1;i<1;i++){
		node>next= createnode()
		node= node-> next;
		putData(node);
	}
}
    struct link*head ,node

