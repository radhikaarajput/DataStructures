#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h>

struct node
{
    int a;
    struct node *next;
};
 
void generate(struct node **);
void display(struct node *);
void stack_reverse(struct node **, struct node **);
void delete(struct node **);
 
int main()
{
    struct node *head = NULL;
 
    generate(&head);
    printf("\Initially Stack: ");
    display(head);
    printf("\nStack after calling reverse: ");
    if (head != NULL)
    {
        stack_reverse(&head, &(head->next));
    }
    printf("\nThe contents in stack after reversal: ");
    display(head);
    delete(&head);
 	getch();
    return 0;
}
 
void stack_reverse(struct node **head, struct node **head_next)
{
    struct node *temp;
 
    if (*head_next != NULL)
    {
         temp = (*head_next)->next;
        (*head_next)->next = (*head);
        *head = *head_next;
        *head_next = temp;
        stack_reverse(head, head_next);
    }
}
 
void display(struct node *head)
{
    if (head != NULL)
    {
        printf("%d  ", head->a);
        display(head->next);
    }
}
 
void generate(struct node **head)
{
    int num, i;
    struct node *temp;
 
    printf("Enter length: ");
    scanf("%d", &num);
    for (i = num; i > 0; i--)
    {
        temp = (struct node *)malloc(sizeof(struct node));
       // temp->a = i;
       printf("Enter element: ");
    	scanf("%d", &temp->a);
        if (*head == NULL)
        {
            *head = temp;
            (*head)->next = NULL;
        }
        else
        {
            temp->next = *head;
            *head = temp;
        }
    }
}
 
void delete(struct node **head)
{
    struct node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
