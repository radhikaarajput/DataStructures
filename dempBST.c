#include<stdio.h>
#include<string.h>
#include<conio.h>
#define max 50
int top = -1;
char stack[max];

void push(char c)
{
            top++;
            stack[top] = c;
}

void pop()
{
            stack[top] = '\0';
            top--;
}

int main()
{
            int j,k,l;
            char s[1000];
            printf("Type the expression.\n");
            scanf("%[^\n]s",s);
            l = strlen(s);
            for(j = 0 ;j<l;j++)
            {
                        if(s[j]=='(' || s[j] == '{' || s[j] == '[')
                        {
                                    push(s[j]);
                        }
                        if(s[j]==')')
                        {
                                    if(stack[top]=='(')
                                    {
                                                pop();
                                    }
                                    else
                                    {
                                                printf("Expression is not correctly paraenthesized\n");
                                                return;
                                    }
                        }
                        if(s[j]=='}')
                        {
                                    if(stack[top]=='{')
                                    {
                                                pop();
                                    }
                                    else
                                    {
                                                printf("Expression is not correctly paraenthesized\n");
                                                return;
                                    }
                        }
                        if(s[j]==']')
                        {
                                    if(stack[top]=='[')
                                    {
                                                pop();
                                    }
                                    else
                                    {
                                                printf("Expression is not correctly paraenthesized\n");
                                                return;
                                    }
                        }
            }
            printf("Expression is correctly paraenthesized\n");
            getch();
            return 0;
}
