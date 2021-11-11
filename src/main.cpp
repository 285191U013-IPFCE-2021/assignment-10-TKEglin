extern "C"{
    #include <stdio.h>
    #include "btree.h"
    #include "linked_list.h" 
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    int sum;
    node *ns = NULL;

    ns = make_node (1,
	      make_node (2,
		   make_node (3,
			make_node (4,
			 make_node (5, &SENTINEL_node)))));
    
    print_list(ns);

    printf("\n\nSum square test:");
    printf("\n%d", sum_squares(ns));
    
    node* mns = NULL;
    printf("\n\nMap test:\n");
    mns = map(ns, square);
    print_list(mns);


    printf("\n\n\n***btree.c test:***");
    struct tree_node *root = NULL;

    root = Initialize (root);
    root = Insert (20, root);
    root = Insert (5, root);
    root = Insert (1, root);
    root = Insert (15, root);
    root = Insert (9, root);
    root = Insert (7, root);
    root = Insert (12, root);
    root = Insert (30, root);
    root = Insert (25, root);
    root = Insert (40, root);
    root = Insert (45, root);
    root = Insert (42, root);

    printf("\n\n");
    //print_tree(root, 0);

    printf("\n\nContains 20: %d", Contains(20, root));
    printf("\nContains 5: %d", Contains(5, root));
    printf("\nContains 1: %d", Contains(1, root));
    printf("\nContains 15: %d", Contains(15, root));
    printf("\nContains 9: %d", Contains(9, root));
    printf("\nContains 7: %d", Contains(7, root));
    printf("\nContains 12: %d", Contains(12, root));
    printf("\nContains 30: %d", Contains(30, root));
    printf("\nContains 25: %d", Contains(25, root));
    printf("\nContains 40: %d", Contains(40, root));
    printf("\nContains 45: %d", Contains(45, root));
    printf("\nContains 42: %d", Contains(42, root));
    printf("\nContains 2: %d", Contains(2, root));
    printf("\nContains 3: %d", Contains(3, root));
    printf("\nContains 200: %d", Contains(200, root));
    
    printf("\n\nEmpty REQUIRE: %d", Empty(Initialize(NULL)));


    Remove(20, root);
    
    //printf("\n\nAfter remove, contains 20: %d", Contains(20, root));

    printf("\n\n\n**Main function reached end**");
    
    return 0;
}