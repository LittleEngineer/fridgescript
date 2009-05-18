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

/*
    return values go on st0
    instead of using the heap, the stack is used to store the doubles
    parameters are passed in on the stack in whatever order the compiler likes
    function calls are not yet implemented
    constants currently use the heap and are bug prone
*/

#include "FSParseTree.h"

#include "Absyn.h"
#include "FSContext.h"
#include "FSFunctionParseTree.h"
#include "FSVariable.h"

#include <string.h>
#include <time.h>

///////////////////////////////////////////////
// H E L P E R    F U N C T I O N S
///////////////////////////////////////////////

///////////////////////////////////////////////
// Appends some assembler code to push a double
// precision float onto the stack from st(0)
///////////////////////////////////////////////

void FSParseTree::pushDouble()
{
    // sub esp, 8 would be MUCH better than two pushes
    assembler += "push eax\r\npush eax\r\nfstp [esp]\r\n";
}

///////////////////////////////////////////////
// Appends some assembler code to pop a double
// precision float off of the stack into st(0)
///////////////////////////////////////////////

void FSParseTree::popDouble()
{
    // add esp, 8 would be MUCH better than two pops
    assembler += "fld [esp]\r\npop eax\r\npop eax\r\n";
}

///////////////////////////////////////////////
// Generate a random label for jmp, call etc.
///////////////////////////////////////////////

Simple::ANSIString FSParseTree::GetRandomLabel()
{
    Simple::ANSIString ret;
    ret += "lbl";
    static int seed = 0;
    for(unsigned int i = 0; i < 15; ++i)
    {
        switch((i + time(0)) & 0x1)
        {
        case 0:
            ret += static_cast<char>((static_cast<unsigned int>(time(0) + seed) % 10) + '0');
            break;
        case 1:
            ret += static_cast<char>((static_cast<unsigned int>(time(0) + seed) & 0xF) + 'A');
            break;
        }
        seed += 37;
    }
    return ret;
}

///////////////////////////////////////////////
// Get the offset of a local variable from ebp
///////////////////////////////////////////////

unsigned int FSParseTree::GetVariableOffset(const char* const& name)
{
    for(unsigned int i = 0; i < GetVariableStackPointer()->GetCount(); ++i)
    {
        if(!strcmp((*GetVariableStackPointer())[i]->name, name))
        {
            return 8*(GetVariableStackPointer()->GetCount() - i - 1);
        }
    }
    
    return INVALID_VARIABLE_OFFSET;
}

///////////////////////////////////////////////
// C O M P I L E R
///////////////////////////////////////////////

///////////////////////////////////////////////
// Main : The whole program
///////////////////////////////////////////////

void FSParseTree::visitMain(Main* main)
{
    // first parse the variables
    // this must be done first so that the variable references can be resolved in a single pass
    main->accept(&varPicker);

    // parse the functions, this is important:
    // * function calls can be done in one pass
    // * some optimisations can be done in one pass
    main->accept(&fnTree);

    // now we should have the complete tree of functions and references for every variable
    // this allows for single pass generation of code (ignoring any optimisations we may decide to add later)
    main->listblock_->accept(this);

    // all of the assembler code has been emitted, just one thing left to do...
    assembler += "ret\r\n";
}

///////////////////////////////////////////////
// BStmt : A list of statements
///////////////////////////////////////////////

void FSParseTree::visitBStmt(BStmt* bstmt)
{
    bstmt->liststatement_->accept(this);
}

///////////////////////////////////////////////
// ListBlock : A list of blocks of code
// e.g. statement lists, function defines, etc.
///////////////////////////////////////////////

void FSParseTree::visitListBlock(ListBlock* listblock)
{
    while(listblock)
    {
        listblock->block_->accept(this);
        listblock = listblock->listblock_;
    }
}

///////////////////////////////////////////////
// ListBlock : A list of statements
// e.g. if, for, expressions, etc.
///////////////////////////////////////////////

void FSParseTree::visitListStatement(ListStatement* liststatement)
{
    while(liststatement)
    {
        liststatement->statement_->accept(this);
        liststatement = liststatement->liststatement_;
    }
}

///////////////////////////////////////////////
// SExp : An expression statement
// e.g. a = b + c;
///////////////////////////////////////////////

void FSParseTree::visitSExp(SExp* sexp)
{
    assembler += "-- expression statement\r\n";

    sexp->expression_->accept(this);

    // clean the expression result off of the fpu stack
    assembler += "-- end of expression\r\nffree st(0)\r\n";
}

///////////////////////////////////////////////
// SScope : Just a bit of code wrapped in { }
// doesn't create a variable scope like C++
///////////////////////////////////////////////

