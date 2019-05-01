// test_sessions.c - Implementations of functions responsible for organizing
// the use of unit tests
//

#include "stdafx.h"
#include "test_core.h"

#include "test_sessions.h"

//////////////////////////////////////////////////////////////////////////////
// Publicly-exposed functions

//////////////////////////////////////////////////////////////////////////////
// StartUnitTestSession function

void StartUnitTestSession(LPSETUP_ROUTINE lpfnSetUp) {
  fprintf(stdout, "*** STARTING UNIT TEST SESSION ***\n");

  if (lpfnSetUp != NULL) {
    lpfnSetUp();
  }
}

//////////////////////////////////////////////////////////////////////////////
// EndUnitTestSession function

void EndUnitTestSession(LPTEARDOWN_ROUTINE lpfnTearDown) {
  fprintf(stdout, "*** ENDING UNIT TEST SESSION ***\n");

  if (lpfnTearDown != NULL) {
    lpfnTearDown();
  }
}

//////////////////////////////////////////////////////////////////////////////
