// test_core.c - Implementations of functions and symbols exposed by this
// library.

#include "stdafx.h"
#include "test_core.h"

///////////////////////////////////////////////////////////////////////////////
// Global variables

/**
 * @name g_nTestFailureCount
 * @brief Global count of failed tests.
 */
int g_nTestFailureCount = 0;

///////////////////////////////////////////////////////////////////////////////
// Internal functions only

///////////////////////////////////////////////////////////////////////////////
// ThrowTestFailedException function

/**
 * @name ThrowTestFailedException
 * @brief Prints a message to STDERR that a unit test failed and
 * @param pszTestName
 * @param pszMessage
 */
void ThrowTestFailedException(const char* pszTestName,
        const char* pszMessage) {
  if (IsNullOrWhiteSpace(pszTestName)) {
    return;
  }

  if (IsNullOrWhiteSpace(pszMessage)) {
    return;
  }

  /* Remove whitespace and/or newlines from beginning, end of message */
  char szTrimmedMessage[strlen(pszMessage)];
  memset(szTrimmedMessage, 0, strlen(pszMessage));
  Trim(szTrimmedMessage, strlen(pszMessage), pszMessage);

  fprintf(stderr, "%s FAILED: %s\n", pszTestName, szTrimmedMessage);
  g_nTestFailureCount++;
}

//////////////////////////////////////////////////////////////////////////////
// Publicly-exposed functions

//////////////////////////////////////////////////////////////////////////////
// DecrementTestFailureCount function

void DecrementTestFailureCount() {
  if (GetTestFailureCount() == 0) {
    return; // test failure count is zero or positive
  }

  g_nTestFailureCount--;
}

//////////////////////////////////////////////////////////////////////////////
// GetTestFailureCount function

int GetTestFailureCount() {
  return g_nTestFailureCount;
}

//////////////////////////////////////////////////////////////////////////////
// IncrementTestFailureCount function

void IncrementTestFailureCount() {
  g_nTestFailureCount++;
}

///////////////////////////////////////////////////////////////////////////////
