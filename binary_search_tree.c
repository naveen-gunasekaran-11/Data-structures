// C program to demonstrate different operations in a binary search tree
#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
    int key; 
    struct node *left;
    struct node *right; 
}; 

struct node* new_node(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = NULL;
    temp->right = NULL; 
    return temp; 
} 

void inorder (struct node *root)
{
    if (root != NULL)
    {
        inorder (root->left);
        printf ("%d ", root->key);
        inorder (root->right);
    }
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL)
    {
        return new_node (key);
    }

    if (key < node->key)
    {
        node->left = insert (node->left, key);
    }
    else
    {
        node->right = insert (node->right, key);
    }

    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* temp = node;

    if (temp == NULL)
    return node;

    while ((temp != NULL) && (temp->left != NULL))
    {
        temp = temp->left;
    }

    return temp;
}

struct node* find_node (struct node *root, int data)
{
    if ((root == NULL) || (root->key == data))
    {
        return root;
    }

    if (data < root->key)
    {
        return find_node (root->left, data);
    }
    else if (data > root->key)
    {
        return find_node (root->right, data);
    }
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
    return root;

    if (key < root->key)
    {
        root->left = deleteNode (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode (root->right, key);
    }
    else
    {
        if ((root->right == NULL) && (root->left == NULL))
        {
            free (root);
            root = NULL;
            return root;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free (root);
            return temp;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free (root);
            return temp;
        }

        struct node *temp = minValueNode (root->right);
        root->key = temp->key;
        root->right = deleteNode (root->right, temp->key);
    }

    return root;
}

int main ()
{
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    printf ("%d \n", root->key);
    inorder(root);
    printf ("\n");

    root = deleteNode(root, 20);
    inorder(root);
    printf ("\n");

    root = deleteNode(root, 50);
    inorder(root);
    printf ("\n");


    struct node *search_node = find_node (root, 40);
    printf ("Searched node --> %d \n", search_node->key);

    search_node = find_node (root, 70);
    printf ("Searched node --> %d \n", search_node->key);

    return 0;
}
