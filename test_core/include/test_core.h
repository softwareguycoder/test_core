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

/**
 * @name DecrementTestFailureCount
 * @brief Decrements the count of failed tests.
 */
void DecrementTestFailureCount();

/**
 * @name GetTestFailureCount
 * @brief Gets the count of failed unit tests for this session.
 * @return Count of failed unit tests.
 */
int GetTestFailureCount();

/**
 * @name IncrementTestFailureCount
 * @brief Increments the count of failed tests.
 */
void IncrementTestFailureCount();

#endif //__TEST_CORE_H__
