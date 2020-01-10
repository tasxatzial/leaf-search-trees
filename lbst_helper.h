/* An abstract data type for storing/manipulating dictionaries of
integer (key, data) pairs */

#ifndef _LBST_HELPER_H_
#define _LBST_HELPER_H_

#include <stdio.h>
#include "lbst_public.h"


/* Prints the full tree structure of the dictionary (preorder traversal) */
void lbst_print_tree(lbst_T root);

#endif