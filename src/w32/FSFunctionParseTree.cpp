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
#include "FridgeScript.h"

// this file's header
#include "FSFunctionParseTree.h"

// FridgeScript headers
#include "FSParseTree.h"

// C/C++ headers
#include <string.h>

///////////////////////////////////////////////
// H E L P E R    F U N C T I O N S
///////////////////////////////////////////////

void FSFunction::AddParameterOffset(const unsigned int &offset)
{
    varOffsets.Push( offset );
}

void FSFunction::ResetParameterOffsets()
{
    varOffsets.Clear();
}

Simple::ANSIString FSFunctionParseTree::GetAssembler() const
{
    Simple::ANSIString sResult = "";

    for( unsigned int i = 0; i < fnList.GetCount(); ++i )
    {
        // comment
        sResult += "-- function ";
        sResult += fnList[i]->GetName();
        sResult += "\r\n";

        // label
        sResult += fnList[i]->GetLabel();
        sResult += ":\r\n";

        // the function's code
        sResult += fnList[i]->GetAssembler();
    }

    return sResult;
}

FSFunction* FSFunctionParseTree::GetFunctionInfo(const char* name) const
{
    for( unsigned int i = 0; i < fnList.GetCount(); ++i )
    {
        if( !strcmp( fnList[i]->GetName().GetPointer(), name ) )
        {
            return fnList[i];
        }
    }

    return 0;
}

///////////////////////////////////////////////
// F U N C T I O N    V I S I T O R
///////////////////////////////////////////////

FSFunctionParseTree::~FSFunctionParseTree()
{
    for( unsigned int i = 0; i < fnList.GetCount(); ++i ) delete fnList[i];
}

///////////////////////////////////////////////
// Main : The whole program
///////////////////////////////////////////////

void FSFunctionParseTree::visitMain(Main* main)
{
    main->listblock_->accept( this );
}

///////////////////////////////////////////////
// BFunc : A block containing a list of
//         function definitions
///////////////////////////////////////////////

void FSFunctionParseTree::visitBFunc(BFunc* bfunc)
{
    bfunc->listfunction_->accept( this );
}

///////////////////////////////////////////////
// DTFunc : Default type function definition
///////////////////////////////////////////////
// N E E D S    F I N I S H I N G
///////////////////////////////////////////////
// doesn't deal with parameters completely yet
///////////////////////////////////////////////

void FSFunctionParseTree::visitDTFunc(DTFunc* dtfunc)
{
    // default type function
    // create a new parse tree for the function
    FSParseTree* fp = new FSParseTree( context );
    
    // create a seperate parse tree for the function
    Main fnMain( dtfunc->listblock_ );

    // parse the function code block
    fnMain.accept( fp );

    // create an object to represent the function
    // for the moment the label used in assembler can be the function name, it would be nice to prefix it with something though
    FSFunction* fnStructure = new FSFunction( dtfunc->ident_, dtfunc->ident_ );

    // set the assembler code
    fnStructure->SetAssembler( fp->GetAssemblerString() );

    // check which parameters are actually used in the function
    // this is both optimisation and simplification
    // since we can setup the stack for the locals and just chuck the parameter in there
    ListParameter* pList = dtfunc->listparameter_;
    while( pList != 0 )
    {
        // because it is a default type function is is safe to assume this
        unsigned int uOffset = fp->GetVariableOffset( static_cast<DTParam*>( pList->parameter_ )->ident_ );

        if( uOffset != INVALID_VARIABLE_OFFSET )
        {
            // this parameter goes into [ebp+uOffset]
            fnStructure->AddParameterOffset( uOffset );
        }
        else
        {
            // otherwise throw this parameter away
            fnStructure->AddParameterOffset( INVALID_VARIABLE_OFFSET );
        }
        pList = pList->listparameter_;
    }

    fnList.Push( fnStructure );
    
    delete fp;
}

///////////////////////////////////////////////
// DTParam : Default type function parameter
///////////////////////////////////////////////

void FSFunctionParseTree::visitDTParam(DTParam* dtparam)
{
    // do nothing, the default type function handles the parameters itself
}

///////////////////////////////////////////////
// ListBlock : A list of blocks of code
// e.g. statement lists, function defines, etc.
///////////////////////////////////////////////

void FSFunctionParseTree::visitListBlock(ListBlock* listblock)
{
    while(listblock)
    {
        listblock->block_->accept( this );
        listblock = listblock->listblock_;
    }
}

///////////////////////////////////////////////
// ListFunction : A list of function defines
///////////////////////////////////////////////

void FSFunctionParseTree::visitListFunction(ListFunction* listfunction)
{
    while( listfunction )
    {
        listfunction->function_->accept( this );
        listfunction = listfunction->listfunction_;
    }
}

///////////////////////////////////////////////
// ListFunction : A list of function parameters
///////////////////////////////////////////////

void FSFunctionParseTree::visitListParameter(ListParameter* listparameter)
{
    // this gets handled in the function definition proper e.g. visitDTFunc(DTFunc*)
}