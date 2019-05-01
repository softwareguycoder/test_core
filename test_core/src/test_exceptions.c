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
  const int MESSAGE_SIZE = strlen(pszMessage) + 1;
  char szTrimmedMessage[MESSAGE_SIZE];
  memset(szTrimmedMessage, 0, MESSAGE_SIZE);
  Trim(szTrimmedMessage, MESSAGE_SIZE, pszMessage);

  fprintf(stderr, "*** %s FAILED:\n\t%s\n", pszTestName, szTrimmedMessage);
}

//////////////////////////////////////////////////////////////////////////////

