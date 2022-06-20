#ifndef _LBST_H_
#define _LBST_H_

#include <stdio.h>

typedef void* lbst_T;


/* Inserts a new (key, val) into the dictionary. If key is already in the
dictionary, its val is updated.

Returns 1 on success, else 0.

Time complexity: O(h) */
int lbst_insert(lbst_T root, char *key, char *val);


/* Deletes a key from the dictionary.

Time complexity: O(h) */
void lbst_delete(lbst_T root, char *key);


/* Searches for a key in the dictionary.

If found, it returns the a pointer to its val, else it returns NULL.

Time complexity: O(h) */
char *lbst_lookup(lbst_T root, char *key);


/* Returns 1 if dictionary has no keys, 0 otherwise */
int lbst_is_empty(lbst_T root);


/* Creates and returns an empty dictionary. Its (key, val) pairs have
type (char *, char *).

Returns NULL on fail.*/
lbst_T lbst_create();


/* Clears the dictionary. The function lbst_is_empty() returns 1 after
calling this one. */
void lbst_clear(lbst_T root);


/* Clears the dictionary. No other functions should be called after
calling this one. */
void lbst_destroy(lbst_T root);


/* Prints (key, val) that satisfy first <= key <= last.

Time complexity: O(h + last - first) */
void lbst_range_query(lbst_T root, char *first, char *last);


/* Prints the dictionary. (key, val) pairs are sorted by key.

Time complexity: O(h + #keys) */
void lbst_print(lbst_T root);

#endif