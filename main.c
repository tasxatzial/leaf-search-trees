/* Test file for the dictionary abstract data type.

Uses functions from lbst_public.h */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lbst_public.h"

int main() {
    int i, key, data;
    lbst_T root;

    root = lbst_create();
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        key = rand() % 20;
        data = rand() % 20;
        printf("Inserting (%d,%d)\n", key, data);
        lbst_insert(root, key, data);
    }
    lbst_delete_dict(root);
    return 0;
}