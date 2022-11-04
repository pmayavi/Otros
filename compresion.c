#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data_element;
    int uses;
    char char_element;
    struct node *left, *right, *father;
};

struct node *new_node(int uses, char char_element, struct node *father)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node)); // Allocating memory to the node
    temp->data_element = 1;
    temp->uses = uses;
    temp->char_element = char_element;
    temp->left = temp->right = NULL;
    temp->father = father;
    return temp;
}

void display(struct node *root) // A function for the inroder traversal of the binary tree
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d \n", root->char_element);
        display(root->right);
    }
}

void insert(struct node *father, struct node *node) // Function to insert a new node
{
    if (father->char_element != 0)
        return;
    if (!father->left)
    {
        father->left = new_node(node->uses, 0, father);
        father->left->right = node;
    }
    else
    {
        recursion(father->left, node);
        recursion(father->right, node);
    }
}

int main()
{
    char input[1024];
    char letters[107];
    size_t let = 0;
    int num[107];
    gets(input);
    int new;
    struct node *root = NULL;
    root = new_node(0, 0, NULL);
    for (size_t i = 0; i < strlen(input); i++)
    {
        new = 1;
        for (size_t j = 0; j < strlen(letters); j++)
        {
            if (input[i] == letters[j])
            {
                new = 0;
                break;
            }
        }
        if (new)
        {
            letters[let++] = input[i];
            insert(root, input[i]);
        }
    }

    display(root); // Function to display the binary tree elements

    return 0;
}