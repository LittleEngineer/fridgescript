# Introduction #

FridgeScript is the name of a scripting language as well as a compiler library which currently generates byte-code for Intel x86 compatible CPUs running under Windows.


# Language #
_see [LanguageFeatures](LanguageFeatures.md)_

The FridgeScript language is loosely based on evallib, the scripting language and library used for Winamp AVS and SPS. It has a C-style syntax and supports C-like conditional statements, loops and function calls.

One aim of FridgeScript is to provide sufficient functionality to replicate any program that can be produced with evallib, whilst extending that functionality further with the aim of improving code readability, speed of execution and ease of use.

Functions like band(x, y) in evallib are replaced with C++ like operators like && in FridgeScript. There is no need for functions like exec2(x, y) since branches and loops are implemented like C++ with braces containing multiple statements separated by semicolons. Although the syntax is more C++ like FridgeScript lacks all of the advanced functionality like templates, pointers and classes, although this may change in future versions of the language.


# Compiler #

The FridgeScript compiler is an LGPL library for handling the compiling and execution of FridgeScript source code provided as a null-terminated ANSI string.