void FSParseTree::visitSScope(SScope* sscope)
{
    sscope->liststatement_->accept(this);
}

///////////////////////////////////////////////
// SRet : The return statement
// leaves a result in st(0)
///////////////////////////////////////////////

void FSParseTree::visitSRet(SRet* sret)
{
    assembler += "-- return statement\r\n";

    sret->expression_->accept(this);
    assembler += "ret\r\n";

    assembler += "-- end of return statement\r\n";
}

///////////////////////////////////////////////
// SIf : The if statement
// runs code depending on a test
///////////////////////////////////////////////

void FSParseTree::visitSIf(SIf* sif)
{
    // evaluate expression
    assembler += "-- if statement expresion\r\n";

    sif->expression_->accept(this);

    // compare st0 with zero
    assembler += "-- compare result with zero for if statement\r\n";
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";

    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "ffree st(1)\r\n";

    // jump if zero ...
    assembler += "jz ";
    Simple::ANSIString lbl = GetRandomLabel();
    assembler += lbl;
    assembler += "\r\n";

    // ... otherwise do what the if contains
    assembler += "-- if statement contents\r\n";
    sif->statement_->accept(this);
    
    // end label
    assembler += lbl;
    assembler += ":\r\n";
    
    assembler += "-- end of if statement\r\n";
}

///////////////////////////////////////////////
// SIfElse : The if-else statement
// runs code depending on a test
///////////////////////////////////////////////

void FSParseTree::visitSIfElse(SIfElse* sifelse)
{
    // evaluate expression
    assembler += "-- if statement expresion\r\n";
    
    sifelse->expression_->accept(this);
    
    // compare st0 with zero
    assembler += "-- compare result with zero for if statement\r\n";
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "ffree st(1)\r\n";
    
    // jump if zero to the else block ...
    assembler += "jz ";
    Simple::ANSIString lblElse = GetRandomLabel();
    assembler += lblElse;
    assembler += "\r\n";
    
    // ... otherwise run the contents of the if block then jump to the end
    assembler += "-- if statement contents\r\n";
    
    sifelse->statement_1->accept(this);
    
    assembler += "jmp ";
    Simple::ANSIString lblEnd = GetRandomLabel();
    assembler += lblEnd;
    assembler += "\r\n";
    
    // now put the else block and its label
    assembler += "-- else contents\r\n";
    assembler += lblElse;
    assembler += ":\r\n";
    
    sifelse->statement_2->accept(this);

    // then the end label for the if block
    assembler += lblEnd;
    assembler += ":\r\n";

    assembler += "-- end of if statement\r\n";
}

///////////////////////////////////////////////
// SWhile : The while statement
// does a test then runs code and repeats until
// the test fails
///////////////////////////////////////////////

void FSParseTree::visitSWhile(SWhile* swhile)
{
    assembler += "-- while statement\r\n";
    Simple::ANSIString lblStart = GetRandomLabel();
    assembler += lblStart;
    assembler += ":\r\n";
    // evaluate expression
    assembler += "-- while statement expression\r\n";
    swhile->expression_->accept(this);
    // compare st0 with zero
    assembler += "-- compare result with zero for while statement\r\n";
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "ffree st(1)\r\n";
    // jump if zero to the end ...
    assembler += "jz ";
    Simple::ANSIString lblEnd = GetRandomLabel();
    assembler += lblEnd;
    assembler += "\r\n";
    // ... otherwise run the contents of the loop block then jump back to the start
    assembler += "-- while statement contents\r\n";
    swhile->statement_->accept(this);
    assembler += "jmp ";
    assembler += lblStart;
    assembler += "\r\n";
    assembler += "-- end of while statement\r\n";
    assembler += lblEnd;
    assembler += ":\r\n";
}

///////////////////////////////////////////////
// SUntil : The until statement
// runs code then does a test and repeats until
// the test succeeds
///////////////////////////////////////////////

void FSParseTree::visitSUntil(SUntil* suntil)
{
    assembler += "-- until statement\r\n";
    Simple::ANSIString lblStart = GetRandomLabel();
    assembler += lblStart;
    assembler += ":\r\n";
    // run the contents of the loop block then jump back to the start
    suntil->statement_->accept(this);
    // evaluate expression
    suntil->expression_->accept(this);
    // compare st0 with zero
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "ffree st(1)\r\n";
    // jump if zero to the beginning ...
    assembler += "jz ";
    assembler += lblStart;
    assembler += "\r\n";
    // ... otherwise continue
}

///////////////////////////////////////////////
// SFor : The for statement
// for ( a; b; c )
// runs a then runs code depending on test b
// then runs c and repeats
///////////////////////////////////////////////

