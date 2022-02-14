# lbst

Library for creating and using dictionaries, that is, sorted collections by key of (key, value) pairs.

The following functions are provided:

* lbst_create(): Create an empty dictionary.
* lbst_is_empty(dictionary): Check whether dictionary is empty.
* lbst_insert(dictionary, key, value): Insert (key, value) into dictionary. If key exists, update its value.
* lbst_delete(dictionary, key): Delete key from dictionary.
* lbst_lookup(dictionary, key, value): Get the value associated with key.
* lbst_print(dictionary): Print all dictionary (key, value).
* lbst_range_query(dictionary, first, last): Print all dictionary (key, value) with key between first and last.

## Implementation

Internally the dictionary is stored as a leaf-oriented binary search tree structure. Time complexity of operations 'insert', 'delete', 'lookup' is O(tree_height) whereas 'range_query' has a complexity of O(tree_height + last - first). More details about 'insert' and 'delete' can be found in [lbst.md](docs/lbst.md) (english) and [lbst.pdf](docs/lbst.pdf) (greek).

**Note**: Currently only integer keys/values are supported. Pairs are sorted by keys (ascending).

## Compile

Use the provided Makefile:

```bash
make lbst.o
```

The above command builds a module that contains the functions declared in lbst.h only.

## Demo

Using the library is demonstrated in [main.c](src/main.c).

Build:

```bash
make lbst_demo
```

Run:

```bash
./lbst_demo
```
