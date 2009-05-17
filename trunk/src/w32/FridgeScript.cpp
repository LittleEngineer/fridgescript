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

#include "FSContext.h"
#include "FSParseTree.h"
#include "FSVariable.h"

#include <string.h>

#define _export extern "C" unsigned int __declspec(dllexport) __stdcall
#define _exportptr extern "C" double __declspec(dllexport)* __stdcall
#define _exportval extern "C" double __declspec(dllexport) __stdcall

const unsigned int ptrMash = 0xABCD1234;
const unsigned int codeMash = 0x1234ABCD;
const unsigned int varMash = 0x1A2B3C4D;

///////////////////////////////////////////////
// D L L    I N T E R F A C E
///////////////////////////////////////////////

///////////////////////////////////////////////
// FSCreateContext : Allocates everything and
//                   provides the user with a
//                   context to compile with
///////////////////////////////////////////////

_export FSCreateContext()
{
    return reinterpret_cast<unsigned int>(new FSContext()) ^ ptrMash;
}

///////////////////////////////////////////////
// FSDestroyContext : Cleans up a context
///////////////////////////////////////////////

_export FSDestroyContext(unsigned int context)
{
    delete reinterpret_cast<FSContext*>(context ^ ptrMash);
    return 0;
}

///////////////////////////////////////////////
// FSGetVariableHandle : Converts a string to
//                       a handle to be used
//                       for variable accesses
///////////////////////////////////////////////

_export FSGetVariableHandle(unsigned int context, unsigned int codeHandle, char* name)
{
    Simple::Stack<FSVariable*>* p = reinterpret_cast<FSContext*>(context ^ ptrMash)->GetVariables(codeHandle ^ codeMash);
    for(unsigned int i = 0; i < p->GetCount(); ++i)
    {
        if(!strcmp((*p)[i]->name, name)) return reinterpret_cast<unsigned int>((*p)[i]) ^ varMash;
    }

    return 0;
}

///////////////////////////////////////////////
// FSGetVariableValue : Get value from handle
///////////////////////////////////////////////

_exportval FSGetVariableValue(unsigned int varHandle)
{
    FSVariable* p = reinterpret_cast<FSVariable*>(varHandle ^ varMash);
    return p->_auto;
}

///////////////////////////////////////////////
// FSSetVariableValue : Set value from handle
///////////////////////////////////////////////

_exportval FSSetVariableValue(unsigned int varHandle, double value)
{
    FSVariable* p = reinterpret_cast<FSVariable*>(varHandle ^ varMash);
    return (p->_auto = value);
}

///////////////////////////////////////////////
// FSCompile : Compiles code from ANSI string
//             returning a handle that can be
//             used to execute it later
///////////////////////////////////////////////

_export FSCompile(unsigned int context, char* code)
{
    FSContext* pContext = reinterpret_cast<FSContext*>(context ^ ptrMash);
    unsigned int ret = pContext->CompileCode(code);
    return (ret) ? ret ^ codeMash : 0;
}

///////////////////////////////////////////////
// FSExecute : Executes code from the handle
//             provided by FSCompile
///////////////////////////////////////////////

_export FSExecute(unsigned int context, unsigned int codeHandle)
{
    FSContext* pContext = reinterpret_cast<FSContext*>(context ^ ptrMash);

    pContext->ExecuteCode(codeHandle ^ codeMash);

    return 0; 
}