void FSParseTree::visitSFor(SFor* sfor)
{
    assembler += "-- for statement\r\n";
    assembler += "-- initialise\r\n";
    sfor->expression_1->accept(this);
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "-- start of loop\r\n";
    Simple::ANSIString lblStart = GetRandomLabel();
    assembler += lblStart;
    assembler += ":\r\n";
    assembler += "-- run test\r\n";
    sfor->expression_2->accept(this);
    // compare st0 with zero
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "ffree st(1)\r\n";
    // skip to end if condition fails ...
    Simple::ANSIString lblEnd = GetRandomLabel();
    assembler += "jz ";
    assembler += lblEnd;
    assembler += "\r\n";
    // ... otherwise run for block then the final loop expression
    assembler += "-- run for contents\r\n";
    sfor->statement_->accept(this);
    assembler += "-- run for expression\r\n";
    sfor->expression_3->accept(this);
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(0)\r\n";
    assembler += "-- loop\r\n";
    assembler += "jmp ";
    assembler += lblStart;
    assembler += "\r\n";
    assembler += "-- end of for statement\r\n";
    assembler += lblEnd;
    assembler += ":\r\n";
}

///////////////////////////////////////////////
// SBreak : The break statement
// for breaking out of loops or ifs
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitSBreak(SBreak* sbreak)
{
}

///////////////////////////////////////////////
// SContinue : The continue statement
// for skipping to the next loop
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitSContinue(SContinue* scontinue)
{
}

///////////////////////////////////////////////
// ECDbl : Double constant for expressions
///////////////////////////////////////////////

void FSParseTree::visitECDbl(ECDbl* ecdbl)
{
    // ecdbl->double_ contains the constant as a double
    // fld ...
    if(ecdbl->double_ == 0.0)
    {
        // fldz
        assembler += "-- load zero\r\n";
        assembler += "fldz\r\n";
    }
    else if(ecdbl->double_ == 1.0)
    {
        // fld1
        assembler += "-- load one\r\n";
        assembler += "fld1\r\n";
    }
    else
    {
        assembler += "-- load constant\r\n";
        assembler += "fld [";
        assembler.AppendHex(reinterpret_cast<unsigned int>(context->GetConstant(ecdbl->double_)));
        assembler += "]\r\n";
    }
}

///////////////////////////////////////////////
// ECInt : Integer constant for expressions
///////////////////////////////////////////////

void FSParseTree::visitECInt(ECInt* ecint)
{
    // ecint->integer_ contains the constant as an int
    // fld ...
    if(ecint->integer_ == 0)
    {
        // fldz
        assembler += "-- load zero\r\n";
        assembler += "fldz\r\n";
    }
    else if(ecint->integer_ == 1)
    {
        // fld1
        assembler += "-- load one\r\n";
        assembler += "fld1\r\n";
    }
    else
    {
        assembler += "-- load constant ";
        assembler.AppendInt(ecint->integer_);
        assembler += "\r\n";
        assembler += "fld [";
        assembler.AppendHex(reinterpret_cast<unsigned int>(context->GetConstant(static_cast<double>(ecint->integer_))));
        assembler += "]\r\n";
    }
}

///////////////////////////////////////////////
// EVar : Variable for expressions
///////////////////////////////////////////////

void FSParseTree::visitEVar(EVar *evar)
{
    // load the variable
    assembler += "-- load variable ";
    assembler += evar->ident_;
    assembler += "\r\n";
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(evar->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(evar->ident_, 0)));
    assembler += "]\r\n";

}

///////////////////////////////////////////////
// EPi : Pi constant for expressions
///////////////////////////////////////////////

void FSParseTree::visitEPi(EPi *epi)
{
    // fldpi
    assembler += "-- load pi\r\n";
    assembler += "fldpi\r\n";
}

///////////////////////////////////////////////
// ECall : Function call
// the function result is to return in st(0)
// the parameters are handled as locals and
// are setup in the function parse tree
///////////////////////////////////////////////

void FSParseTree::visitECall(ECall* ecall)
{
    // push parameters
    ListExpression* e = ecall->listexpression_;
    while(e)
    {
        e = e->listexpression_;
    }
    // call function (function cleans stack)
}

///////////////////////////////////////////////
// EPostInc : Post-increment
///////////////////////////////////////////////

