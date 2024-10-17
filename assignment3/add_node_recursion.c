#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

void in_order(struct node *trav);
struct node *create_node(int data);
struct node *add_node(struct node *root, int data);



int main()
{

    root = add_node(root, 28);
    add_node(root, 50);
    add_node(root, 30);
    add_node(root, 59);
    add_node(root, 59);
    add_node(root, 44);
    add_node(root, 35);
    add_node(root, 77);
    add_node(root, 88);
    add_node(root, 85);
    add_node(root, 75);
    add_node(root, 70);

    printf("\n in order :\n");
    in_order(root);

    return 0;
}

struct node *create_node(int data)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct node *add_node(struct node *root, int data)
{

    if (root == NULL)
    {
        return create_node(data);
    }

    if (data < root->data)
    {
        root->left = add_node(root->left, data);
    }
    else
    {
        root->right = add_node(root->right, data);
    }

    return root;
}

void in_order(struct node *trav)
{
    if (trav == NULL)
    {
        return;
    }
    in_order(trav->left);
    printf("%4d", trav->data);
    in_order(trav->right);
}
