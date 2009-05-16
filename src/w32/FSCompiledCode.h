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

#ifndef __FSCompiledCode_h
#define __FSCompiledCode_h

#include <windows.h>

#include "SimpleStructures.h"

class FSVariable;

class FSCompiledCode
{
private:
    unsigned char*  bytes;
    unsigned int    length;

    Simple::Stack<FSVariable*> vars;
    Simple::Stack<double> consts;
public:
    FSCompiledCode(const unsigned char* const& source, const unsigned int& size) : vars(), consts()
    {
        bytes = static_cast<unsigned char*>(VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
        for(unsigned int i = 0; i < size; ++i) bytes[i] = source[i];
        length = size;
    }

    ~FSCompiledCode()
    {
        VirtualFree(bytes, length, MEM_RELEASE);
    }

    void operator ()();

    Simple::Stack<FSVariable*>* GetVariables() { return &vars; }
    Simple::Stack<double>* GetConstants() { return &consts; }
    void SetupVariableStack(Simple::Stack<FSVariable*>* v);
    void SetupConstantStack(Simple::Stack<double>* v);
};

#endif