void FSParseTree::visitEPostInc(EPostInc* epostinc)
{
    /*
        load variable then load 1
        faddp does st(1) = st(1) + st(0) and pops the x87 stack
        so st(0) = var + 1
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    assembler += "-- post-increment variable ";
    assembler += epostinc->ident_;
    assembler += "\r\n";
    // load variable
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(epostinc->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(epostinc->ident_, 0)));
    assembler += "]\r\n";
    // dupe
    assembler += "fld st(0)\r\n";
    // load 1
    assembler += "fld1\r\n";
    // add
    assembler += "faddp\r\n";
    // store result
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(epostinc->ident_));
    assembler += "]\r\n";
    // clean stack so old value is on top
    assembler += "fstp st(0)\r\n";
}

///////////////////////////////////////////////
// EPostDec : Post-decrement
///////////////////////////////////////////////

void FSParseTree::visitEPostDec(EPostDec* epostdec)
{
    /*
        load variable then load 1
        faddp does st(1) = st(1) + st(0) and pops the x87 stack
        so st(0) = var + 1
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    assembler += "-- post-decrement variable ";
    assembler += epostdec->ident_;
    assembler += "\r\n";
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(epostdec->ident_));
    assembler += "]\r\n";
    // dupe
    assembler += "fld st(0)\r\n";
    // load 1
    assembler += "fld1\r\n";
    assembler += "fsubp\r\n";
    // store result
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(epostdec->ident_));
    assembler += "]\r\n";
    // clean stack so old value is on top
    assembler += "fstp st(0)\r\n";
}

///////////////////////////////////////////////
// EPow : Power function
// This is quite expensive and messy
///////////////////////////////////////////////

void FSParseTree::visitEPow(EPow* epow)
{
    /*
        pow(x,y) = 2^(y*lg(x))
        since:
        z = pow(x,y)
        lg z = y*lg(x)
        z = 2^(y*lg(x))

        fyl2x does st(0) = st(1) * lg(st(0))
        f2xm1 does st(0) = 2^(st(0) - 1.0
    */

    assembler += "-- power function\r\n";

    /*
        evaluate second expression and push
    */

    assembler += "-- expression 1\r\n";
    epow->expression_1->accept(this);
    assembler += "-- end expression 1\r\n";
    pushDouble();
    /*
        evaluate first expression then pop previous result
        ready for a binary operation
    */
    assembler += "-- expression 2\r\n";
    epow->expression_2->accept(this);
    assembler += "-- end expression 2\r\n";
    popDouble();
    // from pow(x,y)...
    // st(1) = y
    // st(0) = x
    assembler += "-- do the powering\r\n";
    assembler += "fyl2x\r\n";
    // st(0) = y*lg(x)

    // split the result into integer and fraction
    assembler += "fld st(0)\r\n";
    assembler += "frndint\r\n";
    // st(1) = y*lg(x)
    // st(0) = round(y*lg(x))
    
    assembler += "fsub\r\n";
    // st(1) = remainder(y*lg(x))
    // st(0) = round(y*lg(x))
    
    // work out power of integer and fractional part
    assembler += "fld1\r\n";
    assembler += "fscale\r\n";
    assembler += "fxch\r\n";
    assembler += "fstp st(0)\r\n";
    assembler += "fxch\r\n";
    assembler += "f2xm1\r\n";
    // st(1) = pow(x,round(y))
    // st(0) = pow(x,remainder(y)) - 1
    
    // add one to finish integral power then multiply by fractional part
    assembler += "fld1\r\n";
    assembler += "faddp\r\n";
    assembler += "fmulp\r\n";

    assembler += "-- end of power function\r\n";
}

///////////////////////////////////////////////
// ESqrt : Square-root function
// This can be optimised:
// * SSE sqrt function
// * magic number hack
///////////////////////////////////////////////

void FSParseTree::visitESqrt(ESqrt* esqrt)
{
    assembler += "-- expression for sqrt\r\n";

    /*
        evaluate the expression
        sqrt the result and leave it in st(0) for the rest of the expression
    */

    esqrt->expression_->accept(this);

    assembler += "-- sqrt\r\n";
    assembler += "fsqrt\r\n";

    assembler += "-- end sqrt\r\n";
}

///////////////////////////////////////////////
// EExp : Exponential function
// This is messy like EPow
///////////////////////////////////////////////

