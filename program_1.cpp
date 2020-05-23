#include<iostream>
using namespace std;

int main(){
	int a[100],size,d=0,b[100];
	cout<<"Enter the size of the array::";
	cin>>size;
	cout<<"\nEnter the array Elements one by one::";
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	cout<<"\nArray elements::";
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\nEnter the element you want to delete::";
	cin>>d;
	int j;
	for(int i=0,j=0;i<size;i++){
		if(a[i]!=d){
			b[j++]=a[i];
		}
		else
		continue;
	}
	if(j==size){
		cout<<"\nSorry the element could not be deleted::";
	}
	else{
		cout<<"\n The new array is ::";
		for(int i=0;i<j;i++){
			cout<<b[i];
		}
	}
	int count=0;
	for(int i=0,j=1;j<size;j++){
		if(a[i]==a[j]){
			count++;
		}
		else
		continue;
		i++;
	}
	return 0;
}
