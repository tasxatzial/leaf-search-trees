/* Leaf-oriented binary search tree module.

Description: Implementation of a dictionary abstract data type.
*/

#ifndef _LBST_PUBLIC_H_
#define _LBST_PUBLIC_H_

#include <stdio.h>

typedef void* lbst_T;

void lbst_insert(lbst_T root, int key, int data);
void lbst_delete(lbst_T root, int key);
int lbst_lookup(lbst_T root, int key);
int lbst_is_empty(lbst_T root);
lbst_T lbst_create();

void lbst_delete_tree(lbst_T root);
void lbst_range_query(lbst_T root, int first, int last);
void lbst_print(lbst_T root, int first_call);
void lbst_print_leaves(lbst_T root, int first_call);

#endif