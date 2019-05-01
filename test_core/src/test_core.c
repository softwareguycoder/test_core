// test_core.c - Implementations of functions and symbols exposed by this
// library.

#include "stdafx.h"
#include "test_core.h"

///////////////////////////////////////////////////////////////////////////////
//

void PrintFunctionName(const char* pszFunctionName) {
	if (IsNullOrWhiteSpace(pszFunctionName)) {
		return;
	}

	fprintf(stdout, "%s\n", pszFunctionName);
}

///////////////////////////////////////////////////////////////////////////////
