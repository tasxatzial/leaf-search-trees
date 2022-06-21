#include <stdio.h>
#include <assert.h>
#include "lbst_private.h"


/* Prints the full tree structure of the dictionary (preorder traversal) */
void lbst_print_tree(struct lbst *root, void (*print)(char *key, void *val)) {
    assert(print);
    assert(root);

    lbst_print_subtree(root->head, print);
}


/* Prints the full tree structure of the subtree  (preorder traversal) */
void lbst_print_subtree(struct lbst_node *node, void (*print)(char *key, void *val)) {
    if (node == NULL) {
        return;
    }
    print(node->key, node->val);
    if (node->next != NULL) {
        printf(" --> ");
        print(node->key, node->val);
    }
    printf("\n");

    lbst_print_subtree(node->lc, print);
    lbst_print_subtree(node->rc, print);
}
