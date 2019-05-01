// assert_api.h - Definitions of the Assert* functions that make up a testing
// api
//

#ifndef __ASSERT_API_H__
#define __ASSERT_API_H__

/**
 * @name AssertIsFalse
 * @brief Tests whether a Boolean expression evaluates to FALSE.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the expression
 * evaluates to TRUE.
 * @param bExpression Boolean expression to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsFalse(const char* pszTestName,
    const char* pszMessage, BOOL bExpression);

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

/**
 * @name AssertIsNullOrWhiteSpace
 * @brief Tests whether the pszValue string is blank, and displays a message
 * and fails the unit test if it is not.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the value is not blank.
 * @param pszValue Value to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsNullOrWhiteSpace(const char* pszTestName,
    const char* pszMessage, const char* pszValue);

/**
 * @name AssertIsTrue
 * @brief Tests whether a Boolean expression evaluates to TRUE.
 * @param pszTestName Name of the unit test routine.
 * @param pszMessage Name of the message to display if the expression
 * evaluates to FALSE.
 * @param bExpression Boolean expression to test.
 * @returns TRUE if the test ran by the assert passed; FALSE if the data
 * passed to the assert failed to meet the criteria
 */
BOOL AssertIsTrue(const char* pszTestName,
    const char* pszMessage, BOOL bExpression);

#endif //__ASSERT_API_H__
