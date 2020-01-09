/* An abstract data type for storing dictionaries */

#ifndef _LBST_PUBLIC_H_
#define _LBST_PUBLIC_H_

#include <stdio.h>

typedef void* lbst_T;

/* Inserts a new (key, data) into the dictionary. If key is already in the
dictionary, its data is updated */
void lbst_insert(lbst_T root, int key, int data);

void lbst_delete(lbst_T root, int key);
int lbst_lookup(lbst_T root, int key);
int lbst_is_empty(lbst_T root);

/* Creates and returns an empty dictionary. Its (key, data) pairs have
type (int, int). Key should be unique. */
lbst_T lbst_create();

void lbst_delete_tree(lbst_T root);
void lbst_range_query(lbst_T root, int first, int last);
void lbst_print(lbst_T root, int is_root);

#endif