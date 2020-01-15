# Description

Library for creating and using dictionaries, that is, collections of (key, value) pairs.

The following functions are provided:

* lbst_create(): Create an empty dictionary
* lbst_is_empty(dictionary): Check whether dictionary is empty
* lbst_insert(dictionary, key, value): Insert (key, value) into dictionary
* lbst_delete(dictionary, key): Delete key from dictionary
* lbst_lookup(dictionary, key, value): Get the value associated with key
* lbst_print(dictionary): Print all dictionary (key, value)
* lbst_range_query(dictionary, first, last): Print all dictionary (key, value) with key between first and last
* lbst_delete_dict(dictionary): Delete dictionary and free memory
* lbst_print_tree(dictionary): Print the full dictionary tree structure

## Language

C.

## Implementation

Internally the dictionary is stored as a leaf-oriented binary search tree structure. Operations like 'insert', 'delete', 'lookup' should run in O(h) time whereas 'range_query' should run in O(h + last - first) time. For more details about the implementation see [lbst.pdf](lbst.pdf) (in greek).

Note: Currently only integer keys/values are supported.

## Compile

Use the provided Makefile:

### Building the library

```bash
make lbst.o
```

Note: The above command builds a module that contains only the functions declared in lbst_public.h. It does not
include the function lbst_print_tree which is related to the internal dictionary representation and is not necessary for using the library.

### Building the test files

Using the library is demonstrated in [main.c](main.c). Build the tests with:

```bash
make lbst_test
```

and run with:

```bash
./lbst_test
```
