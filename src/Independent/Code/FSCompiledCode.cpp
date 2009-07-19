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

#include <Code/FSCompiledCode.h>
#include <Variable/FSVariable.h>

void FSCompiledCode::operator ()()
{
    FSAssert( bytes != 0, "Trying to execute code before it has been compiled!" );
    
    // need to set up the stack etc...
    // this is a really crappy solution
    static double crap[4096];
    double* p = &(crap[0]);
    unsigned int i;
    void(__stdcall *f)() = reinterpret_cast<void(__stdcall *)()>(bytes);

    for(i = 0; i < vars.GetCount(); ++i)
    {
        crap[i] = vars[i]->_auto;
    }

    __asm
    {
        mov eax, p
        mov ecx, i
lbl1:
        // copy stuff
        push dword ptr [eax+4]
        push dword ptr [eax]
        add eax, 8
        loop lbl1

        // store the pointer ready for copy back
        mov p, eax
        // load function address
        mov eax, f

        // setup stack frame and execute code
        push ebp
        mov ebp, esp
        add ebp, 4
        call eax                        // reinterpret_cast<void(__stdcall *)()>(bytes)();
        pop ebp
        
        // load pointer, counter
        mov eax, p
        mov ecx, i
lbl2:
        // copy stuff
        sub eax, 8
        pop dword ptr [eax]
        pop dword ptr [eax+4]
        loop lbl2
    }

    for(i = 0; i < vars.GetCount(); ++i)
    {
        vars[i]->_auto = crap[i];
    }
}

void FSCompiledCode::SetupVariableStack(Simple::Stack<FSVariable*>* v)
{
    for(unsigned int i = 0; i < v->GetCount(); ++i)
    {
        vars.Push((*v)[i]);
    }
}

void FSCompiledCode::SetupConstantStack(Simple::Stack<double>* v)
{
    for(unsigned int i = 0; i < v->GetCount(); ++i)
    {
        consts.Push((*v)[i]);
    }
}