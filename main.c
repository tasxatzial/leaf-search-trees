/* Test file for the dictionary abstract data type.

Uses functions from lbst_public.h ,lbst_helper.h */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lbst_public.h"
#include "lbst_helper.h"

int main() {
    int i, key, data, found;
    lbst_T root;

    /* create dictionary */
    root = lbst_create();
    srand(time(NULL));

    
    for (i = 0; i < 10; i++) {
        key = rand() % 15;
        data = rand() % 15;
        printf("Inserting (%d,%d)\n", key, data);

        /* insert random (key, data) */
        lbst_insert(root, key, data);

        /* print dictionary after each insertion */
        lbst_print(root);
    }

    /* print full tree structure */
    printf("Full dictionary tree (preorder traversal):\n");
    lbst_print_tree(root);

    /* lookup 3 random (key, data) */
    for (i = 0; i < 3; i++) {
        key = rand() % 15;
        printf("Lookup key %d -> ", key);
        found = lbst_lookup(root, key, &data);
        if (found) {
            printf("Data: %d\n", data);
        }
        else {
            printf("Not found\n");
        }
    }
    
    /* delete dictionary and free memory */
    lbst_delete_dict(root);
    
    return 0;
}