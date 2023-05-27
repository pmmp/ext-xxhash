# ext-xxhash
This extension is a PHP binding for the [xxhash](https://github.com/Cyan4973/xxHash) library.

xxhash v0.8.1 is included as a subtree.

## Why still maintain this extension? Doesn't PHP 8.1 now have builtin xxhash support?
PHP's `hash()` function relies on string lookups of the algorithm name, and has extra logic that we don't need, making it slower than this extension.
In addition, this extension provides specialized functions for integer hashing, which are performance-critical.

A quick performance benchmark on an i7-12700K with a payload of 8 zero-bytes (one of the smallest possible payloads) has a PHP runtime of 20 ns for `xxhash64()`, vs 51 ns for `hash('xxh64', binary: true)`.
This might not sound like much in real terms, but these small inefficiencies add up in hot paths.

## API
See [`xxhash.stub.php`](/xxhash.stub.php) for a list of functions.
