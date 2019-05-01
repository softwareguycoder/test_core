// test_exceptions.c - Implementations for test-failure exception functions
//

#include "stdafx.h"
#include "test_core.h"

#include "test_exceptions.h"

//////////////////////////////////////////////////////////////////////////////
// Internally-exposed functions

///////////////////////////////////////////////////////////////////////////////
// ThrowTestFailedException function

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
}

//////////////////////////////////////////////////////////////////////////////

