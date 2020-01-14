# Description

Library for storing and manipulating dictionaries, that is collections of (key, value) pairs.

Internally the dictionary is stored as a leaf-oriented [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) structure. For more details on the implementation see [lbst.pdf](lbst.pdf)

The following functions are implemented:

* lbst_create(): Create an empty dictionary
* lbst_is_empty(dictionary): Check whether dictionary is empty
* lbst_insert(dictionary, key, value): Insert (key, value) into dictionary
* lbst_delete(dictionary, key): Delete key from dictionary
* lbst_lookup(dictionary, key, value): Get the value associated with key
* lbst_print(dictionary): Print all dictionary (key, value)
* lbst_range_query(dictionary, first, last): Print all dictionary (key, value) with key between first and last
* lbst_print_tree(dictionary): Print the full dictionary tree structure
* lbst_delete_dict(dictionary): Delete dictionary and free memory

Note: The program currently supports only integer keys/values.

## Compile

The program is written in C.

To compile, use the provided Makefile:

```bash
make lbst
```

## Typical usage

To run the tests in [main.c](main.c), execute:

```bash
./lbst
```
