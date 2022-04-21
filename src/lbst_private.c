/* A library for creating and using dictionaries of integer (key, data) pairs */

#include <stdio.h>
#include "lbst_private.h"


/* Prints the full tree structure of the dictionary (preorder traversal) */
void lbst_print_tree(struct lbst *root) {
    if (root == NULL) {
        return;
    }
    lbst_print_subtree(root->head);
}


/* Prints the full tree structure of the subtree  (preorder traversal) */
void lbst_print_subtree(struct lbst_node *node) {
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
    lbst_print_subtree(node->lc);
    lbst_print_subtree(node->rc);
}
