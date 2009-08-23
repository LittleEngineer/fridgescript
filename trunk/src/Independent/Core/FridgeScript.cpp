/*
    This file is part of FridgeScript.

    FridgeScript is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    ( at your option ) any later version.

    FridgeScript is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FridgeScript.  If not, see <http://www.gnu.org/licenses/>
*/

// main header
#include <Core/FridgeScript.h>

// FridgeScript headers
#include <Core/FSContext.h>
#include <ParseTree/FSParseTree.h>
#include <Variable/FSVariable.h>

// Platform headers
#include <Core/Platform_FridgeScript.h>

// C/C++ headers
#include <string.h>

const u_int ptrMash = 0xABCD1234;
const u_int codeMash = 0x1234ABCD;
const u_int varMash = 0x1A2B3C4D;

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
    return reinterpret_cast< u_int >( new FSContext() ) ^ ptrMash;
}

///////////////////////////////////////////////
// FSDestroyContext : Cleans up a context
///////////////////////////////////////////////

_export FSDestroyContext( u_int context )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to destroy null context" );

    delete reinterpret_cast< FSContext* >( context ^ ptrMash );
    
    return 0;
}

///////////////////////////////////////////////
// FSGetVariableHandle : Converts a string to
//                       a handle to be used
//                       for variable accesses
///////////////////////////////////////////////

_export FSGetVariableHandle( u_int context, u_int codeHandle, char* name )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    Simple::Stack< FSVariable* >* p = reinterpret_cast< FSContext* >( context ^ ptrMash )->GetVariables( codeHandle ^ codeMash );
    for( u_int i = 0; i < p->GetCount(); ++i )
    {
        if( !strcmp( ( *p )[i]->name, name ) ) return reinterpret_cast< u_int >( ( *p )[i] ) ^ varMash;
    }

    return 0;
}

///////////////////////////////////////////////
// FSGetVariableValue : Get value from handle
///////////////////////////////////////////////

_exportval FSGetVariableValue( u_int varHandle )
{
    FSAssert( ( varHandle ^ varMash ) != 0, "Trying to use null variable" );

    FSVariable* p = reinterpret_cast< FSVariable* >( varHandle ^ varMash );

    return p->_auto;
}

///////////////////////////////////////////////
// FSSetVariableValue : Set value from handle
///////////////////////////////////////////////

_exportval FSSetVariableValue( u_int varHandle, float value )
{
    FSAssert( ( varHandle ^ varMash ) != 0, "Trying to use null variable" );

    FSVariable* p = reinterpret_cast< FSVariable* >( varHandle ^ varMash );
    
    return ( p->_auto = value );
}

///////////////////////////////////////////////
// FSRegisterAPI0f : Register an API function
///////////////////////////////////////////////

_export FSRegisterAPI0f( u_int context, char* name, float ( FRIDGE_API * pfnCallback0f )() )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pxContext = reinterpret_cast< FSContext* >( context ^ ptrMash );

    if( pxContext )
    {
        pxContext->RegisterFunction( name, pfnCallback0f );
    }

    return 0;
}

///////////////////////////////////////////////
// FSRegisterAPI1f : Register an API function
///////////////////////////////////////////////

_export FSRegisterAPI1f( u_int context, char* name, float ( FRIDGE_API * pfnCallback1f )( float ) )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pxContext = reinterpret_cast< FSContext* >( context ^ ptrMash );

    if( pxContext )
    {
        pxContext->RegisterFunction( name, pfnCallback1f );
    }

    return 0;
}

///////////////////////////////////////////////
// FSRegisterAPI2f : Register an API function
///////////////////////////////////////////////

_export FSRegisterAPI2f( u_int context, char* name, float ( FRIDGE_API * pfnCallback2f )( float, float ) )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pxContext = reinterpret_cast< FSContext* >( context ^ ptrMash );

    if( pxContext )
    {
        pxContext->RegisterFunction( name, pfnCallback2f );
    }

    return 0;
}

///////////////////////////////////////////////
// FSRegisterAPI3f : Register an API function
///////////////////////////////////////////////

_export FSRegisterAPI3f( u_int context, char* name, float ( FRIDGE_API * pfnCallback3f )( float, float, float ) )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pxContext = reinterpret_cast< FSContext* >( context ^ ptrMash );

    if( pxContext )
    {
        pxContext->RegisterFunction( name, pfnCallback3f );
    }

    return 0;
}

///////////////////////////////////////////////
// FSRegisterAPI4f : Register an API function
///////////////////////////////////////////////

_export FSRegisterAPI4f( u_int context, char* name, float ( FRIDGE_API * pfnCallback4f )( float, float, float, float ) )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pxContext = reinterpret_cast< FSContext* >( context ^ ptrMash );

    if( pxContext )
    {
        pxContext->RegisterFunction( name, pfnCallback4f );
    }

    return 0;
}

///////////////////////////////////////////////
// FSCompile : Compiles code from ANSI string
//             returning a handle that can be
//             used to execute it later
///////////////////////////////////////////////

_export FSCompile( u_int context, char* code )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pContext = reinterpret_cast<FSContext*>( context ^ ptrMash );
    
    u_int ret = pContext->CompileCode( code );
    
    return ( ret != 0 ) ? ret ^ codeMash : 0;
}

///////////////////////////////////////////////
// FSExecute : Executes code from the handle
//             provided by FSCompile
///////////////////////////////////////////////

_export FSExecute( u_int context, u_int codeHandle )
{
    FSAssert( ( context ^ ptrMash ) != 0, "Trying to use null context" );

    FSContext* pContext = reinterpret_cast<FSContext*>( context ^ ptrMash );

    FSAssert( ( codeHandle ^ codeMash ) != 0, "Trying to use null code" );

    pContext->ExecuteCode( codeHandle ^ codeMash );

    return 0; 
}