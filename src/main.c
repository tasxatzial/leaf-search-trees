/* Test file for the dictionary library */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "lbst.h"
#include "lbst_private.h"

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

int main() {
    int i, j;
    char *val;
    char **keys, **vals;
    lbst_T root;

    /* create dictionary */
    root = lbst_create();
    srand(time(NULL));

    keys = random_strings("abc", 10, 3);
    vals = random_strings("abc", 10, 3);

    /* insert random (key, val) */
    printf("----------Insert-----------------------------------\n");
    for (i = 0; i < 10; i++) {
        printf("+ [%s :: %s]\n", keys[i], vals[i]);
        lbst_insert(root, keys[i], vals[i]);

        /* print dictionary after each insertion */
        lbst_print(root);
    }

    /* we no longer need the keys, vals */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
        free(vals[i]);
    }
    free(keys);
    free(vals);

    /* print full tree */
    printf("----------Print tree (preorder traversal)----------\n");
    lbst_print_tree(root);

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
            printf("NULL\n");
        }
    }
    
    /* we no longer need the keys */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
    }
    free(keys);

    /* lookup keys in [a, b] */
    printf("----------Range Query [ba to ca]------------------------\n");
    lbst_range_query(root, "ba", "ca");

    /* delete random keys */
    printf("----------Delete-----------------------------------\n");
    keys = random_strings("abc", 10, 3);
    for (i = 0; i < 10; i++) {
        j = rand() % 10;
        printf("- %s\n", keys[j]);
        lbst_delete(root, keys[j]);
        lbst_print(root);
    }

    /* we no longer need the keys */
    for (i = 0; i < 10; i++) {
        free(keys[i]);
    }
    free(keys);

    /* clear dictionary */
    printf("---------------------------------------------------\n");
    printf("Clear dictionary\n");
    lbst_clear(root);

    /* check if empty */
    printf("Check if dictionary is empty (should print 1): %d\n", lbst_is_empty(root));

    /* should print nothing */
    printf("Print dictionary: ");
    lbst_print(root);

    /* re-use dictionary: insert */
    printf("Re-use dictionary. Insert ['nice', 'day']\n");
    lbst_insert(root, "nice", "day");

    printf("Print dictionary: ");
    lbst_print(root);
    
    /* clear dictionary */
    printf("Clear dictionary\n");
    lbst_clear(root);

    printf("Print dictionary: ");
    lbst_print(root);

    /* check if empty */
    printf("Check if dictionary is empty (should print 1): %d\n", lbst_is_empty(root));

    /* destroy dictionary.
    We cannot call any other functions after this */
    printf("Destroy dictionary\n");
    lbst_destroy(root);

    return 0;
}