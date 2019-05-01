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
 * @name PrintFunctionName
 * @brief Prints the name of a function to the console.
 * @param pszFunctionName Text containing the string to be printed.
 * @remarks This function does nothing if the pszFunctionName string is blank.
 */
void PrintFunctionName(const char* pszFunctionName);

#endif //__TEST_CORE_H__
