/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5d00c9b994f78f6a15f0324ce01969b28323ffb2 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_xxhash32, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_xxhash64 arginfo_xxhash32


ZEND_FUNCTION(xxhash32);
ZEND_FUNCTION(xxhash64);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(xxhash32, arginfo_xxhash32)
	ZEND_FE(xxhash64, arginfo_xxhash64)
	ZEND_FE_END
};
