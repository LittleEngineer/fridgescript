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