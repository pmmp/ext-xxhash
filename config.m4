PHP_ARG_ENABLE([xxhash],
  [whether to enable xxhash support],
  [AS_HELP_STRING([--enable-xxhash],
    [Enable xxhash support])],
  [no])

if test "$PHP_XXHASH" != "no"; then
  AC_DEFINE(HAVE_XXHASH, 1, [ Have xxhash support ])


  PHP_NEW_EXTENSION(xxhash, xxhash.c, $ext_shared)
  PHP_ADD_INLCUDE($ext_builddir/xxhash)
fi
