#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
    struct tree_node *root = t;

    if(root == NULL) {
        root = malloc(sizeof(struct tree_node));

        root->item = x;
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    
    if(x <= root->item) {
        root->left = Insert(x, root->left);
    }
    if(x > root->item) {
        root->right = Insert(x, root->right);
    }

    return root;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
    struct tree_node *root = t;

    //If x isn't in the tree, it can't be removed
    if(!Contains(x, t)) return t;

    if(t->item == x) {
        if(t->right == NULL && t->left == NULL) {
            t = NULL;
            return t;
        }
        if(t->right == NULL && t->left != NULL) {
            root = t;
            t = t->left;
            free(root);
            return t;
        }
        if(t->right != NULL && t->left == NULL) {
            root = t;
            t = t->right;
            free(root);
            return t;
        }
        if(t->right != NULL && t->left != NULL) {
            root = root->right;
            while(root->left != NULL) {
                root = root->left;
            }
            t->item = root->item;
            root = NULL;
        }

        free(root);
        return t;
    }
    else if(root->left != NULL && x <= root->item) {
        root = Remove(x, root->left);
    }
    else if(root->left != NULL && x > root->item) {
        root = Remove(x, root->right);
    }

    return t;
}


int Contains (int x, struct tree_node *t)
{
    struct tree_node *root = t;
    int sresult = 0; //Search result

    //If the tree is empty, it does not contain x
    if(Empty(t)) return sresult;

    if(root->item == x) {
        return 1;
    }
    
    if(root->left != NULL && x <= root->item) {
        sresult = Contains(x, root->left);
    }
    else if(root->right != NULL && x > root->item) {
        sresult = Contains(x, root->right);
    }

    return sresult;
}


struct tree_node * Initialize (struct tree_node *t)
{
    struct tree_node *root = t;
    root = NULL;

    return root;
}

int Empty (struct tree_node *t)
{
    if(t == NULL)
        return 1;
    else 
        return 0;
}

int Full (struct tree_node *t)
{
    return 0;
}

void print_tree (struct tree_node * p, int depth) {
    int i;

    for (i = 0; i < depth; i = i + 1)
    printf (" ");
    printf ("| ");

    if (p == NULL)
        printf ("NULL\n");
    else
        printf ("[%d]\n", p->item);


    if (p->left)
        print_tree (p->left, depth + 1);

    if (p->right)
        print_tree (p->left, depth + 1);
}