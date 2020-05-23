//create and traverse sparse matrix (linked list implemetation)
#include<iostream>
using namespace std;
struct col
{
	int c;
	int val;
	struct col* ptr;
};
struct row
{
	int r;
	struct col* ptr1;
	struct row* ptr2;
};
struct row* create(int r,int c,struct row* st)
{
	int n=0,v,f=1;
	struct row* ptr_r=NULL;
	struct row* prev_r=NULL;
	struct col* prev_c=NULL;
	struct col* ptr_c=NULL;
	char ch='y';
	cout<<"----------CREATE THE SPARSE MATRIX----------\n";
	while(ch=='y'||ch=='Y')
	{
		cout<<"ELEMENT NUMBER: "<<n+1<<"\n";
		cout<<"\tenter row number:  ";
		cin>>v;
		if(v<=r)
		{
			prev_r=ptr_r;
			if(ptr_r==NULL)
			{
				ptr_r=new struct row;
				st=ptr_r;
			}
			else
			{
				ptr_r=new struct row;
				prev_r->ptr2=ptr_r;
				
			}
				
			ptr_r->r=v;
			ptr_r->ptr2=NULL;
			
		}
		else
		{
			cout<<"cannot create with the entered row value. Enter again\n";
			continue;
		}
		while(ch=='y'||ch=='Y')
		{
			if(f==0)
			{
				cout<<"ELEMENT NUMBER: "<<n+1<<"\n";
			}
			cout<<"\tenter column number:  ";
			cin>>v;
			if(v<=c)
			{
				prev_c=ptr_c;
				if(ptr_c==NULL)
				{
					ptr_c=new struct col;
					ptr_r->ptr1=ptr_c;
				}
				else
				{
					ptr_c=new struct col;
					prev_c->ptr=ptr_c;
				}
					
				ptr_c->c=v;
				ptr_c->ptr=NULL;
				
			}
			else
			{
				cout<<"cannot create with the entered column value. Enter again\n";
				continue;
			}
			cout<<"\tenter the value of the element:  ";
			cin>>v;
			ptr_c->val=v;
			n++;
			cout<<"\tadd another column of the same row?:";
			cin>>ch;
			if(ch=='y'||ch=='Y')
				f=0;
		}
		f=1;
		prev_c=NULL;
		ptr_c=NULL;
		cout<<"\tadd another row?(y/n/Y/N):";
		cin>>ch;
	}
	return st;
}
void traverse(int r,int c,struct row* st)
{
	int i,j;
	struct row* trav_r;
	struct col* trav_c; 
	cout<<"----------PRINTING SPARSE MATRIX----------\n";
	for(trav_r=st,i=0;i<r;i++)
	{
		for(trav_c=trav_r->ptr1,j=0;j<c;j++)
		{
			if(i+1==trav_r->r&&j+1==trav_c->c)
			{
				cout<<trav_c->val<<"  ";
				if(trav_c->ptr!=NULL)
					trav_c=trav_c->ptr;
				
			}
			else
				cout<<"0  ";
		}
		if(trav_r->ptr2!=NULL)
			trav_r=trav_r->ptr2;
		cout<<"\n";
	}
}
int main()
{
	struct row* st;
	int r,c,n;
	cout<<"Enter the maximum number of rows and columns: ";
	cin>>r>>c;
	st=create(r,c,st);
	traverse(r,c,st);
}
