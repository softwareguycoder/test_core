// assert_api.c - Implementations of functions that perform assertions, i.e.,
// condition must be true otherwise test fails.
//

#include "stdafx.h"
#include "test_core.h"

#include "assert_api.h"
#include "test_exceptions.h"

//////////////////////////////////////////////////////////////////////////////
// Internal functions

//////////////////////////////////////////////////////////////////////////////
// Publicly-exposed library functions

//////////////////////////////////////////////////////////////////////////////
// AssertIsNotNull function

BOOL AssertIsNotNull(const char* pszTestName,
        const char* pszMessage, void* pvValue) {
  if (pvValue == NULL) {
    ThrowTestFailedException(pszTestName, pszMessage);
    return FALSE;
  }

  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// AssertIsNotNullOrWhiteSpace function

BOOL AssertIsNotNullOrWhiteSpace(const char* pszTestName,
        const char* pszMessage, const char* pszValue) {
  if (IsNullOrWhiteSpace(pszValue)) {
    ThrowTestFailedException(pszTestName, pszMessage);
    return FALSE;
  }

  return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
