#include<stdio.h>
#include<stdlib.h>


/*Several approaches of root node
Local variable approach with return type as struct node pointer
void return type using pointer to pointer
Otherwise as global variable
*/
//Structure of the BST node
struct node{
	int data;
	struct node *left;
	struct node *right;
};

//Declaring root node as null
struct node *root = NULL;

//Function for the search
void search(struct node *head,int data)
{
	if(head==NULL)
	{
		printf("Tree is empty");
	}
	else
	{
		if(data>head->data)
		{
			search(head->right,data);
		}
		else if(data<head->data)
		{
			search(head->left,data);
		}
		else if(head->data==data)
		{
			printf("Found Data");
			return;
		}
	}
}

//Function for inserting node
void insert(int x)
{
	struct node *temp =(struct node *)malloc(sizeof(struct node));
	
	if(temp==NULL)
	{
		printf("Cannot allocate memory\n");
		return;
	}
	if (root==NULL)
	{
		temp->data=x;
		temp->right=NULL;
		temp->left=NULL;
		root=temp;
		return;
	}
	else
	{	
		temp->data=x;
		struct node *parent=NULL;
		struct node *current=root;
		while(current!=NULL)
		{
			parent=current;
			if(current->data<=x)
			{
				current=current->right;
			}
			else
			{
				current=current->left;
			}
		}
		if(parent->data<=x)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
		temp->left=NULL;
		temp->right=NULL;
	}
	
}

//Finding maximum and minimum using iteration
int find_max()
{
	struct node *temp=root;
	if (temp==NULL)
	{
		printf("Tree is empty\n");
		return -1;
	}
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp->data;
}

int find_min()
{
	struct node *temp=root;
	if(temp==NULL)
	{
		printf("Tree is empty\n");
		return -1;
	}
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}

//Finding the maximum and minimum using reccurtion
int find_min_rec(struct node *root_temp)
{
	if(root_temp==NULL)
	{
		printf("Tree is empty\n");
		return -1;
	}
	else if(root_temp->left==NULL)
	{
		return root_temp->data;
	}
	return find_min_rec(root_temp->left);
}



struct node* findmin(struct node *root_temp)
{
	if(root_temp==NULL)
	{
		printf("Tree is empty\n");
		return NULL;
	}
	else if(root_temp->left==NULL)
	{
		return root_temp;
	}
	return findmin(root_temp->left);
}

void preorder(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	printf("%d\t",head->data);
	preorder(head->left);
	preorder(head->right);
}

void inorder(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	inorder(head->left);
	printf("%d\t",head->data);
	inorder(head->right);
}

void postorder(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	postorder(head->left);
	postorder(head->right);
	printf("%d\t",head->data);
}

//Function for deleting the node
struct node *Delete(struct node *root,int data)
{
	if(root == NULL)
	{
		printf("The tree is empty\n");
		return;
	}
	else if (data<root->data)
	{
		root->left=Delete(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=Delete(root->right,data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
			return root;
		}
		else if(root->left==NULL)
		{
			struct node *temp=root;
			root=root->right;
			free(temp);
			return root;
			
		}
		else if(root->right==NULL)
		{
			struct node *temp=root;
			root=root->left;
			free(temp);
			return root;	
		}
		else
		{
			struct node *temp= findmin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
}
int main()
{
	int x,n,i,del,fin;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
	printf("The largest value of the BST is %d",find_max());
	printf("\nThe smallest value of the BST is %d",find_min());
	printf("\nThe smallest value of the BST using reccursion is %d",find_min_rec(root));
	
	
	printf("Printing the elemnent of the tree in preorder\n");
	preorder(root);
	printf("\nPrinting the elemnent of the tree in inorder\n");
	inorder(root);
	printf("\nPrinting the elemnent of the tree in postorder\n");
	postorder(root);
	
	printf("\nNow deleting the data of a node\n");
	scanf("%d",&del);
	Delete(root,del);
	
	
	printf("Printing the elemnent of the tree in preorder\n");
	preorder(root);
	
	printf("\nEneter the data to be searched");
	scanf("%d",&fin);
	search(root,fin);
}
