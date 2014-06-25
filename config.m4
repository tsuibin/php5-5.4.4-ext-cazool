dnl $Id$
dnl config.m4 for extension cazool

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(cazool, for cazool support,
dnl Make sure that the comment is aligned:
dnl [  --with-cazool             Include cazool support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(cazool, whether to enable cazool support,
Make sure that the comment is aligned:
[  --enable-cazool           Enable cazool support])

if test "$PHP_CAZOOL" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-cazool -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/cazool.h"  # you most likely want to change this
  dnl if test -r $PHP_CAZOOL/$SEARCH_FOR; then # path given as parameter
  dnl   CAZOOL_DIR=$PHP_CAZOOL
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for cazool files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CAZOOL_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CAZOOL_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the cazool distribution])
  dnl fi

  dnl # --with-cazool -> add include path
  dnl PHP_ADD_INCLUDE($CAZOOL_DIR/include)

  dnl # --with-cazool -> check for lib and symbol presence
  dnl LIBNAME=cazool # you may want to change this
  dnl LIBSYMBOL=cazool # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CAZOOL_DIR/lib, CAZOOL_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CAZOOLLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong cazool lib version or lib not found])
  dnl ],[
  dnl   -L$CAZOOL_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CAZOOL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(cazool, cazool.c, $ext_shared)
fi
