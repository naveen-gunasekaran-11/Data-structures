/** Inorder traversal of a binary tree **/
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#define MAX_Q_SIZE 500 

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
};

struct stack
{
    struct node *tree;
    struct stack *next;
};

void push (struct stack **head, struct node *tree)
{
    struct stack *new_node = (struct stack*) malloc (sizeof (struct stack));

    new_node->tree = tree;
    new_node->next = *head;
    *head = new_node;
}

struct node* pop (struct stack **head)
{
    struct stack *temp = *head;

    *head = temp->next;
    struct node *ret = temp->tree;

    free(temp);

    return ret;
}

bool isempty (struct stack *head)
{
    return ((head==NULL)? 1:0);
}

void printinOrder (struct node *root)
{
    struct node *current = root;
    struct stack *head = NULL;
    bool done = 0;

    while (!done)
    {
        if (current != NULL)
        {
            push (&head, current);
            current = current->left;
        }
        else
        {
            if (!isempty(head))
            {
                struct node *temp = pop(&head);
                printf ("%d ", temp->data);
                current = temp->right;
            }
            else
            {
                done = 1;
            }
        }
    }
}

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
    struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5);
    root->right->left  = newNode(6); 
    root->right->right = newNode(7);
  
    printf("In Order traversal of binary tree is \n"); 
    printinOrder(root); 
  
    return 0; 
} 