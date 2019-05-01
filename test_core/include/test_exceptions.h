// test_exceptions.h - Defines the interface for test-failure exception
// handling
//

#ifndef __TEST_EXCEPTIONS_H__
#define __TEST_EXCEPTIONS_H__

/**
 * @name ThrowTestFailedException
 * @brief Prints a message to STDERR that a unit test failed and
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Message to display on failure.
 */
void ThrowTestFailedException(const char* pszTestName,
        const char* pszMessage);

#endif //__TEST_EXCEPTIONS_H__
