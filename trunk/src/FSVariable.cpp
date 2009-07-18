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

// main header
#include <Core/FridgeScript.h>

// this file's header
#include "FSVariable.h"

#include <string.h>

FSVariable::FSVariable(const char* const& id)
{
    unsigned long long ullQNaN = 0xFFFFFFFFFFFFFFFF;
    _auto = *reinterpret_cast<double*>( &ullQNaN );

    unsigned int i = strlen( id ) + 1;
    name = new char[i];
    while( i > 0 )
    {
        --i;
        name[i] = id[i];
    }
}

FSVariable::~FSVariable()
{
    delete[] name;
}