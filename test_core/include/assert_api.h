// assert_api.h - Definitions of the Assert* functions that make up a testing
// api
//

#ifndef __ASSERT_API_H__
#define __ASSERT_API_H__

/**
 * @name AssertIsNull
 * @brief Tests whether the pointer pvValue is NULL and displays a message
 * and fails the unit test if it is not.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the value is blank.
 * @param pvValue Value to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsNull(const char* pszTestName,
    const char* pszMessage, void* pvValue);

/**
 * @name AssertIsNotNull
 * @brief Tests whether the pointer pvValue is NULL and displays a message
 * and fails the unit test if it is.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the value is blank.
 * @param pvValue Value to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsNotNull(const char* pszTestName,
        const char* pszMessage, void* pvValue);

/**
 * @name AssertIsNotNullOrWhiteSpace
 * @brief Tests whether the pszValue string is blank, and displays a message
 * and fails the unit test if it is.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the value is blank.
 * @param pszValue Value to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsNotNullOrWhiteSpace(const char* pszTestName,
		const char* pszMessage, const char* pszValue);

#endif //__ASSERT_API_H__
