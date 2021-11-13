#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
    struct tree_node *root = t;

    //If an end of the tree has been found, the new node can be inserted
    if(root == NULL) {
        root = malloc(sizeof(struct tree_node));

        root->item = x;
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    
    //Recursively moving through the tree until a NULL pointer is found
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
    struct tree_node *root = t,  //Pointer for traversing the tree
                     *store = t; //Pointer for storing node to free()

    //When the item to be removed has been found, the tree needs to be rearranged
    if(t->item == x) {
        if(t->right == NULL && t->left == NULL) {
            //If both pointers are NULL, the node can simply be removed
            free(store);
            return NULL;
        }
        if(t->right == NULL && t->left != NULL) {
            //If there is only one branch, it can simply be moved up the tree
            t = t->left;
            free(store);
            return t;
        }
        if(t->right != NULL && t->left == NULL) {
            //If there is only one branch, it can simply be moved up the tree
            t = t->right;
            free(store);
            return t;
        }
        if(t->right != NULL && t->left != NULL) {
            root = t->left;
            /* The goal here is to find the largest item of the left (smaller) branch, *
             * so that the left branch will not contain a larger number than t->item.  *
             * In practice, this means finding a node with no right branch and setting *
             * t->item equal to it, and then removing that node.                       */
            
            if(root->right == NULL) {
                t->item = root->item;
                t->left = root->left;
                free(root);
                return t;
            }
            else {
                /* In order to maintain pointer to the node I am    *
                 * manipulating, I stop one node before reaching it */
                while(root->right->right != NULL)
                    root = root->right;

                t->item = root->right->item;
                store = root->right;
                root->right = root->right->left;
                free(store);
                return t;
            }            
        }
    }
    
    if(root->left != NULL && x <= root->item) {
        t->left = Remove(x, root->left);
    }
    if(root->right != NULL && x > root->item) {
        t->right = Remove(x, root->right);
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
    if(root->right != NULL && x > root->item) {
        sresult = Contains(x, root->right);
    }

    return sresult;
}


struct tree_node * Initialize (struct tree_node *t)
{
    return NULL;
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
        print_tree (p->right, depth + 1);
}