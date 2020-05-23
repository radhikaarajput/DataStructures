#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
}*root=NULL;

typedef struct node nd;


void insert(nd *root, nd *newn);
nd* getnode();
void Preorder(nd* node);
void Postorder(nd *node);
void Inorder(nd *node);
void ItreativePostorder(nd *node);
void ItreativeInorder(nd *node);
void ItreativePreorder(nd *p);

#define max 100
nd *stack[max];
int top=-1;

void main()
{
	root=NULL;
	nd *newn=NULL;
	printf("\nMenu");
	printf("\n1.Insert\n2.Preorder \n3.Postorder \n4.Inorder\n5.Itreative Preorder \n6.Itreative Postorder \n7.Itreative Inorder\n8.Exit");
	int c;
		while(1)	
		{
		printf("\nEnter your choice(1-4):");
		scanf("%d",&c);
		
		switch(c)
		{
			
			case 1: newn=getnode(); 
					if(root==NULL)
						root=newn;
					else
						insert(root,newn);
						
					break;
					
			case 2: printf("Tree now: ");
					Preorder(root);
					break;
				
			case 3: printf("Tree now: ");
					Postorder(root);
					break;
					
			case 4: printf("Tree now: ");
					Inorder(root);
					break;
					
			case 5: printf("Tree now: ");
					ItreativePreorder(root);
					break;				
					
			case 6: printf("Tree now: ");
					ItreativePostorder(root);
					break;
					
			case 7: printf("Tree now: ");
					ItreativeInorder(root);
					break;						
						
		}
	}
	getch();
		
}

void insert(nd *root, nd *newn)
{
	char ch='n';
	printf("Left or Right: ");
	ch=getch();
	if(ch=='L' || ch=='l')
	{
		//printf("in looooop");
		if(root->right == NULL)
			root->right=newn;
		else
			insert(root->right,newn);	
	}
	if(ch=='R' || ch=='r')
	{
		if(root->left == NULL)
			root->left=newn;
		else
			insert(root->left,newn);	
	}
}


nd* getnode()
{
	nd *newn;
	newn=(nd*)malloc(sizeof(nd));
	if(newn==NULL)
	{
		printf("overflow");
		return;
	}
	newn->left=NULL;
	newn->right=NULL;
	printf("Enter value: ");
	scanf("%d",&newn->val);
	
	return newn;
}




void Preorder(nd *node) 
{ 
    if (node == NULL) 
        return; 
  
    printf("%d - ",node->val);
    Preorder(node->left);
    Preorder(node->right); 
}  

void Postorder(nd *node) 
{ 
    if (node == NULL) 
        return; 
  
    Preorder(node->left);
    Preorder(node->right); 
    printf("%d - ",node->val);
    
}  

void Inorder(nd *node) 
{ 
    if (node == NULL) 
        return; 
  
    Preorder(node->left);
    printf("%d - ",node->val);
    Preorder(node->right); 
    
}  

void ItreativePostorder(nd *p)
{
	while(1)
	{
		if(p)
		{
			stack[++top]=p;
			p=p->left;
		}
		else
		{
			if(top== -1)
				break;
			else
			{
				if(stack[top]->right==NULL)
				{
					p=stack[top];
					top--;
					printf("%d ",p->val);
					
					if(p==stack[top]->right)
					{
						printf("%d ",stack[top]->val);	
						top--;
					}
				}
				
				
			   if(top!= -1)
			   {
					p=stack[top]->right;
			   }	
			   else
			   	p=NULL;	
			}	
		}
	}
}



void ItreativeInorder(nd *p)
{
	while(p!=NULL && top!=-1)
	{
		if(p!=NULL)
		{
			stack[++top]=p;
			p=p->left;
		}
		else
		{
			p=stack[top--];
			printf("%d - ",p->val);
			p=p->right;
		}
	}
}


void ItreativePreorder(nd *p)
{
	stack[++top]=p;
	while(top!=-1)
	{
		p=stack[top--];
		if(p!=NULL)
		{
			printf("%d ",p->val);
			stack[++top]=p->right;
			stack[++top]=p->left;
		}
	}
}
