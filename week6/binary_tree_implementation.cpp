// Binary Tree creation and Traversal

#include<stdio.h>
#include<stdlib.h>

struct node *create();
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);

struct node{
		int value;
		struct node *left;
		struct node *right;
	};
int main()
{	
	struct node *root;
	root=create();
	
	printf("\n Inorder Traversal: ");
	inorderTraversal(root);
	
	printf("\n Preorder Traversal: ");
	preorderTraversal(root);
	
	printf("\n Postorder Traversal: ");
	postorderTraversal(root);
}
struct node *create()
{
	int x;
	struct node *newnode;
	
	printf("\n enter a value (-1 for no node): ");
	scanf("%d",&x);
	
	if(x==-1)
		return NULL;
		
	newnode=(struct node*)malloc(sizeof(newnode));
	newnode->value=x;
	printf("\n enter left child of %d: ",x);
	newnode->left=create();
		
	printf("\n enter right child of %d: ",x);
	newnode->right=create();
	
	return(newnode);
}
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->value);
  inorderTraversal(root->right);
}
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left); 
  postorderTraversal(root->right);
  printf("%d ->", root->value);
}
