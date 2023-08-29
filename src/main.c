/* Test file for the dictionary library */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "lbst.h"
#include "lbst_private.h"

static char** random_strings(char *alphabet, int num_keys, int max_key_len);
static void print(char *key, void *val);


int main() {
    int i, j;
    char *val;
    char **keys, **vals;
    lbst_T root;

    root = lbst_create();
    srand(time(NULL));

    keys = random_strings("abc", 10, 3);
    vals = random_strings("abc", 10, 3);

    /* insert random (key, val) */
    printf("----------Insert-----------------------------------\n");
    for (i = 0; i < 10; i++) {
        printf("+ [%s :: %s]\n", keys[i], vals[i]);
        lbst_insert(root, keys[i], vals[i]);
        lbst_print(root, print);
    }

    /* we no longer need the keys but we need the vals */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
    }
    free(keys);

    printf("----------Print tree (preorder traversal)----------\n");
    lbst_print_tree(root, print);

    /* lookup random keys */
    printf("----------Lookup-----------------------------------\n");
    keys = random_strings("abc", 10, 3);
    for (i = 0; i < 10; i++) {
        j = rand() % 10;
        printf("%s :: ", keys[j]);
        val = lbst_lookup(root, keys[j]);
        if (val) {
            printf("%s\n", val);
        }
        else {
            printf("Not found\n");
        }
    }
    
    /* we no longer need the keys */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
    }
    free(keys);

    printf("----------Range Query [ba to ca]------------------------\n");
    lbst_range_query(root, "ba", "ca", print);

    /* delete random keys */
    printf("----------Delete-----------------------------------\n");
    keys = random_strings("abc", 10, 3);
    for (i = 0; i < 10; i++) {
        j = rand() % 10;
        printf("- %s\n", keys[j]);
        lbst_delete(root, keys[j]);
        lbst_print(root, print);
    }

    /* we no longer need the keys */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
    }
    free(keys);

    printf("---------------------------------------------------\n");
    printf("Clear dictionary\n");
    lbst_clear(root);

    printf("Check if dictionary is empty (should print 1): %d\n", lbst_is_empty(root));

    printf("Print dictionary: ");
    lbst_print(root, print);

    printf("Insert ['nice', 'day']\n");
    lbst_insert(root, "nice", "day");

    printf("Print dictionary: ");
    lbst_print(root, print);
    
    printf("Delete 'nice'\n");
    lbst_delete(root, "nice");

    printf("Print dictionary: ");
    lbst_print(root, print);

    printf("Check if dictionary is empty (should print 1): %d\n", lbst_is_empty(root));

    /* We cannot call any other functions after deleting the dictionary */
    printf("Delete dictionary\n");
    lbst_free(root);

    /* clear whatever is left */
    for (i = 0; i < 10; i++) {
        free(vals[i]);
    }
    free(vals);

    return 0;
}


/* Creates an array of character arrays (keys). Each key has
at most max_key_len characters and is created by selecting random characters
from the character array alphabet.

Runtime checks:
1) if alphabet is not NULL
2) if length of alphabet is not 0
3) if number of keys is >=0
4) if maximum key length is >0
5) if memory was allocated succesfully for keys

Parameters:
alphabet: pointer to an array of characters. Must be null-terminated.
num_keys: the number of keys in the array.
max_key_len: the maximum number of characters in each key.

Returns: a pointer to an array of non-empty null-terminated keys. */
static char** random_strings(char *alphabet, int num_keys, int max_key_len) {
    char **keys;
    int i, j, rand_int, alpha_length;

    assert(alphabet);
    assert(num_keys >= 0);
    assert(max_key_len > 0);
    alpha_length  = strlen(alphabet);
    assert(alpha_length);
    keys = malloc(num_keys * sizeof(char *));
    assert(keys);

    for (i = 0; i < num_keys; i++) {

        /* generate a random length for each key */
        rand_int = rand() % max_key_len + 1;
        keys[i] = malloc((rand_int + 1) * sizeof(char));

        /* fill the key with random characters from alphabet */
        for (j = 0; j < rand_int; j++) {
            keys[i][j] = alphabet[rand() % alpha_length];
        }
        keys[i][j] = '\0';
    }
    return keys;
}


/* Prints the key and val of a dictionary entry.

Checks: if val is not NULL at runtime.

Parameters:
key: pointer to a character array. Must be null-terminated.
val: pointer to a void value (treated as char*).

Returns: void */
static void print(char *key, void *val) {
    char *value;

    assert(key);

    value = val;
    printf("[%s::%s]", key, value);

    return;
}
