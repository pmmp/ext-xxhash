--TEST--
Test that a call to xxhash64() produces the same hash that xxhsum does for a known preimage
--EXTENSIONS--
xxhash
--FILE--
<?php

var_dump(bin2hex(xxhash64("hello\n")));

?>
--EXPECT--
string(16) "e4c191d091bd8853"

