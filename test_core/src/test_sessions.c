// test_sessions.c - Implementations of functions responsible for organizing
// the use of unit tests
//

#include "stdafx.h"
#include "test_core.h"

#include "test_sessions.h"
#include "test_core_symbols.h"

//////////////////////////////////////////////////////////////////////////////
// Internally-used functions

//////////////////////////////////////////////////////////////////////////////
// GetNewTestSessionGUID function

/**
 * @name GetNewTestSessionGUID
 * @brief Generates a new UUID to be associated with a unit test session.
 * @param pNewUUID Address of a uuid_t variable that will receive the newly-
 * generated universally-unique identifier (UUID) value.
 */
void GetNewTestSessionGUID(uuid_t* pNewUUID) {
  if (pNewUUID == NULL) {
    return;
  }

  uuid_generate_random(*pNewUUID);
}

/**
 * @name GUIDToString
 * @brief Transforms a uuid_t value to a string representation of the GUID.
 * @param pszBuffer Buffer that will be filled with the string. Must be 37
 * bytes in size.
 * @param pGUID The UUID value to represent as a string.
 *
 */
void GUIDToString(char* pszBuffer, uuid_t* pGUID) {
  if (pszBuffer == NULL) {
    return; // Required parameter
  }
  if (pGUID == NULL) {
    return; // Required parameter
  }

  if (uuid_is_null(*pGUID)) {
    return; // uuid_t must contain a valid UUID
  }

  uuid_unparse(*pGUID, pszBuffer);
}

//////////////////////////////////////////////////////////////////////////////
// CreateTestSession function

/**
 * @name CreateTestSession
 * @brief Creates and initializes a new TESTSESSSION structure instance.
 * This structure serves as a handle that identifies the specific unit test
 * session that is now running.
 * @param lpfnSetUp (Optional.) Address of a function that is to serve as a
 * set up routine for the unit test session.  May be NULL.
 * @param lpfnTearDown (Optional.) Address of a function that is to serve as
 * a tear down routine for the unit test session.  May be NULL.
 */
LPTESTSESSION CreateTestSession(LPSETUP_ROUTINE lpfnSetUp,
    LPTEARDOWN_ROUTINE lpfnTearDown) {
  LPTESTSESSION lpResult = (LPTESTSESSION) malloc(sizeof(TESTSESSION));
  if (lpResult == NULL) {
    fprintf(stderr, "Failed to allocate new unit test session handle.\n");
    exit(EXIT_FAILURE);
  }

  memset(lpResult, 0, sizeof(TESTSESSION));

  lpResult->pTestSessionID = (uuid_t*) malloc(sizeof(uuid_t));
  if (lpResult->pTestSessionID == NULL) {
    fprintf(stderr, "Failed to allocate storage for new unit test ID.\n");
    exit(EXIT_FAILURE);
  }

  memset(lpResult->pTestSessionID, 0, sizeof(uuid_t));

  GetNewTestSessionGUID(lpResult->pTestSessionID);

  lpResult->lpfnSetUp = lpfnSetUp;
  lpResult->lpfnTearDown = lpfnTearDown;

  lpResult->nPassed = 0;
  lpResult->nFailed = 0;

  /* If an address for one is provided, call the SetUp function specified
   * by the caller for this session  */
  if (lpResult->lpfnSetUp != NULL) {
    lpResult->lpfnSetUp();
  }

  return lpResult;
}

/**
 * @name DestroyUnitTestSession
 * @brief Deallocates the unit test session.  Frees operating system resources
 * consumed by the session handle.
 * @param lpSession Address of a TESTSESSION structure instance that serves
 * as the test session handle.
 */
void DestroyUnitTestSession(LPPTESTSESSION lppSession) {
  if (lppSession == NULL || *lppSession == NULL) {
    return; // Required parameter
  }

  FreeBuffer((void**) &((*lppSession)->pTestSessionID));

  memset((*lppSession), 0, sizeof(TESTSESSION));

  FreeBuffer((void**)lppSession);
}

//////////////////////////////////////////////////////////////////////////////
// IsGUIDValid function

BOOL IsGUIDValid(uuid_t* pGUID) {
  return pGUID != NULL && !uuid_is_null((*pGUID));
}

//////////////////////////////////////////////////////////////////////////////
// Publicly-exposed functions

//////////////////////////////////////////////////////////////////////////////
// StartUnitTestSession function

void StartUnitTestSession(LPSETUP_ROUTINE lpfnSetUp,
    LPTEARDOWN_ROUTINE lpfnTearDown, LPPTESTSESSION lppTestSession) {
  if (lppTestSession == NULL) {
    return; // Required parameter
  }

  char szSessionGUID[GUID_BUFFER_SIZE];
  memset(szSessionGUID, 0, GUID_BUFFER_SIZE);

  LPTESTSESSION lpSession = NULL;
  lpSession = CreateTestSession(lpfnSetUp, lpfnTearDown);
  if (lpSession == NULL) {
    fprintf(stderr, "Failed to start new unit test session.\n");
    exit(EXIT_FAILURE);
  }

  if (!IsGUIDValid(lpSession->pTestSessionID)) {
    return; //Required value
  }

  GUIDToString(szSessionGUID, lpSession->pTestSessionID);

  fprintf(stdout, "*** STARTED UNIT TEST SESSION {%s} ***\n\n",
      szSessionGUID);

  *lppTestSession = lpSession;
}

//////////////////////////////////////////////////////////////////////////////
// EndUnitTestSession function

void EndUnitTestSession(LPPTESTSESSION lppSession) {
  if (lppSession == NULL || *lppSession == NULL) {
    return; // Required parameter
  }

  if (!IsGUIDValid((*lppSession)->pTestSessionID)) {
    return; //Required value
  }

  char szSessionGUID[GUID_BUFFER_SIZE];
  memset(szSessionGUID, 0, GUID_BUFFER_SIZE);

  GUIDToString(szSessionGUID, (*lppSession)->pTestSessionID);

  fprintf(stdout, "\n %d test(s) passed, %d test(s) failed.\n",
      (*lppSession)->nPassed, (*lppSession)->nFailed);

  fprintf(stdout, "\n*** ENDING UNIT TEST SESSION {%s} ***\n",
      szSessionGUID);

  if ((*lppSession)->lpfnTearDown != NULL) {
    (*lppSession)->lpfnTearDown();
  }

  DestroyUnitTestSession(lppSession);
}

//////////////////////////////////////////////////////////////////////////////
