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

#ifndef __FSAssembler_h
#define __FSAssembler_h

#define _import extern "C" unsigned int __declspec(dllexport) __stdcall
#define _importbptr extern "C" unsigned char __declspec(dllexport)* __stdcall

_importbptr FSAssemble(const char* const& source, unsigned int& length);
_import FSAFree(unsigned char* ptr);

#undef _import
#undef _importbptr

#endif