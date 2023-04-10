# Leaf-oriented binary search trees

A data structure that can be used for storing dictionaries, which are sorted collections of (key, value) pairs, sorted by key.

This version supports (key, value) pairs that have type (char*, void*).

The following functions are provided:

* lbst_create(): Create an empty dictionary.
* lbst_is_empty(d): Check whether the dictionary is empty.
* lbst_insert(d, key, value): Insert (key, value). If key exists, update its value.
* lbst_delete(d, key): Delete key.
* lbst_lookup(d, key): Get the value associated with key.
* lbst_print(d): Print the dictionary.
* lbst_clear(d): Clear the dictionary.
* lbst_destroy(d): Clear the dictionary. No other functions should be used after this one.
* lbst_range_query(d, first, last): Print all pairs with key between first and last (inclusive).

## Implementation

The dictionary is defined as an [opaque data type](https://en.wikipedia.org/wiki/Opaque_data_type). The public interface is defined in [lbst.h](src/lbst.h).

C-strings are supported as keys and are stored directly in the dictionary. Values can be of any type, therefore they should already be stored in a different data structure.

Time complexity is O(tree_height) for 'insert', 'delete', 'lookup' and O(tree_height + number of keys) for 'range_query'. Details can be found in [lbst.md](lbst.md).

For a simpler version of the library that supports only (int, int) pairs, see [leaf-search-tree-int.c](https://github.com/tasxatzial/leaf-search-tree-int.c).

## Compile

Build the library (functions declared in [lbst.h](src/lbst.h)):

```bash
make lbst.o
```

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

## Profiling

'lbst_demo' has been tested for memory leaks with [valgrind](https://valgrind.org/) and [AddressSanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer).
