#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;
void add_first(int data);
node* create_node();
void display();
void add_last(int data);
void delete_first();
void delete_last();
struct node *search(int key);

int main()
{
    add_first(45);
    add_first(60);
    add_first(85);
    display();
    // head->85->60->45
    add_last(20);
    add_last(90);
    add_first(65);
    add_last(10);
    display();
    // head->65->85->60->45->20->90->10

    delete_first();
    display();
    // head->85->60->45->20->90->10

    delete_last();
    display();
    // head->85->60->45->20->90


    struct node *result;
    result=search(120);
    if(result==NULL)
    printf("key not found!\n");
    else
    printf("key found!\n");
    return 0;
}


node* create_node()
{
    node *new_node  = (node*)malloc(sizeof(node));
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

void add_first(int data)
{
    // create

    node* new_node =  create_node();
    new_node->data = data;

    // attach
    // if list is empty

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head; // circular
    }
    else
    {
        node *trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        new_node->next = head;
        head = new_node;

        trav->next = head; // circular
    }
}

void display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        node *trav = head;

        printf("Head");
        do{
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav != head);
    }
    printf("\n");
}

void add_last(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
    }
    else
    {
        node* trav = head;

        while(trav->next != head)
        {
            trav = trav->next;
        }
        trav->next = new_node;
        new_node->next = head; // circular
    }
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        node *temp = head;

        head = temp->next;

        trav->next = head;

        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        // traverse till second last node
        struct node *trav = head;

        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head; // circular
    }
}

struct node *search(int key)
{
    struct node *trav=head;

    do
    {
        if(trav->data==key)
        return trav;

        trav=trav->next;
    
    }while(trav != head);

    return NULL;
}