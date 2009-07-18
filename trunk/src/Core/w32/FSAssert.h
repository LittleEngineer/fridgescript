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

#ifndef __FS_ASSERT_H_
#define __FS_ASSERT_H_

/////////////////////////////////////////////////////////////////////////////////////////////
// D E F I N E S
/////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _DEBUG
    #define FSAssert(condition, message, ...) if( _FSAssert( condition, __FILE__, __LINE__, message, __VA_ARGS__ ) ) { __asm int 3 }
#else
    #define FSAssert(condition, ...) ;
#endif

#define ASSERT_MAX_TITLE_LENGTH          512
#define ASSERT_MAX_MESSAGE_LENGTH        512

/////////////////////////////////////////////////////////////////////////////////////////////
// D E C L A R A T I O N S
/////////////////////////////////////////////////////////////////////////////////////////////

bool _FSAssert(const bool& bCondition, const char* sFileName, const int& uLineNumber, const char* sFormatString, ...);

#endif