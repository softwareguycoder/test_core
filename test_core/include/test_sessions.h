// test_sessions.h - Defines the interface to a unit test session

#ifndef __TEST_SESSIONS_H__
#define __TEST_SESSIONS_H__

#include <uuid/uuid.h>

/**
 * @brief Callback signature for a routine that is called when a unit test
 * session is started.
 * @remarks Use this routine to supply a user-specified set up routine to
 * be executed at the start of a unit test session.
 */
typedef void (*LPSETUP_ROUTINE)(void);

/**
 * @brief Callback signature for a routine that is called when a unit test
 * session is ended.
 * @remarks Use this routine to supply a user-specified tear down rotuine to
 * be executed at the end of a unit test session.
 */
typedef void (*LPTEARDOWN_ROUTINE)(void);

/**
 * @name TESTSESSION
 * @brief Data structure to keep a handle on the current unit test session.
 */
typedef struct _tagTESTSESSION {
  uuid_t* pTestSessionID;
  LPSETUP_ROUTINE lpfnSetUp;
  LPTEARDOWN_ROUTINE lpfnTearDown;
  int nPassed;
  int nFailed;
} TESTSESSION, *LPTESTSESSION;

/**
 * @name StartUnitTestSession
 * @brief Starts a unit test session.  Optionally calls a set up routine.
 * @param lpfnSetUp (Optional.) Address of a function callback to be invoked
 * when the unit test session has been started. May be NULL.
 * @param lpfnTearDown (Optional.) Address of a function callback to be
 * invoked when the unit test session has been ended.  May be NULL.
 * @param lppTestSession Receives the address of a newly-allocated TESTSESSION
 * structure instance that serves as a handle to the session. This handle must
 * be provided to the EndUnitTestSession function.
 * @remarks A set up routine is utilized to allocate variables, structures,
 * or acquire resources from the OS that must be available to all unit tests
 * in the session.
 */
void StartUnitTestSession(LPSETUP_ROUTINE lpfnSetUp,
        LPTEARDOWN_ROUTINE lpfnTearDown, LPTESTSESSION* lppTestSession);

/**
 * @name EndUnitTestSession
 * @brief Ends a unit test session. Optionally calls a tear down routine.
 * @param lpSession Handle to the test session you want to end. Required.
 * @remarks Use of a tear down routine is needed when variables, structures,
 * and/or OS resources needed by all unit tests must be cleaned up and/or
 * released.
 */
void EndUnitTestSession(LPTESTSESSION lpSession);

#endif /* __TEST_SESSIONS_H__ */