void FSParseTree::visitEExp(EExp* eexp)
{
    // this just copies pow but uses e for x
    /*
        pow(x,y) = 2^(y*lg(x))
        since:
        z = pow(x,y)
        lg z = y*lg(x)
        z = 2^(y*lg(x))

        fyl2x does st(0) = st(1) * lg(st(0))
        f2xm1 does st(0) = 2^(st(0) - 1.0
    */

    assembler += "-- exponential function expression\r\n";

    /*
        evaluate expression
    */
    eexp->expression_->accept(this);
    // st(0) = y

    // push e
    assembler += "-- load e\r\n";
    assembler += "fld [";
    assembler.AppendHex(reinterpret_cast<unsigned int>(context->GetConstant(2.7182818284590452353602874713527)));
    assembler += "]\r\n";    
    // from pow(x,y)...
    // st(1) = y
    // st(0) = x
    
    assembler += "-- do power function\r\n";
    assembler += "fyl2x\r\n";
    // st(0) = y*lg(x)
    
    assembler += "fld st(0)\r\n";
    assembler += "frndint\r\n";
    // st(1) = y*lg(x)
    // st(0) = round(y*lg(x))
    
    assembler += "fsub\r\n";
    // st(1) = remainder(y*lg(x))
    // st(0) = round(y*lg(x))
    
    // work out power of integer and fractional part
    assembler += "fld1\r\n";
    assembler += "fscale\r\n";
    assembler += "fxch\r\n";
    assembler += "fstp st(0)\r\n";
    assembler += "fxch\r\n";
    assembler += "f2xm1\r\n";
    // st(1) = pow(x,round(y))
    // st(0) = pow(x,remainder(y)) - 1
    
    // add one to finish integral power then multiply by fractional part
    assembler += "fld1\r\n";
    assembler += "faddp\r\n";
    assembler += "fmulp\r\n";
    
    assembler += "-- end exponential function\r\n";
}

///////////////////////////////////////////////
// ELog : Natural logarithm
///////////////////////////////////////////////

void FSParseTree::visitELog(ELog* elog)
{
    /*
        log 2^(lg x) = log x = lg x * log 2
    */
    assembler += "-- expression for natural logarithm\r\n";

    elog->expression_->accept(this);

    assembler += "-- natural logarithm\r\n";
    assembler += "fldln2\r\n";
    assembler += "fxch\r\n";
    assembler += "fyl2x\r\n";
    
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    
    assembler += "-- end natural logarithm\r\n";
}

///////////////////////////////////////////////
// ELogD : Base 10 logarithm
///////////////////////////////////////////////

void FSParseTree::visitELogD(ELogD* elogd)
{
    /*
        log10 2^(lg x) = log10 x = lg x * log10 2
    */
    
    assembler += "-- expression for log 10\r\n";
    
    elogd->expression_->accept(this);
    
    assembler += "-- log 10\r\n";
    assembler += "fldlg2\r\n";
    assembler += "fxch\r\n";
    assembler += "fyl2x\r\n";
    
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    
    assembler += "-- end log 10\r\n";
}

void FSParseTree::visitESin(ESin* esin)
{
    /*
        evaluate the expression
        take sine of the result and leave it in st(0) for the rest of the expression
    */
    assembler += "-- expression for sin\r\n";
    esin->expression_->accept(this);
    assembler += "-- sin\r\n";
    assembler += "fsin\r\n";
    assembler += "-- end sin\r\n";
}

void FSParseTree::visitECos(ECos* ecos)
{
    /*
        evaluate the expression
        take cosine of the result and leave it in st(0) for the rest of the expression
    */
    assembler += "-- expression for cos\r\n";
    ecos->expression_->accept(this);
    assembler += "-- cos\r\n";
    assembler += "fcos\r\n";
    assembler += "-- end cos\r\n";
}

void FSParseTree::visitETan(ETan* etan)
{
    /*
        evaluate the expression
        take tan of the result and leave it in st(0) for the rest of the expression
        fptan pushes 1.0 so we need an extra pop
    */
    etan->expression_->accept(this);
    
    assembler += "fptan\r\n";
    assembler += "fstp st(0)\r\n";
}

void FSParseTree::visitEAtan(EAtan* eatan)
{
    /*
        evaluate the expression
        take atan of the result and leave it in st(0) for the rest of the expression
        fpatan takes the atan of st(1)/st(0) so load a 1 before executing fpatan
    */
    eatan->expression_->accept(this);
    
    assembler += "fld1\r\n";
    assembler += "fpatan\r\n";
}

void FSParseTree::visitEAtanT(EAtanT* eatant)
{
    /*
        evaluate first expression and push
    */
    eatant->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    eatant->expression_1->accept(this);
    popDouble();
    /*
        fpatan does st(0) = atan(st(1)/st(0)) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fpatan\r\n";
}

void FSParseTree::visitEAsin(EAsin* easin)
{
    /*
        asin(x) = 2*atan(x/(1 + sqrt(1 - x*x)))
    */
    // load x
    easin->expression_->accept(this);
    // we want st(0) to equal 1+sqrt(1-st(1)*st(1))
    assembler += "fld1\r\n";
    assembler += "fld st(1)\r\n";
    assembler += "fld st(0)\r\n";
    // st(3) = x
    // st(2) = 1
    // st(1) = x
    // st(0) = x
    assembler += "fmulp\r\n";
    // st(2) = x
    // st(1) = 1
    // st(0) = x*x
    assembler += "fsubp\r\n";
    // st(1) = x
    // st(0) = 1-x*x
    assembler += "fsqrt\r\n";
    // st(1) = x
    // st(0) = sqrt(1-x*x)
    assembler += "fld1\r\n";
    // st(2) = x
    // st(1) = sqrt(1-x*x)
    // st(0) = 1
    assembler += "faddp\r\n";
    // st(1) = x
    // st(0) = 1+sqrt(1-x*x)
    assembler += "fpatan\r\n";
    // st(0) = atan(x/(1 + sqrt (1-x*x))
    // multiply by 2 by adding to itself
    assembler += "fld st(0)\r\n";
    assembler += "faddp\r\n";   
}

