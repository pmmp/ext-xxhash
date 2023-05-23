/* xxhash extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_xxhash.h"
#include "xxhash_arginfo.h"
#include "Zend/zend_long.h"

#include "xxhash.h"

#ifndef ZEND_ENABLE_ZVAL_LONG64
# error "ext-xxhash requires a 64-bit build of PHP"
#endif

#define ACCEPT_STRING_INPUT() \


#define STRING_HASH_FUNC(name, hashFunc, result_size) \
PHP_FUNCTION(name) { \
	zend_string *input; \
	\
	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1) \
		Z_PARAM_STR(input) \
	ZEND_PARSE_PARAMETERS_END(); \
	\
	XXH##result_size##_hash_t hash = hashFunc(ZSTR_VAL(input), ZSTR_LEN(input), 0); \
	XXH##result_size##_canonical_t canonicalHash; \
	XXH##result_size##_canonicalFromHash(&canonicalHash, hash); \
	\
	RETURN_STRINGL((const char *) &canonicalHash.digest, sizeof(canonicalHash.digest)); \
}

STRING_HASH_FUNC(xxhash32, XXH32, 32);
STRING_HASH_FUNC(xxhash64, XXH64, 64);
STRING_HASH_FUNC(xxhash3_64bits, XXH3_64bits_withSeed, 64);
STRING_HASH_FUNC(xxhash3_128bits, XXH3_128bits_withSeed, 128);

#define INT_HASH_FUNC(name, hashFunc) \
PHP_FUNCTION(name) { \
	zend_long input; \
	\
	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1) \
		Z_PARAM_LONG(input) \
	ZEND_PARSE_PARAMETERS_END(); \
	\
	RETURN_LONG(hashFunc(&input, sizeof(input), 0)); \
}

INT_HASH_FUNC(xxhash32_int, XXH32);
INT_HASH_FUNC(xxhash64_int, XXH64);
INT_HASH_FUNC(xxhash3_64bits_int, XXH3_64bits_withSeed);

PHP_MINFO_FUNCTION(xxhash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xxhash support", "enabled");

	char xxhash_library_version[16];
	snprintf(xxhash_library_version, sizeof(xxhash_library_version), "%d.%d.%d", XXH_VERSION_MAJOR, XXH_VERSION_MINOR, XXH_VERSION_RELEASE);
	php_info_print_table_row(2, "xxhash library version", xxhash_library_version);
	php_info_print_table_end();
}

/* {{{ xxhash_module_entry */
zend_module_entry xxhash_module_entry = {
	STANDARD_MODULE_HEADER,
	"xxhash",
	ext_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(xxhash),
	PHP_XXHASH_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_XXHASH
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(xxhash)
#endif
