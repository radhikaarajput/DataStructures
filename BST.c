#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


typedef struct node nd;

void inorder(struct node *root) ;
void preorder(struct node *root) ;
void postorder(struct node *root) ;
void deleteNode(nd *root, int key);
nd* minimumKey(nd *curr);
void search(nd *root, int key);
nd* getSuccessor(nd *root, int data);
nd* find(nd *root,int val);
void Maximum();
void Minimum();

int found=0;

void insert();
void delete();
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;


void main()
{
	int k;
	printf("Menu\n");
	printf("1.Insert\n2.Delete \n3.Inorder Traversal\n4.postorder Traversal\n5.preorder Traversal\n6.Search Element\n7.Mininmum element\n8.Maximum Element \n9.Inorder Sucessor\n10.Exit");
	int c;
		while(1)	
		{
		printf("\nEnter your choice: ");
		scanf("%d",&c);
		
		switch(c)
		{
			
			case 1: insert();
					break;
						
			case 2: printf("Enter element for deletion: ");
					scanf("%d",&k);
					deleteNode(root,k);
				
			case 3: printf("Inorder Traversal of BST--->Tree now: ");
					inorder(root);
					break;
					
			case 4: printf("postorder Traversal of BST--->Tree now: ");
					postorder(root);
					break;
					
			case 5: printf("preorder Traversal of BST--->Tree now: ");
					preorder(root);
					break;				
					
			case 6: printf("Enter element for searching: ");
					scanf("%d",&k);
					search(root,k);
					break;
			case 7: Minimum();
					break;
			case 8:Maximum();
					break;
			case 9: printf("Enter element for finding inorder sucessor: ");
					scanf("%d",&k);
					getSuccessor(root,k);
					break;
			case 10:exit(0);
					break;						
				
		}
	}	
	getch();
}

void insert( )
{
	int a;
	
	nd *t;
	t=(nd*)malloc(sizeof(nd));
	if(t==NULL)
	{
		printf("overflow");
		return;
	}
	
	printf("Enter Value: ");
	scanf("%d",&t->data);
	t->right=NULL;
	t->left=NULL;
	
	nd *p=NULL;
	
	if(root==NULL)
	{
		root=t;
		return;
	}
	else
	{
		nd *cur=root;
		
		while(cur)
		{
			p=cur;
			if(t->data > cur->data)
				cur=cur->right;
			else
				cur=cur->left;	
		}
	}
	
	if(t->data > p->data)
		p->right=t;
	else
		p->left=t;			
}
void inorder(struct node *root) 
{ 
		
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); 
    } 
} 

void preorder(struct node *root) 
{ 
		
    if (root != NULL) 
    { 
		printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

void postorder(struct node *root) 
{ 
		
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right);
		printf("%d ", root->data);  
    } 
} 

nd* minimumKey(nd *curr)
{
	while(curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}

nd* find(nd *root,int val)
{
	if(root==NULL)
		return;
	else if(root->data== val)
		return root;
	else if(root->data < val)
		return find(root->right, val);
	else if(root->data > val)
		return find(root->left, val);
				
}

nd *getSuccessor(nd *root, int data)
{
	nd *cur=find(root,data);
	nd *suc=NULL;
	if(cur==NULL)
		return NULL;
	
	if(cur->right !=NULL)
	{
		nd *temp= cur->right;
		while(temp->left != NULL)
			temp= temp->left;
	
		printf("Successor is %d",temp->data);	
		return temp;	
	}
	else
	{
		//nd *suc=NULL;
		nd *ancestor=root;
		while(ancestor!=cur)
		{
			if(cur->data < ancestor->data)
			{
				suc=ancestor->data;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
	}
	
	printf("Successor is %d",suc->data);
	return suc;
}

void deleteNode(nd *root, int key)
{
	nd *parent = NULL;    //store parent of key
	nd *curr = root;   

	// find parent of key (Key element to delete)
	while (curr != NULL && curr->data != key)
	{
		// update parent node as current node
		parent = curr;

		if (key < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	// key is not found in the tree
	if (curr == NULL)
	{
		printf("Element Not FOUND");
		return;
	}

	// Case 1 delete leaf node
	//cur=element to delete now
	if (curr->left == NULL && curr->right == NULL)
	{
		
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		// if tree has only root node, delete it and set root to null
		else
			root = NULL;

		// deallocate the memory
		free(curr);	 // or delete curr;
	}

	// Case 2 node to be deleted has two children (both left and right exist)
	else if (curr->left && curr->right)
	{
		// find its in-order successor node
		nd* minRightSubTREE  = minimumKey(curr->right);

		// store successor value
		int val = minRightSubTREE->data;
		

		//deleting 45 present at leaf level
		//successor  ----> at-most one child (right child) 
		deleteNode(root, minRightSubTREE->data);
		
		// Copy the value of min from right sub-tree to current node i.e. node to be delete
		curr->data = val;
	}

	// Case 3 cur had one child
	else
	{
		// find child node of the current(left/right)
			
			nd *child;
			if(curr->left != NULL)
			{
				child=curr->left;
			}
			else if(curr->right != NULL)
			{
				child=curr->right;
			}	

		if(curr == root)                            //deleting root---cur==root node(need to set the root now)
			root = child;

		// if node to be deleted is not a root node, then set its parent
		// to its child
		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		
	
		// deallocate the memory
		free(curr);
	}
	
}


void search(nd *root, int key)
{
	while(root!=NULL)
	{
		
		if(key > root->data)
			root=root->right;
		else if(key < root->data)
			root=root->left;
	
		if(root->data == key)
		{
				found=1;
				break;
		}
	}
	
	if(found==1)
		printf("Element found");
	else
		printf("Element not found");	
}


void Minimum()
{
	nd *cur=root;
	while(cur->left!=NULL)
		cur=cur->left;
	
	printf("Minimum Element is: %d ",cur->data);	
}


void Maximum()
{
	nd *cur=root;
	while(cur->right!=NULL)
		cur=cur->right;
	
	printf("Maximum Element is: %d",cur->data);	
}