///////////////////////////////////////////////
// EAcos : Inverse cosine function
// this is a naive implementation since it can
// divide by zero and relies on this identity:
// acos( x ) =
// 2 * atan( sqrt ( 1 - x * x ) / ( 1 + x ) )
///////////////////////////////////////////////

void FSParseTree::visitEAcos(EAcos* eacos)
{
    /*
        acos(x) = 2*atan(sqrt(1 - x*x)/(1 + x))
    */

    assembler += "-- expression for acos\r\n";

    // load x
    eacos->expression_->accept(this);
    
    assembler += "-- acos\r\n";

    // we want st(1) = sqrt(1 - x*x) and st(0) = (1 + x)
    assembler += "fld1\r\n";
    assembler += "fld st(1)\r\n";
    assembler += "fld st(0)\r\n";
    // st(3) = x
    // st(2) = 1
    // st(1) = x
    // st(0) = x
    
    assembler += "fmulp\r\n";
    // st(2) = x
    // st(1) = 1
    // st(0) = x*x
    
    assembler += "fsubp\r\n";
    // st(1) = x
    // st(0) = 1-x*x
    
    assembler += "fsqrt\r\n";
    // st(1) = x
    // st(0) = sqrt(1-x*x)
    
    assembler += "fxch\r\n";
    // st(1) = sqrt(1-x*x)
    // st(0) = x
    
    assembler += "fld1\r\n";
    // st(2) = sqrt(1-x*x)
    // st(1) = x
    // st(0) = 1
    
    assembler += "faddp\r\n";
    // st(1) = sqrt(1-x*x)
    // st(0) = 1+x
    
    assembler += "fpatan\r\n";
    // st(0) = atan(sqrt(1-x*x)/(1+x))
    // multiply by 2 by adding to itself
    
    assembler += "fld st(0)\r\n";
    assembler += "faddp\r\n";

    assembler += "-- end of acos\r\n";
}

void FSParseTree::visitELnot(ELnot* elnot)
{
    /*
        test if expression is equal to 0 and return 1 if it is, otherwise 0
    */
    assembler += "-- expression for logical not\r\n";
    elnot->expression_->accept(this);
    assembler += "-- logical not\r\n";
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    // zero is on top, so load 1 then exchange
    assembler += "fld1\r\n";
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(2)";
    assembler += "fxch\r\n";
    // if it was equal move st(1) to st(0)
    assembler += "fcmove\r\n";
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)";
    assembler += "-- end of logical not\r\n";
}

void FSParseTree::visitEPreInc(EPreInc* epreinc)
{
    /*
        load variable then load 1
        faddp does st(1) = st(1) + st(0) and pops the x87 stack
        so st(0) = var + 1
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    assembler += "-- pre-increment variable ";
    assembler += epreinc->ident_;
    assembler += "\r\n";
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(epreinc->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(epreinc->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fld1\r\n";
    assembler += "faddp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(epreinc->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(epreinc->ident_, 0)));
    assembler += "]\r\n";
}

void FSParseTree::visitEPreDec(EPreDec* epredec)
{
    /*
        load variable then load 1
        fsubp does st(1) = st(1) - st(0) and pops the x87 stack
        so st(0) = var - 1
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    assembler += "-- pre-decrement variable ";
    assembler += epredec->ident_;
    assembler += "\r\n";
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(epredec->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(epredec->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fld1\r\n";
    assembler += "fsubp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(epredec->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(epredec->ident_, 0)));
    assembler += "]\r\n";
}

void FSParseTree::visitENeg(ENeg* eneg)
{
    /*
        evaluate the expression
        take cosine of the result and leave it in st(0) for the rest of the expression
    */
    eneg->expression_->accept(this);
    assembler += "fchs\r\n";
}

///////////////////////////////////////////////
// EBnot : Bitwise not operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEBnot(EBnot* ebnot)
{
}

void FSParseTree::visitEPos(EPos* epos)
{
    // no need to do anything here... unary plus is a bit of a waste. :)
}

