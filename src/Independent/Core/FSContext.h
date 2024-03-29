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

#ifndef __FSContext_h
#define __FSContext_h

#include <API/APIList.h>

class FSVariable;
class FSCompiledCode;

class FSContext : public APIList
{

    typedef APIList PARENT;

public:

    FSContext() : PARENT(), code(0), numCode(0) { }
    virtual ~FSContext();

    Simple::Stack<FSVariable*>* GetVariables( const unsigned int& id );
    unsigned int CompileCode( const char* const& source );
    void ExecuteCode( const unsigned int& id );

    float* GetConstant( const float& value );

protected:

    FSCompiledCode**            code;
    unsigned int                numCode;
    Simple::Stack< float* >     constants;

};

#endif