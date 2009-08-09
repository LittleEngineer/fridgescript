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
// F R I D G E S C R I P T    M A I N    H E A D E R
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __FS_FRIDGESCRIPT_H_
#define __FS_FRIDGESCRIPT_H_

/////////////////////////////////////////////////////////////////////////////////////////////
// D E F I N E S
/////////////////////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
#define FRIDGE_API __stdcall
#else
#define FRIDGE_API define_me_for_other_platforms_please_line_32_FridgeScript_h
#endif

#ifndef NULL
#define NULL (0)
#endif

/////////////////////////////////////////////////////////////////////////////////////////////
// T Y P E D E F S
/////////////////////////////////////////////////////////////////////////////////////////////

typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned char u_char;

/////////////////////////////////////////////////////////////////////////////////////////////
// I N C L U D E S
/////////////////////////////////////////////////////////////////////////////////////////////

// core includes
#include <Core/FSAssert.h>
#include <Core/SimpleStructures.h>

#endif