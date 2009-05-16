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

#include "FSFunctionParseTree.h"

#include "FSParseTree.h"

///////////////////////////////////////////////
// F U N C T I O N    V I S I T O R
///////////////////////////////////////////////

///////////////////////////////////////////////
// Main : The whole program
///////////////////////////////////////////////

void FSFunctionParseTree::visitMain(Main* main)
{
    main->listblock_->accept(this);
}

void FSFunctionParseTree::visitBFunc(BFunc* bfunc)
{
    bfunc->listfunction_->accept(this);
}

void FSFunctionParseTree::visitDTFunc(DTFunc* dtfunc)
{
    // default type function
    // create a new parse tree for the function
    FSParseTree* fp = new FSParseTree(context);
    dtfunc->liststatement_->accept(fp);

    // check which parameters are actually used in the function
    // this is both optimisation and simplification
    // since we can setup the stack for the locals and just chuck the parameter in there
    ListParameter* pList = dtfunc->listparameter_;
    while(pList)
    {
        // because it is a default type function is is safe to assume this
        unsigned int uOffset = fp->GetVariableOffset( static_cast<DTParam*>( pList->parameter_ )->ident_ );
        if( uOffset != INVALID_VARIABLE_OFFSET )
        {
            // this parameter goes into [ebp+uOffset]
        }

        // otherwise throw this parameter away
        pList = pList->listparameter_;
    }
    
    delete fp;
}

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
        listblock->block_->accept(this);
        listblock = listblock->listblock_;
    }
}

void FSFunctionParseTree::visitListFunction(ListFunction* listfunction)
{
    while(listfunction)
    {
        listfunction->function_->accept(this);
        listfunction = listfunction->listfunction_;
    }
}

void FSFunctionParseTree::visitListParameter(ListParameter* listparameter)
{
    while(listparameter)
    {
        listparameter->parameter_->accept(this);
        listparameter = listparameter->listparameter_;
    }
}