/* An abstract data type for storing dictionaries */

#ifndef _LBST_PUBLIC_H_
#define _LBST_PUBLIC_H_

#include <stdio.h>

typedef void* lbst_T;
typedef void* lbst_T_pair;

/* Inserts a new (key, data) into the dictionary. If key is already in the
dictionary, its data is updated */
void lbst_insert(lbst_T root, int key, int data);

void lbst_delete(lbst_T root, int key);


/* Finds a key in the dictionary.

If key is found, return value is 1 and the specified data pointer provides
access to key data.
If key is not found, return value is 0 and the specified data pointer should
be ignored. */
int lbst_lookup(lbst_T root, int key, int *data);

/* Returns 1 if dictionary has no (key, data) pairs, 0 otherwise */
int lbst_is_empty(lbst_T root);

/* Creates and returns an empty dictionary. Its (key, data) pairs have
type (int, int). Key should be unique. */
lbst_T lbst_create();

/* Deletes dictionary and frees allocated memory */
void lbst_delete_dict(lbst_T root);

/* Prints (key, data) that satisfy first <= key <= last */
void lbst_range_query(lbst_T root, int first, int last);

/* Prints the dictionary. Sorting is based on key relationship < */
void lbst_print(lbst_T root);

#endif