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
    static float crap[4096];
    float* p = &(crap[0]);
    unsigned int i;
    void(__stdcall *f)() = reinterpret_cast<void(__stdcall *)()>(bytes);

    // set control word for 32-bit precision
    unsigned short usCW;
    __asm fstcw [usCW];
    usCW &= ~0x300; // clear bits 8 and 9
    __asm fldcw [usCW];

    for(i = 0; i < vars.GetCount(); ++i)
    {
        crap[i] = vars[i]->_auto;
    }

    __asm
    {
        mov eax, p
        mov ecx, i
        
        jecxz skiplbl1
lbl1:
        // copy stuff
        push dword ptr [eax]
        add eax, 4
        loop lbl1

        // store the pointer ready for copy back
        mov p, eax

skiplbl1:
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

        jecxz skiplbl2
lbl2:
        // copy stuff
        sub eax, 4
        pop dword ptr [eax]
        loop lbl2

skiplbl2:
    }

    for(i = 0; i < vars.GetCount(); ++i)
    {
        vars[i]->_auto = crap[i];
    }
}