/** Level order traversal of a binary tree **/
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

struct q_node
{
    struct node *tree;
    struct q_node *next;
};

struct queue 
{
    struct q_node *front;
    struct q_node *rear;
    int size;
};

int size = 0;

struct queue* create_queue ()
{
    struct queue *new_q = (struct queue*)malloc (sizeof (struct queue));
    new_q->front = NULL;
    new_q->rear = NULL;
    new_q->size = 0;

    return new_q;
}

struct q_node* create_node (struct node *tree)
{
    struct q_node *new_node = (struct q_node*) malloc (sizeof (struct q_node));

    new_node->tree = tree;
    new_node->next = NULL;

    return new_node;
}

void enqueue (struct queue *q, struct node *tree)
{
    struct q_node *new_node = create_node (tree);

    if ((q->front == NULL) && (q->rear == NULL))
    {
        //printf ("\nEHhloo\n");
        q->front = new_node;
        q->rear = new_node;
        (q->size)++;
        //printf ("Helo %d ", q->front->tree->data);
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
    (q->size)++;
}

struct node * dequeue (struct queue *q)
{
    if ((q->front == NULL) && (q->size == 0))
    {
        return NULL;
    }

    struct q_node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        //printf ("DEq");
        q->rear = NULL;
        //printf ("\n Nave: %d\n,",q->rear);
        //printf ("\n Nave: %d\n, ",q->front);
    }

    struct node *result = temp->tree;
    free(temp);
    (q->size)--;

    return result;
}

int get_size (struct queue *q)
{
    return (q->size);
}

bool isempty (struct queue *q)
{
    if ((q->front == NULL) && (q->rear == NULL))
    {
        return 1;
    }
    return 0;
}

void printlevelorder (struct node *root)
{
    int rear;
    int front;
    struct queue *q = create_queue ();

    enqueue (q, root);

    //printf ("\nIs empty:%d ", isempty(q));

    while (!isempty(q))
    {
        //printf ("\nheh");
        int q_size = get_size(q);

        while (q_size > 0)
        {
            struct node *temp = dequeue(q);
            printf ("%d ", temp->data);

            if (temp->left)
            {
                //printf ("%d\n",temp->left->data);
                //printf ("%d\n", q->front);
                //printf ("%d\n", q->rear);
                enqueue (q, temp->left);
                //printf ("\ninside 1 %d\n", get_size(q));
                //printf ("%d\n", q->front->tree->data);
            }

            if (temp->right)
            {
                enqueue (q, temp->right);
                //printf ("\ninside 2 %d\n", get_size(q));
                //printf ("%d\n", q->front->tree->data);
            }
            q_size--;
            //printf ("Hello: %d", q_size);
        }
        printf ("\n");
        //printf ("is empty? : %d", isempty(q));
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
  
    printf("Level Order traversal of binary tree is \n"); 
    printlevelorder(root); 
  
    return 0; 
} 