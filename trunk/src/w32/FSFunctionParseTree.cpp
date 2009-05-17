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

FSFunctionParseTree::~FSFunctionParseTree()
{
    for(unsigned int i = 0; i < fnList.GetCount(); ++i) delete fnList[i];
}

///////////////////////////////////////////////
// Main : The whole program
///////////////////////////////////////////////

void FSFunctionParseTree::visitMain(Main* main)
{
    main->listblock_->accept(this);
}

///////////////////////////////////////////////
// BFunc : A block containing a list of
//         function definitions
///////////////////////////////////////////////

void FSFunctionParseTree::visitBFunc(BFunc* bfunc)
{
    bfunc->listfunction_->accept(this);
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
    FSParseTree* fp = new FSParseTree(context);
    //dtfunc->liststatement_->accept(fp);
    
    // create a seperate parse tree for the function quickly on the stack
    // this might be nice to wrap into a function, but for now it only happens here
    BStmt fnBlock(dtfunc->liststatement_);
    ListBlock fnListBlock(&fnBlock);
    Main fnMain(&fnListBlock);

    // parse the function code block
    fnMain.accept(fp);

    // create an object to represent the function
    // for the moment the label used in assembler can be the function name, it would be nice to prefix it with something though
    FSFunction* fnStructure = new FSFunction(dtfunc->ident_, dtfunc->ident_);

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
            // TODO: Keep track of this in the function structure
        }

        // otherwise throw this parameter away
        pList = pList->listparameter_;
    }
    
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
        listblock->block_->accept(this);
        listblock = listblock->listblock_;
    }
}

///////////////////////////////////////////////
// ListFunction : A list of function defines
///////////////////////////////////////////////

void FSFunctionParseTree::visitListFunction(ListFunction* listfunction)
{
    while(listfunction)
    {
        listfunction->function_->accept(this);
        listfunction = listfunction->listfunction_;
    }
}

///////////////////////////////////////////////
// ListFunction : A list of function parameters
///////////////////////////////////////////////

void FSFunctionParseTree::visitListParameter(ListParameter* listparameter)
{
    // this gets handled in the function definition proper e.g. visitDTFunc(DTFunc*)
    /*
    while(listparameter)
    {
        listparameter->parameter_->accept(this);
        listparameter = listparameter->listparameter_;
    }
    */
}