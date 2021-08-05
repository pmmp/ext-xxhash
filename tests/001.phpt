--TEST--
Check if xxhash is loaded
--SKIPIF--
<?php
if (!extension_loaded('xxhash')) {
    echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "xxhash" is available';
?>
--EXPECT--
The extension "xxhash" is available
