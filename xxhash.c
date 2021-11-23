/* xxhash extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_xxhash.h"
#include "xxhash_arginfo.h"

#include "xxhash.h"

PHP_FUNCTION(xxhash32) {
	zend_string *input;

	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();

	XXH32_hash_t hash = XXH32(ZSTR_VAL(input), ZSTR_LEN(input), 0);
	XXH32_canonical_t canonicalHash;
	XXH32_canonicalFromHash(&canonicalHash, hash);

	RETURN_STRINGL((const char *) &canonicalHash.digest, sizeof(canonicalHash.digest));
}

PHP_FUNCTION(xxhash64) {
	zend_string *input;

	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();

	XXH64_hash_t hash = XXH64(ZSTR_VAL(input), ZSTR_LEN(input), 0);
	XXH64_canonical_t canonicalHash;
	XXH64_canonicalFromHash(&canonicalHash, hash);

	RETURN_STRINGL((const char *) &canonicalHash.digest, sizeof(canonicalHash.digest));
}

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
