# ext-xxhash
This extension is a PHP binding for the [xxhash](https://github.com/Cyan4973/xxHash) library.

xxhash v0.8.1 is included as a subtree.

## Why still maintain this extension? Doesn't PHP 8.1 now have builtin xxhash support?
PHP's hash() function relies on string lookups of the algorithm name, and has extra logic that we don't need, making it slower than this extension.
In addition, this extension provides specialized functions for integer hashing, which are performance-critical.

## API
See [`xxhash.stub.php`](/xxhash.stub.php) for a list of functions.
