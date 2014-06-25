/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_CAZOOL_H
#define PHP_CAZOOL_H

extern zend_module_entry cazool_module_entry;
#define phpext_cazool_ptr &cazool_module_entry

#ifdef PHP_WIN32
#	define PHP_CAZOOL_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_CAZOOL_API __attribute__ ((visibility("default")))
#else
#	define PHP_CAZOOL_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(cazool);
PHP_MSHUTDOWN_FUNCTION(cazool);
PHP_RINIT_FUNCTION(cazool);
PHP_RSHUTDOWN_FUNCTION(cazool);
PHP_MINFO_FUNCTION(cazool);

PHP_FUNCTION(confirm_cazool_compiled);	/* For testing, remove later. */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(cazool)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(cazool)
*/

/* In every utility function you add that needs to use variables 
   in php_cazool_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as CAZOOL_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define CAZOOL_G(v) TSRMG(cazool_globals_id, zend_cazool_globals *, v)
#else
#define CAZOOL_G(v) (cazool_globals.v)
#endif

#endif	/* PHP_CAZOOL_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
