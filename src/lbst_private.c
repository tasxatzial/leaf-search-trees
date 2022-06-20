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
    printf("[%s :: %s]", node->key, node->val);
    if (node->next != NULL) {
        printf(" --> [%s :: %s]", node->next->key, node->next->val);
    }
    printf("\n");

    lbst_print_subtree(node->lc);
    lbst_print_subtree(node->rc);
}
