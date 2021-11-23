--TEST--
Test that a call to xxhash32() produces the same hash that xxhsum does for a known preimage
--EXTENSIONS--
xxhash
--FILE--
<?php

var_dump(bin2hex(xxhash32("hello\n")));

?>
--EXPECT--
string(8) "946b5bf9"

