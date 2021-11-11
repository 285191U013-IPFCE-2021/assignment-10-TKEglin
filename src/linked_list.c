#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
    node *p = malloc (sizeof (node));
    p->value = v;

    /*if (q == &SENTINEL_node)
        p->next = &SENTINEL_node;
    else*/

    p->next = q;
    return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
    node *q = p;
    while (q != &SENTINEL_node)
    {
        node *t = q->next;
        free (q);
        q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    node *n = p;
    
    printf("%d ", n->value);

    if(n->next->next != 0) {
        print_list(n->next);
    }
}

int sum_squares (node * p)
{
    node *n = p;
    int sum = 0;

    sum += square(n->value);
    
    if(n->next->next != 0)
        sum += sum_squares(n->next);

    return sum;
}

node *map (node * p, int (*f) (int))
{
    node *n = p;
    node *new_node = malloc(sizeof(node));

    new_node->value = f(n->value);

    if(n->next->next != 0) 
        new_node->next = map(n->next, f);
    else
        new_node->next = &SENTINEL_node;

    return new_node;
}


int square (int x)
{
    return x * x;
}
