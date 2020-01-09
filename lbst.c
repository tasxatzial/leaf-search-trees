/* An abstract data type for storing dictionaries

Declarations are in lbst.h, lbst_public.h */

#include <stdio.h>
#include <stdlib.h>
#include "lbst.h"
#include "lbst_public.h"

static void lbst_delete_root(struct lbst *root);
static void lbst_delete_nodes(struct lbst_node *node);


/* Description: See lbst_public.h */
void lbst_insert(lbst_T root, int key, int data) {
    struct lbst *root_private = root;
    struct lbst_node *ptr, *n1, *n2, *parent, *grparent;

    /* special case: root has not been initialized using lbst_create() */
    if (root_private == NULL) {
        printf("Error inserting: NULL root\n");
        return;
    }

    /* special case: 0 (key, data) nodes */
    if (root_private->head == NULL) {
        ptr = malloc(sizeof(struct lbst_node));
        if (ptr == NULL) {
            printf("Error inserting: Mem alloc NULL\n");
            return;
        }
        ptr->key = key;
        ptr->data = data;
        root_private->head = ptr;
        return;
    }

    /* traverse the tree based on the key and find a leaf that will be
    used as parent node of the new nodes. Also remember the parent node
    of that leaf (grparent) */
    ptr = root_private->head;
    parent = NULL;
    grparent = NULL;
    while(ptr != NULL) {
        grparent = parent;
        parent = ptr;
        if (key <= ptr->key) {
            ptr = ptr->lc;
        }
        else {
            ptr = ptr->rc;
        }
    }

    /* update the parent data if the same key was provided */
    if (parent->key == key) {
        parent->data = data;
        return;
    }

    /* create two new nodes n1, n2 */
    n1 = malloc(sizeof(struct lbst_node));
    if (n1 == NULL) {
        printf("Error inserting: Mem alloc NULL\n");
        return;
    }
    n1->rc = NULL;
    n1->lc = NULL;
    n1->next = NULL;

    n2 = malloc(sizeof(struct lbst_node));
    if (n2 == NULL) {
        free(n1);
        printf("Error inserting: Mem alloc NULL\n");
        return;
    }
    n2->rc = NULL;
    n2->lc = NULL;
    n2->next = NULL;

    /* initialize pointers */
    n1->next = parent->next;
    parent->next = n1;
    n2->lc = parent;
    n2->rc = n1;

    /* now arrange (key, data) of grparent, parent, n1, n2 based on
    the new key */
    if (key <= parent->key) {
        n1->key = parent->key;
        n1->data = parent->data;
        parent->key = key;
        parent->data = data;
        n2->key = key;
        n2->data = data;
    }
    else {
        n2->key = parent->key;
        n2->data = parent->data;
        n1->key = key;
        n1->data = data;
    }
    if (grparent != NULL) {
        if (parent == grparent->lc)
            grparent->lc = n2;
        else
            grparent->rc = n2;
    }
    else {
        root_private->head = n2;
    }

    return;
}

void lbst_delete(lbst_T root, int key) {
    
}

/* Description: See lbst_public.h */
int lbst_lookup(lbst_T root, int key) {

    return 0;
}

/* Description: See lbst_public.h */
int lbst_is_empty(lbst_T root) {
    struct lbst *root_private;

    root_private = root;
    if (root_private == NULL) {
        return 1;
    }
    if (root_private->head == NULL) {
        return 1;
    }
    return 0;
}

/* Description: See lbst_public.h */
lbst_T lbst_create() {
    struct lbst *root_private;

    root_private = malloc(sizeof(struct lbst));
    root_private->head = NULL;

    return (lbst_T) root_private;
}

/* Description: See lbst_public.h */
void lbst_delete_dict(lbst_T root) {
    struct lbst *root_private;

    root_private = root;
    if (root_private == NULL) {
        return;
    }
    lbst_delete_nodes(root_private->head);
    lbst_delete_root(root_private);
}

/* Frees memory allocated for the root node of the dictionary */
static void lbst_delete_root(struct lbst *root) {
    if (root == NULL) {
        return;
    }
    free(root);
}

/* Frees memory allocated for all (key, data) nodes of the dictionary */
static void lbst_delete_nodes(struct lbst_node *node) {
    if (node == NULL) {
        return;
    }
    lbst_delete_nodes(node->lc);
    lbst_delete_nodes(node->rc);
    free(node);
}

void lbst_range_query(lbst_T root, int first, int last) {

}

/* Description: See lbst_public.h */
void lbst_print(lbst_T root) {
    struct lbst *root_private;
    struct lbst_node *ptr, *prev;

    root_private = root;
    if (root_private == NULL) {
        return;
    }

    /* Go to leftmost leaf node */
    ptr = root_private->head;
    prev = NULL;
    while(ptr != NULL) {
        prev = ptr;
        ptr = ptr->lc;
    }

    /* Use the next pointers to traverse the nodes
    that start from the leftmost leaf to the rightmost leaf */
    while(prev != NULL) {
        printf("<%d, %d> ", prev->key, prev->data);
        prev = prev->next;
    }

    printf("\n");
}