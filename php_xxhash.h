/* xxhash extension for PHP */

#ifndef PHP_XXHASH_H
# define PHP_XXHASH_H

extern zend_module_entry xxhash_module_entry;
# define phpext_xxhash_ptr &xxhash_module_entry

# define PHP_XXHASH_VERSION "0.2.1-dev"

# if defined(ZTS) && defined(COMPILE_DL_XXHASH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_XXHASH_H */
