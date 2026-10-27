// Double Linked List creation, insertion and deletion

#include<stdio.h>
#include<stdlib.h>
void inorderTraversal(struct node* root);
struct node{
		int value;
		struct node *parent;
		struct node *left;
		struct node *right;
	}	;
int main()
{
	int y=1;
	
	struct node *start=NULL, *temp, *newnode;
	
	while(y)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		
		printf("enter the value of new node: ");
		scanf("%d",&newnode->value);	
	//	newnode->next=NULL;
		newnode->left=NULL;
		newnode->right=NULL;
		
		if(start==NULL)
		{
			start=temp=newnode;
			newnode->parent=NULL;
		}
		else if(temp->left==NULL)
		{
			temp->left=newnode;
			newnode->parent=temp;
		//	temp=newnode;
		}
		else if(temp->right==NULL)
		{
			temp->right=newnode;
			newnode->parent=temp;
		//	temp=newnode;
		}
		else
		{
			temp=temp->left;
			temp->left=newnode;
			newnode->parent=temp;
		//	temp=newnode;
		}
		printf("\n do you wish to continue? 1 if yes else 0:");
		scanf("%d",&y);	
	}
	
	printf("\n The binary tree traversal in Inorder: \n");
	
	temp=start;
	while(temp!=NULL)
	{		
	printf("%d ->", temp->value);
	if(temp->left!=NULL)
  		temp=temp->left;
  	printf("%d ->", temp->value);
  	if(temp->right!=NULL)
	  temp=temp->right;
	else
	temp=temp->parent;
	
	if(temp==start)
		break;
	
}


}
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->value);
  inorderTraversal(root->right);
}
