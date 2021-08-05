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
	unsigned char result[4];

	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();

	XXH32_hash_t hash = XXH32(ZSTR_VAL(input), ZSTR_LEN(input), 0);
	result[0] = (unsigned char) ((hash >> 24) & 0xff);
	result[1] = (unsigned char) ((hash >> 16) & 0xff);
	result[2] = (unsigned char) ((hash >> 8) & 0xff);
	result[3] = (unsigned char) (hash & 0xff);

	RETURN_STRINGL((const char *) &result, sizeof(result));
}

PHP_FUNCTION(xxhash64) {
	zend_string *input;
	unsigned char result[8];

	ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();

	XXH64_hash_t hash = XXH64(ZSTR_VAL(input), ZSTR_LEN(input), 0);
	result[0] = (unsigned char) ((hash >> 56) & 0xff);
	result[1] = (unsigned char) ((hash >> 48) & 0xff);
	result[2] = (unsigned char) ((hash >> 40) & 0xff);
	result[3] = (unsigned char) ((hash >> 32) & 0xff);
	result[4] = (unsigned char) ((hash >> 24) & 0xff);
	result[5] = (unsigned char) ((hash >> 16) & 0xff);
	result[6] = (unsigned char) ((hash >> 8) & 0xff);
	result[7] = (unsigned char) (hash & 0xff);

	RETURN_STRINGL((const char *) &result, sizeof(result));
}

PHP_MINFO_FUNCTION(xxhash)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xxhash support", "enabled");
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