void FSParseTree::visitEMul(EMul* emul)
{
    /*
        evaluate first expression and push
    */
    emul->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    emul->expression_1->accept(this);
    popDouble();
    /*
        fmulp does st(1) = st(0) * st(1) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fmulp\r\n";
}

void FSParseTree::visitEDiv(EDiv* ediv)
{
    /*
        evaluate first expression and push
    */
    ediv->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    ediv->expression_1->accept(this);
    popDouble();
    /*
        fdivp does st(1) = st(1) / st(0) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fdivp\r\n";
}

void FSParseTree::visitEMod(EMod* emod)
{
    /*
        evaluate second expression and push
    */
    emod->expression_1->accept(this);
    pushDouble();
    /*
        evaluate first expression than pop previous result
        ready for a binary operation
    */
    emod->expression_2->accept(this);
    popDouble();
    /*
        fprem does st(1) = st(1) % st(0) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fprem\r\n";
}

void FSParseTree::visitEAdd(EAdd* eadd)
{
    /*
        evaluate first expression and push
    */
    eadd->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    eadd->expression_1->accept(this);
    popDouble();
    /*
        faddp does st(1) = st(0) + st(1) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "faddp\r\n";
}

void FSParseTree::visitESub(ESub* esub)
{
    /*
        evaluate first expression and push
    */
    esub->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    esub->expression_1->accept(this);
    popDouble();
    /*
        fsubp does st(1) = st(1) - st(0) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fsubp\r\n";
}

void FSParseTree::visitELSh(ELSh* elsh)
{
    /*
        evaluate first expression and push
    */
    elsh->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    elsh->expression_2->accept(this);
    popDouble();
    /*
        fscale does st(1) = st(1) << st(0) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fscale\r\n";
}

void FSParseTree::visitERSh(ERSh* ersh)
{
    /*
        evaluate first expression and push
    */
    ersh->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression than pop previous result
        ready for a binary operation
    */
    ersh->expression_2->accept(this);
    assembler += "fchs\r\n";
    popDouble();
    /*
        fscale does st(1) = st(1) << st(0) and pops
        leaving the result in st(0) ready for the next expression
    */
    assembler += "fscale\r\n";
}

void FSParseTree::visitELT(ELT* elt)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    elt->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    elt->expression_2->accept(this);
    popDouble();
    assembler += "-- logical less than\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmovb\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

void FSParseTree::visitEGT(EGT* egt)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    egt->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    egt->expression_1->accept(this);
    popDouble();
    assembler += "-- logical greater than\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmovbe\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

void FSParseTree::visitELE(ELE* ele)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    ele->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    ele->expression_2->accept(this);
    popDouble();
    assembler += "-- logical less or equal\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmovbe\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

void FSParseTree::visitEGE(EGE* ege)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    ege->expression_2->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    ege->expression_1->accept(this);
    popDouble();
    assembler += "-- logical greater or equal\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmovb\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

void FSParseTree::visitEE(EE* ee)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    ee->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    ee->expression_2->accept(this);
    popDouble();
    assembler += "-- logical equal\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmove\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

void FSParseTree::visitENE(ENE* ene)
{
    /*
        evaluate first expression and push
    */
    assembler += "-- expressions for comparison\r\n";
    ene->expression_1->accept(this);
    pushDouble();
    /*
        evaluate second expression then pop previous result
        ready for a binary operation
    */
    ene->expression_2->accept(this);
    popDouble();
    assembler += "-- logical not equal\r\n";
    assembler += "fcomi\r\n";
    assembler += "fld1\r\n";
    assembler += "fldz\r\n";
    assembler += "fcmovne\r\n";
    // clean stack
    assembler += "-- clean stack\r\n";
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "ffree st(3)\r\n";
}

///////////////////////////////////////////////
// ELand : Bitwise and operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEBand(EBand* eband)
{
}

///////////////////////////////////////////////
// EBor : Bitwise inclusive or operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEBor(EBor* ebor)
{
}

///////////////////////////////////////////////
// EBxor : Bitwise exclusive or operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEBxor(EBxor* ebxor)
{
}

///////////////////////////////////////////////
// ELand : Logical and operator
///////////////////////////////////////////////

void FSParseTree::visitELand(ELand* eland)
{
    /*
        expression1 && expression2
        test if expression1 is equal to 0 and return 0 if it is, otherwise return expression2
    */
    eland->expression_2->accept(this);
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    // clean stack
    assembler += "ffree st(1)\r\n";
    Simple::ANSIString lblEnd = GetRandomLabel();
    // zero is in st(0) so ending now returns zero ...
    assembler += "je ";
    assembler += lblEnd;
    assembler += "\r\n";
    // clean stack
    assembler += "ffree st(0)\r\n";
    // ... otherwise evaluate the next expression
    eland->expression_1->accept(this);
    assembler += lblEnd;
    assembler += ":\r\n";
}

