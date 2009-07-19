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

#include <Core/FridgeScript.h>

#include <Core/FSContext.h>

#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "Absyn.h"
#include "Parser.H"

#include <Core/BadPtr.h>
#include <Core/FSAssembler.h>
#include <Code/FSCompiledCode.h>
#include <ParseTree/FSParseTree.h>
#include <Variable/FSVariable.h>
#include <Variable/FSVariablePicker.h>
#include <Core/SimpleStructures.h>

FSContext::~FSContext()
{
    for(unsigned int i = 0; i < numCode; ++i)
    {
	    delete code[i];
        code[i] = BadPtr<FSCompiledCode>();
    }
    free(code);
    code = BadPtr<FSCompiledCode*>();
}

unsigned int FSContext::CompileCode(const char* const& source)
{
    FILE* pTmpFile = tmpfile();

    fwrite(source, 1, strlen(source), pTmpFile);

    rewind(pTmpFile);

    Program* tree = pProgram(pTmpFile);
    if(!tree)
    {
        // error!
        fclose(pTmpFile);
        return 0;
    }

    // process the tree
    FSParseTree parseTree = FSParseTree(this);
    tree->accept(&parseTree);

    fclose(pTmpFile);

    // send the resulting string to an assembler
    const char* const foo = parseTree.GetAssemblerString();
#ifdef _DEBUG
    printf("%s\r\n", foo);
#endif

    unsigned int length = 0;
    unsigned char* bytes = FSAssemble(parseTree.GetAssemblerString(), length);
    
    if(!bytes) return 0;

    ++numCode;
    code = static_cast<FSCompiledCode**>(realloc(code, sizeof(FSCompiledCode*)*numCode));
    code[numCode - 1] = new FSCompiledCode(bytes, length);

    code[numCode - 1]->SetupVariableStack(parseTree.GetVariableStackPointer());
    
    FSAFree(bytes);
    return numCode;
}

void FSContext::ExecuteCode(const unsigned int& id)
{
    // load variables and setup the stack
    (*code[id - 1])();
}

Simple::Stack<FSVariable*>* FSContext::GetVariables(const unsigned int& id)
{
    return code[id - 1]->GetVariables();
}

double* FSContext::GetConstant(const double& value)
{
    for(unsigned int i = 0; i < constants.GetCount(); ++i)
    {
        if(constants[i] == value) return &(constants[i]);
    }

    return constants.Push(value);
}