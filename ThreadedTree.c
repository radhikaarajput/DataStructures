#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node n;
/*typedef struct headNode h;

struct headNode
{
	int left;				//1 Null Links otherwise 0
	struct node *leftptr;
	int val;
	struct node *rightptr;
	int right;             //1 Null Links otherwise 0
}; */

struct node
{
	int left;				//1 Null Links otherwise 0
	struct node *lptr;
	int val;
	struct node *rptr;
	int right;             //1 Null Links otherwise 0
};

void inorder()
{
	n *nd;
	if(head->lptr==head)
	{
		printf("Empty");
		return;
	}
	nd = head->lptr;
	
	//move to leftmost with no thread
	while(nd->left==0)
		nd=nd->lptr;
		
	printf("%d",nd->val);   //print leftmost
	
	while(1)
	{
		nd = incSuc(nd);       //printf sucessor of each node while moving up
		
		if(nd==head)
			break;
			
		printf("%d",ptr->val);	
	}
}

struct node *incSuc(n *nd)
{
	nd *suc;
	if(nd->right==1)
		suc=nd->rptr;
	else
	{
		nd=nd->rptr;
		while(nd->left==0)
			nd=nd->lptr;
			
	suc=nd;		
	}	
	
}

void main()
{
	
	getch();
}
