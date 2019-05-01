// test_core.h - Contains definitions for symbols exposed by this library
//

#ifndef __TEST_CORE_H__
#define __TEST_CORE_H__

// To expose the Assert* functions
#include "assert_api.h"

// To expose the StartUnitTestSession and EndUnitTestSession functions
#include "test_sessions.h"

/**
 * @name LPTEST_ROUTINE
 * @brief Function signature for a unit test routine.
 * @returns TRUE if the unit test passed; FALSE otherwise
 * @remarks Unit test routines should return nothing and take no arguments.
 */
typedef BOOL (*LPTEST_ROUTINE)(void);

/**
 * @name ExecuteTest
 * @brief Executes the unit test specified.
 * @param lpSession Reference to the specific test session that this test
 * is running as a part of. Required.
 * @param pszTestName String containing a name/description of the unit test.
 * @param lpfnTest Address of a function having a signature matching that
 * of LPTEST_ROUTINE that is called to execute the unit test.
 */
void ExecuteTest(LPTESTSESSION lpSession,
        const char* pszTestName, LPTEST_ROUTINE lpfnTest);

#endif //__TEST_CORE_H__
