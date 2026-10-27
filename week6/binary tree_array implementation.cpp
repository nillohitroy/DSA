#include<stdio.h>
void inorder(int );
void preorder(int );
void postorder(int );
int get_left_child(int );
int get_right_child(int );

int complete_node=15;
//char tree[]={'D','A','F','E','B','R','T','G','Q','\0','\0','V','\0','J','L'};
int tree[]={10,'\0', 20,'\0','\0','\0',30};
int main()
{
	printf("\n Inorder Traversal: ");
	inorder(0);
	printf("\n Preorder Traversal: ");
	preorder(0);
	printf("\n Postorder Traversal: ");
	postorder(0);
	
	return 0;
}
void inorder(int i)
{
	if(i>=0 && tree[i]!='\0')
	{
		inorder(get_left_child(i));
		printf("%d ",tree[i]);
		inorder(get_right_child(i));
	}
}
void preorder(int i)
{
	if(i>=0 && tree[i]!='\0')
	{
		printf("%d ",tree[i]);
		preorder(get_left_child(i));		
		preorder(get_right_child(i));
	}
}
void postorder(int i)
{
	if(i>=0 && tree[i]!='\0')
	{
		postorder(get_left_child(i));		
		postorder(get_right_child(i));
		printf("%d ",tree[i]);
	}
}
int get_left_child(int i)
{
	if(tree[i]!='\0' && ((2*i+1)<=complete_node))
		return (2*i+1);
	return -1;
}
int get_right_child(int i)
{
	if(tree[i]!='\0' && ((2*i+2)<=complete_node))
		return (2*i+2);
	return -1;
}
