/* Leaf-oriented binary search tree module. Uses lbst_public.h

Description: Implementation of a dictionary abstract data type.

NOTE: This file contains internal implementation details
and should not be publicly available. Distribute
lbst_public.h instead */

#ifndef _LBST_H_
#define _LBST_H_

#include <stdio.h>
#include "lbst_public.h"

struct lbst {
    struct lbst_node *head;
};

struct lbst_node {
    int key;
    int data;
    struct lbst_node *lc;
    struct lbst_node *rc;
    struct lbst_node *next;
};

#endif