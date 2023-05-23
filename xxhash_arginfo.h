/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 115e3a4dde51883c76ce7f47d7c4a12c9a804ac0 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_xxhash32, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_xxhash64 arginfo_xxhash32

#define arginfo_xxhash3_64bits arginfo_xxhash32

#define arginfo_xxhash3_128bits arginfo_xxhash32


ZEND_FUNCTION(xxhash32);
ZEND_FUNCTION(xxhash64);
ZEND_FUNCTION(xxhash3_64bits);
ZEND_FUNCTION(xxhash3_128bits);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(xxhash32, arginfo_xxhash32)
	ZEND_FE(xxhash64, arginfo_xxhash64)
	ZEND_FE(xxhash3_64bits, arginfo_xxhash3_64bits)
	ZEND_FE(xxhash3_128bits, arginfo_xxhash3_128bits)
	ZEND_FE_END
};
