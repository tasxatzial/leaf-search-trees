/* An abstract data type for storing dictionaries.

Declarations are in lbst.h, lbst_public.h, lbst_helper.h */

#include <stdio.h>
#include <stdlib.h>
#include "lbst.h"
#include "lbst_helper.h"
#include "lbst_public.h"

static void lbst_print_nodes(struct lbst_node *node);


/* Description: See lbst_helper.h */
void lbst_print_tree(lbst_T root) {
    struct lbst *root_private;

    root_private = root;
    if (root_private == NULL) {
        return;
    }
    lbst_print_nodes(root_private->head);
}

/* Prints the full tree structure of the dictionary (preorder traversal) */
static void lbst_print_nodes(struct lbst_node *node) {
    if (node == NULL) {
        return;
    }
    if (node->next != NULL) {
        printf("<%d,%d> -- ", node->key, node->data);
        printf("next: <%d,%d>\n", node->next->key, node->next->data);
    }
    else {
        printf("<%d,%d>\n", node->key, node->data);
    }
    lbst_print_nodes(node->lc);
    lbst_print_nodes(node->rc);
}