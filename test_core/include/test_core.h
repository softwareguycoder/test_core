// test_core.h - Contains definitions for symbols exposed by this library
//

#ifndef __TEST_CORE_H__
#define __TEST_CORE_H__

// To expose the Assert* functions
#include "assert_api.h"

/**
 * @name LPTEST_ROUTINE
 * @brief Function signature for a unit test routine.
 * @returns TRUE if the unit test passed; FALSE otherwise
 * @remarks Unit test routines should return nothing and take no arguments.
 */
typedef BOOL (*LPTEST_ROUTINE)(void);

/**
 * @name GetTestFailureCount
 * @brief Gets the count of failed unit tests for this session.
 * @return Count of failed unit tests.
 */
int GetTestFailureCount();

#endif //__TEST_CORE_H__
