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

#ifndef __FSFunctionParseTree_h
#define __FSFunctionParseTree_h

#include "FSContext.h"
#include "FSVisitor.h"

#include "SimpleStructures.h"

///////////////////////////////////////////////
// FSFunction : Holds data for a function
///////////////////////////////////////////////

class FSFunction
{
private:
    Simple::ANSIString  name;
    Simple::ANSIString  assembler;
    Simple::ANSIString  label;

    Simple::Stack<unsigned int> varOffsets;
public:
    FSFunction(const char* const identifier, const char* const asmLabel) : name(identifier), label(asmLabel), assembler(), varOffsets() {}
    ~FSFunction() {}

    void AddParameterOffset(const unsigned int& offset);
    void ResetParameterOffsets();

    Simple::ANSIString GetName() const { return name; }
    Simple::ANSIString GetLabel() const { return label; }
    Simple::ANSIString GetAssembler() const { return assembler; }
    Simple::Stack<unsigned int> GetOffsets() const { return varOffsets; }

    void SetAssembler(Simple::ANSIString sAssembler) { assembler = sAssembler; }
};

///////////////////////////////////////////////
// FSFunctionParseTree : Parses functions
// Emits assembler and stores information for
// the final pass of the compile
///////////////////////////////////////////////

class FSFunctionParseTree : public FSVisitor
{
private:
    FSContext* context;
    Simple::Stack<FSFunction*> fnList;
public:
    FSFunctionParseTree(FSContext* c) : context(c), fnList() {}
    ~FSFunctionParseTree();

    void visitMain(Main* main);
    void visitBFunc(BFunc* bfunc);
    void visitDTFunc(DTFunc* dtfunc);
    void visitDTParam(DTParam* dtparam);
    void visitListBlock(ListBlock* listblock);
    void visitListFunction(ListFunction* listfunction);
    void visitListParameter(ListParameter* listparameter);

    Simple::ANSIString GetAssembler() const;

    FSFunction* GetFunctionInfo(const char* name) const;
};

#endif