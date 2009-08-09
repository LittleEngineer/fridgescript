/*
    This file is part of FSAssembler.

    FSAssembler is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSAssembler is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FSAssembler.  If not, see <http://www.gnu.org/licenses/>
*/

#include "FSOperandVisitor.h"

#include <string.h>

///////////////////////////////////////////////
// H E L P E R    F U N C T I O N S
///////////////////////////////////////////////

///////////////////////////////////////////////
// Converts a hexadecimal string to an integer
///////////////////////////////////////////////

unsigned int ConvertHex(const char* const& str)
{
    unsigned int i = 0;
    unsigned int ret = 0x00;

    if(str[0])
    {
        // hex value
        if((str[0] == '0') && ((str[1] == 'x') || (str[1] == 'X')))
        {
            i = 2;
            while(str[i])
            {
                ret <<= 4;
                ret += str[i] - (unsigned char)'0';
                if(str[i] > '9') ret -= 7;
                ++i;
            }
        }
    }

    return ret;
}

///////////////////////////////////////////////
// R E G I S T E R S
///////////////////////////////////////////////

void FSOperandVisitor::visitREax(REax* reax)
{
    lastRegister = EAX;
}

void FSOperandVisitor::visitREcx(REcx* recx)
{
    lastRegister = ECX;
}

void FSOperandVisitor::visitREdx(REdx* redx)
{
    lastRegister = EDX;
}

void FSOperandVisitor::visitREbx(REbx* rebx)
{
    lastRegister = EBX;
}

void FSOperandVisitor::visitREsp(REsp* resp)
{
    lastRegister = ESP;
}

void FSOperandVisitor::visitREbp(REbp* rebp)
{
    lastRegister = EBP;
}

void FSOperandVisitor::visitREsi(REsi* resi)
{
    lastRegister = ESI;
}

void FSOperandVisitor::visitREdi(REdi* redi)
{
    lastRegister = EDI;
}

///////////////////////////////////////////////
// O P E R A N D    A S S E M B L E R
///////////////////////////////////////////////

///////////////////////////////////////////////
// OReg : Register
///////////////////////////////////////////////

void FSOperandVisitor::visitOReg(OReg* oreg)
{
    oreg->register_->accept(this);
    
    switch(otype)
    {
    default:
        // error
        return;
    case PUSH:
        out.Push(0x50 + static_cast<unsigned char>(lastRegister));
        break;
    case POP:
        out.Push(0x58 + static_cast<unsigned char>(lastRegister));
        break;
    }
}

///////////////////////////////////////////////
// OHex : Hexadecimal constant
///////////////////////////////////////////////

void FSOperandVisitor::visitOHex(OHex* ohex)
{
    unsigned int c = ConvertHex(ohex->hexconstant_);
    switch(otype)
    {
    default:
        // error
        return;
    case JMP:
        out.Push(c & 0xFF);
        c >>= 8;
        out.Push(c & 0xFF);
        c >>= 8;
        out.Push(c & 0xFF);
        c >>= 8;
        out.Push(c & 0xFF);
        break;
    }
}

///////////////////////////////////////////////
// OLab : Label
///////////////////////////////////////////////

void FSOperandVisitor::visitOLab(OLab* olab)
{
    // add a 32-bit zero to the output
    out.Push(0x00); out.Push(0x00); out.Push(0x00); out.Push(0x00);
    // take note of the label reference that needs to be added here
    lastLabel = olab->ident_;
}

///////////////////////////////////////////////
// OLit : Literal address (hexadecimal)
///////////////////////////////////////////////

void FSOperandVisitor::visitOLitAdd(OLitAdd* olitadd)
{
    switch(otype)
    {
    case FLD:
        out.Push(0x05);
        break;
    case FST:
        out.Push(0x15);
        break;
    case FSTP:
        out.Push(0x1D);
        break;
    default:
        // error...
        return;
    }
    
    unsigned int c = ConvertHex(olitadd->hexconstant_);
    out.Push(c & 0xFF);
    c >>= 8;
    out.Push(c & 0xFF);
    c >>= 8;
    out.Push(c & 0xFF);
    c >>= 8;
    out.Push(c & 0xFF);
}

///////////////////////////////////////////////
// ORegAdd : Register address
///////////////////////////////////////////////

void FSOperandVisitor::visitORegAdd(ORegAdd* oregadd)
{
    switch(otype)
    {
    case FILD:
    case FLD:
        out.Push(0x04);
        break;
    case FIST:
    case FST:
        out.Push(0x14);
        break;
    case FISTP:
    case FSTP:
        out.Push(0x1C);
        break;
    default:
        // error...
        return;
    }

    // parse the register
    oregadd->register_->accept(this);

    switch(lastRegister)
    {
    case ESP:
        out.Push(0x24);
        break;
    case EBP:
        out.Push(0x2C);
        break;
    }
}

///////////////////////////////////////////////
// ORelAddP : Relative address from register
// The offset is added to the address
///////////////////////////////////////////////

void FSOperandVisitor::visitORelAddP(ORelAddP* oreladdp)
{
    // parse the register
    oreladdp->register_->accept(this);

    switch(otype)
    {
    case FLD:
        out.Push(0x40 + static_cast< unsigned char >( lastRegister ) );
        break;
    case FST:
        out.Push(0x50 + static_cast< unsigned char >( lastRegister ) );
        break;
    case FSTP:
        out.Push(0x58 + static_cast< unsigned char >( lastRegister ) );
        break;
    }

    switch(lastRegister)
    {
    case ESP:
        out.Push(0x24);
        break;
    }
    

    if(oreladdp->integer_ < 0x80)
    {
        out.Push(static_cast<unsigned char>(oreladdp->integer_));
    }
    else
    {
        // error
    }
}

///////////////////////////////////////////////
// ORelAddS : Relative address from register
// The offset is subtracted from the address
///////////////////////////////////////////////

void FSOperandVisitor::visitORelAddS(ORelAddS* oreladds)
{
    // parse the register
    oreladds->register_->accept(this);

    switch(otype)
    {
    case FLD:
        out.Push(0x40 + static_cast< unsigned char >( lastRegister ) );
        break;
    case FST:
        out.Push(0x50 + static_cast< unsigned char >( lastRegister ) );
        break;
    case FSTP:
        out.Push(0x58 + static_cast< unsigned char >( lastRegister ) );
        break;
    }

    switch(lastRegister)
    {
    case ESP:
        out.Push(0x24);
        break;
    }

    if(oreladds->integer_ < 0x80)
    {
        out.Push(static_cast<unsigned char>(0x100 - oreladds->integer_));
    }
    else
    {
        // error
    }
}