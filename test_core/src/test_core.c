// test_core.c - Implementations of functions and symbols exposed by this
// library.

#include "stdafx.h"
#include "test_core.h"

///////////////////////////////////////////////////////////////////////////////
// Internal functions only

/**
 * @name PrintFunctionName
 * @brief Prints the name of a function to the console.
 * @param pszFunctionName Text containing the string to be printed.
 * @remarks This function does nothing if the pszFunctionName string is blank.
 */
void PrintFunctionName(const char* pszFunctionName) {
	if (IsNullOrWhiteSpace(pszFunctionName)) {
		return;
	}

	fprintf(stdout, "%s\n", pszFunctionName);
}

///////////////////////////////////////////////////////////////////////////////
