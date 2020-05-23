#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void main()
{
    char s[40];
  	char rev[40];
  	int i;
    printf("Enter the string: ");
    gets(s);
    char c='(';
	strcpy(rev,c);
	//strcat(rev,')');
//	strcpy(s,rev);	
    printf("\nReverse of %s ",rev);
    getch();
}

