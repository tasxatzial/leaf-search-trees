/* Leaf-oriented binary search tree module.
Declared in lbst.h and lbst_public.h

Description: Implementation of a dictionary abstract data type.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lbst.h"

void lbst_insert(lbst_T root, int key, int data) {

}

void lbst_delete(lbst_T root, int key) {
    
}

int lbst_lookup(lbst_T root, int key) {

    return 0;
}

int lbst_is_empty(lbst_T root) {

    return 0;
}

lbst_T lbst_create() {
    struct lbst *root_private;

    root_private = malloc(sizeof(struct lbst));
    root_private->head = NULL;

    return (lbst_T) root_private;
}

void lbst_delete_tree(lbst_T root) {
    
}

void lbst_range_query(lbst_T root, int first, int last) {

}

void lbst_print(lbst_T root, int first_call) {

}

void lbst_print_leaves(lbst_T root, int first_call) {
    
}