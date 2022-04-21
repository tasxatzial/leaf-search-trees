# lbst - A dictionary data structure

Library for creating and using dictionaries, that is, sorted collections by key of (key, value) pairs.

The following functions are provided:

* lbst_create(): Create an empty dictionary.
* lbst_is_empty(d): Check whether is empty.
* lbst_insert(d, key, value): Insert (key, value). If key exists, update its value.
* lbst_delete(d, key): Delete key.
* lbst_lookup(d, key, *value): Get the value associated with key.
* lbst_print(d): Print the dictionary.
* lbst_clear(d): Clear the dictionary.
* lbst_destroy(d): Clear the dictionary. No other functions can be used after this one.
* lbst_range_query(d, first, last): Print all (key, value) with key between first and last (inclusive).

## Implementation

The library comes with an [opaque data type](https://en.wikipedia.org/wiki/Opaque_data_type) that can be used with the above function. The representation of the type is completely hidden from its users.

Internally the dictionary is stored as a leaf-oriented binary search tree structure. Time complexity of operations 'insert', 'delete', 'lookup' is O(tree_height) whereas 'range_query' has a complexity of O(tree_height + last - first). More details about 'insert' and 'delete' can be found in [lbst.md](docs/lbst.md) (english) and [lbst.pdf](docs/lbst.pdf) (greek).

**Note**: Currently only integer keys and values are supported. Sorting is by key (ascending).

## Profiling

The program has been tested for memory leaks with [valgrind](https://valgrind.org/) and [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer).

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
