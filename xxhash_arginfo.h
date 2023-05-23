/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: ffa17f70b684af1f1300a498f8ad7dcc668d4bb9 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_xxhash32, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_xxhash64 arginfo_xxhash32

#define arginfo_xxhash3_64bits arginfo_xxhash32

#define arginfo_xxhash3_128bits arginfo_xxhash32

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_xxhash32_int, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_xxhash64_int arginfo_xxhash32_int

#define arginfo_xxhash3_64bits_int arginfo_xxhash32_int


ZEND_FUNCTION(xxhash32);
ZEND_FUNCTION(xxhash64);
ZEND_FUNCTION(xxhash3_64bits);
ZEND_FUNCTION(xxhash3_128bits);
ZEND_FUNCTION(xxhash32_int);
ZEND_FUNCTION(xxhash64_int);
ZEND_FUNCTION(xxhash3_64bits_int);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(xxhash32, arginfo_xxhash32)
	ZEND_FE(xxhash64, arginfo_xxhash64)
	ZEND_FE(xxhash3_64bits, arginfo_xxhash3_64bits)
	ZEND_FE(xxhash3_128bits, arginfo_xxhash3_128bits)
	ZEND_FE(xxhash32_int, arginfo_xxhash32_int)
	ZEND_FE(xxhash64_int, arginfo_xxhash64_int)
	ZEND_FE(xxhash3_64bits_int, arginfo_xxhash3_64bits_int)
	ZEND_FE_END
};
