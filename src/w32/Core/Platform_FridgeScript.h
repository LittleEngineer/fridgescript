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

#ifndef __FS_PLATFORM_FRIDGESCRIPT_H_
#define __FS_PLATFORM_FRIDGESCRIPT_H_

#define _export extern "C" unsigned int __declspec(dllexport) __stdcall
#define _exportptr extern "C" float __declspec(dllexport)* __stdcall
#define _exportval extern "C" float __declspec(dllexport) __stdcall

#endif