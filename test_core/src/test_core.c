// test_core.c - Implementations of functions and symbols exposed by this
// library.

#include "stdafx.h"
#include "test_core.h"

#include "assert_api.h"
#include "test_exceptions.h"

//////////////////////////////////////////////////////////////////////////////
// Publicly-exposed functions

//////////////////////////////////////////////////////////////////////////////
// ExecuteTest function

void ExecuteTest(LPTESTSESSION lpSession,
        const char* pszTestName, LPTEST_ROUTINE lpfnTest) {
  if (lpSession == NULL) {
    return; // Required parameter.
  }

  if (IsNullOrWhiteSpace(pszTestName)) {
    return; // Required parameter
  }

  if (lpfnTest == NULL) {
    return; // Required parameter
  }

  if (lpfnTest()) {
    fprintf(stdout, "%s PASSED\n", pszTestName);
    lpSession->nPassed++;
  } else {
    lpSession->nFailed++;
  }
}

///////////////////////////////////////////////////////////////////////////////
