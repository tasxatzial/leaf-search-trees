/* An abstract data type for storing dictionaries.

NOTE: If we choose to hide internal implementation details, only
lbst_public.h should be distributed. */

#ifndef _LBST_H_
#define _LBST_H_

#include <stdio.h>
#include "lbst_public.h"

/* A special node for the root node of the dictionary.
Pointers to lbst_T (declared in lbst_public.h) should be
cast to this struct when they are treated as the root node of
the dictionary. */
struct lbst {
    struct lbst_node *head;
};

/* Nodes that store a (key, data) pair. They are always
internal nodes in the dictionary.
Pointers to lbst_T (declared in lbst_public.h) should be cast
to this struct when they are not treated as the root node of
the dictionary. */
struct lbst_node {
    int key;
    int data;
    struct lbst_node *lc;
    struct lbst_node *rc;
    struct lbst_node *next;
};

#endif