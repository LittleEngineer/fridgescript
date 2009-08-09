/*
    This file is part of FridgeScript.

    FridgeScript is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FridgeScript is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FridgeScript.  If not, see <http://www.gnu.org/licenses/>
*/

/////////////////////////////////////////////////////////////////////////////////////////////
// A S S E R T
/////////////////////////////////////////////////////////////////////////////////////////////
// Implementation of Assert
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
// I N C L U D E S
/////////////////////////////////////////////////////////////////////////////////////////////

// This file's header
#include <Core/FSAssert.h>

// C/C++ headers
#include <stdarg.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////
// I M P L E M E N T A T I O N
/////////////////////////////////////////////////////////////////////////////////////////////
// Note: this uses that horrible va_list business
/////////////////////////////////////////////////////////////////////////////////////////////

static char sAssertTitle[ASSERT_MAX_TITLE_LENGTH];
static char sAssertMessage[ASSERT_MAX_MESSAGE_LENGTH];

/////////////////////////////////////////////////////////////////////////////////////////////
// _FSAssert : returns whether to trigger a breakpoint or not
/////////////////////////////////////////////////////////////////////////////////////////////

bool _FSAssert(const bool& bCondition, const char* sFileName, const int& uLineNumber, const char* sFormatString, ...)
{
#ifdef _DEBUG
    if( !bCondition )
    {
        int iTitleLength = _scprintf( "Assertion failed in file \"%S\" line %d", sFileName, uLineNumber ) + 1;
        
        va_list xArgumentList;

	    va_start( xArgumentList, sFormatString );
        int iMessageLength = _vscprintf( sFormatString, xArgumentList ) + 1;

        // clean up xArgument list so that other variable parameter functions can work
        va_end( xArgumentList );

        // recursion why not
        FSAssert( iTitleLength < ASSERT_MAX_TITLE_LENGTH, "Assert dialog title char* is too long, increase ASSERT_MAX_TITLE_LENGTH in \"Core\\Assert.h\", the current value is %d but this call requested %d.", ASSERT_MAX_TITLE_LENGTH, iTitleLength );
        FSAssert( iMessageLength < ASSERT_MAX_MESSAGE_LENGTH, "Assert message char* too long, increase ASSERT_MAX_MESSAGE_LENGTH in \"Core\\Assert.h\", the current value is %d but this call requested %d.", ASSERT_MAX_MESSAGE_LENGTH, iMessageLength );

        sprintf( sAssertTitle, /* iTitleLength, */ "Assertion failed in file \"%s\" line %d", sFileName, uLineNumber );
        
        // reinitialise variable argument list because swprintf uses one
	    va_start( xArgumentList, sFormatString );

        vsprintf( sAssertMessage, /* iMessageLength, */ sFormatString, xArgumentList );

        // we no longer need xArgumentList
        va_end( xArgumentList );

        // output to console and offer the user a choice to break or not
        printf("%s : %s\r\nbreak? (y/n) : ", sAssertTitle, sAssertMessage );
        char cChoice = 0;
        scanf( "%c", &cChoice );
        
        if(cChoice == 'y') return true;
    }
#endif

    // assertion was satisfied, so don't break
    return false;
}