///////////////////////////////////////////////
// ELor : Logical inclusive or operator
///////////////////////////////////////////////

void FSParseTree::visitELor(ELor* elor)
{
    /*
        expression1 && expression2
        test if expression1 is equal to 0 and return 1 if it is not, otherwise return expression2
    */
    elor->expression_2->accept(this);
    assembler += "fldz\r\n";
    assembler += "fcomi\r\n";
    Simple::ANSIString lblEnd = GetRandomLabel();
    // put 1 into st0 and return if necessary ...
    assembler += "fld1";
    // clean stack
    assembler += "ffree st(1)\r\n";
    assembler += "ffree st(2)\r\n";
    assembler += "jne ";
    assembler += lblEnd;
    assembler += "\r\n";
    // clean stack
    assembler += "ffree st(0)\r\n";
    // ... otherwise evaluate the next expression
    elor->expression_1->accept(this);
    assembler += lblEnd;
    assembler += ":\r\n";
}

///////////////////////////////////////////////
// ELxor : Logical exclusive or operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitELxor(ELxor* elxor)
{
}

///////////////////////////////////////////////
// ECon : Ternary conditional operator
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitECon(ECon* econ)
{
}

///////////////////////////////////////////////
// EAss : Assignment
///////////////////////////////////////////////

void FSParseTree::visitEAss(EAss* eass)
{
    /*
        evaluate the expression
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    eass->expression_->accept(this);
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(eass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(eass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// EAddAss : Addition and assignment
///////////////////////////////////////////////

void FSParseTree::visitEAddAss(EAddAss* eaddass)
{
    /*
        evaluate the expression, load the var then add it and store it back
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    eaddass->expression_->accept(this);
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(eaddass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(eaddass->ident_, 0)));
    assembler += "]\r\n";
    assembler += "faddp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(eaddass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(eaddass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// ESubAss : Subtraction and assignment
///////////////////////////////////////////////

void FSParseTree::visitESubAss(ESubAss* esubass)
{
    /*
        evaluate the expression, load the var then subtract it and store it back
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    esubass->expression_->accept(this);
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(esubass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(esubass->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fsubrp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(esubass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(esubass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// EMulAss : Multiplication and assignment
///////////////////////////////////////////////

void FSParseTree::visitEMulAss(EMulAss* emulass)
{
    /*
        evaluate the expression, load the var then multiply it and store it back
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    emulass->expression_->accept(this);
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(emulass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(emulass->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fmulp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(emulass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(emulass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// EDivAss : Division and assignment
///////////////////////////////////////////////

void FSParseTree::visitEDivAss(EDivAss* edivass)
{
    /*
        evaluate the expression, load the var then divide it and store it back
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    edivass->expression_->accept(this);
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(edivass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(edivass->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fdivrp\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(edivass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(edivass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// EModAss : Division remainder and assignment
///////////////////////////////////////////////

void FSParseTree::visitEModAss(EModAss* emodass)
{
    /*
        evaluate the expression, load the var then mod it and store it back
        store the result but don't pop, leave it in st(0) for the rest of the expression
    */
    emodass->expression_->accept(this);
    assembler += "fld [ebp+";
    assembler.AppendInt(GetVariableOffset(emodass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(emodass->ident_, 0)));
    assembler += "]\r\n";
    assembler += "fprem\r\n";
    assembler += "fst [ebp+";
    assembler.AppendInt(GetVariableOffset(emodass->ident_));
    //assembler.AppendHex(reinterpret_cast<unsigned int>(context->RegisterVariable(emodass->ident_, 0)));
    assembler += "]\r\n";
}

///////////////////////////////////////////////
// EAndAss : Bitwise and and assign
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEAndAss(EAndAss* eandass)
{
}

///////////////////////////////////////////////
// EOrAss : Bitwise inclusive or and assign
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEOrAss(EOrAss* eorass)
{
}

///////////////////////////////////////////////
// EXorAss : Bitwise exclusive or and assign
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitEXorAss(EXorAss* exorass)
{
}

///////////////////////////////////////////////
// ELShAss : Left shift bits and assign
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitELShAss(ELShAss* elshass)
{
}

///////////////////////////////////////////////
// ERShAss : Right shift bits and assign
///////////////////////////////////////////////
// N E E D S    I M P L E M E N T A T I O N
///////////////////////////////////////////////

void FSParseTree::visitERShAss(ERShAss* ershass)
{
}

///////////////////////////////////////////////
// ListExpression : List of expressions
// does nothing at the moment as function calls
// should traverse these themsevles, might need
// inclusion for for statements like:
// for(i = 0, j = 0;...;...)
///////////////////////////////////////////////

void FSParseTree::visitListExpression(ListExpression* listexpression)
{
}
