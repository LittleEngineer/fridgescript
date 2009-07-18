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
// E X E C U T A B L E    A L L O C
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __FS_PLATFORM_EXECUTABLEALLOC_H_
#define __FS_PLATFORM_EXECUTABLEALLOC_H_

unsigned char* Platform_FSExecutableAlloc( unsigned char* pcPointer, unsigned int uSize );
void Platform_FSExecutableFree( unsigned char* pcPointer, unsigned int uSize );

#endif