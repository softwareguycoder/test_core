// test_core.h - Contains definitions for symbols exposed by this library
//

#ifndef __TEST_CORE_H__
#define __TEST_CORE_H__

// To expose the Assert* functions
#include "assert_api.h"

/**
 * @name LPTEST_ROUTINE
 * @brief Function signature for a unit test routine.
 * @remarks Unit test routines should return nothing and take no arguments.
 */
typedef void (*LPTEST_ROUTINE)(void);

#endif //__TEST_CORE_H__
