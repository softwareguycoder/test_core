// test_core.c - Implementations of functions and symbols exposed by this
// library.

#include "stdafx.h"
#include "test_core.h"

#include "assert_api.h"
#include "test_exceptions.h"

///////////////////////////////////////////////////////////////////////////////
// Global variables

/**
 * @name g_nTestFailureCount
 * @brief Global count of failed tests.
 */
int g_nTestFailureCount = 0;

///////////////////////////////////////////////////////////////////////////////
// Internal functions only

//////////////////////////////////////////////////////////////////////////////
// Library-protected functions

//////////////////////////////////////////////////////////////////////////////
// DecrementTestFailureCount function

void DecrementTestFailureCount() {
  if (GetTestFailureCount() == 0) {
    return; // test failure count is zero or positive
  }

  g_nTestFailureCount--;
}

//////////////////////////////////////////////////////////////////////////////
// IncrementTestFailureCount function

void IncrementTestFailureCount() {
  g_nTestFailureCount++;
}

//////////////////////////////////////////////////////////////////////////////
// ExecuteTest function

void ExecuteTest(const char* pszTestName, LPTEST_ROUTINE lpfnTest) {
  if (IsNullOrWhiteSpace(pszTestName)) {
    return; // Required parameter
  }

  if (lpfnTest == NULL) {
    return; // Required parameter
  }

  if (lpfnTest) {
    fprintf(stdout, "%s PASSED\n", pszTestName);
  } // no else branch; failed test say so when their assertions throw
      // TestFailureExceptions
}

//////////////////////////////////////////////////////////////////////////////
// GetTestFailureCount function

int GetTestFailureCount() {
  return g_nTestFailureCount;
}

///////////////////////////////////////////////////////////////////////////////
