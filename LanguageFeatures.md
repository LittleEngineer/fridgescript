# Introduction #

This page describes the FridgeScript language itself, rather than the details of the compiler implementation provided.


# Details #

There are several aspects to the language of FridgeScript:

## Grammar ##

The [grammar](Grammar.md) is documented on the wiki, but the exact LBNF (labelled Backus-Naur form) grammar used for FridgeScript can be found in FridgeScript.cf in the source.

## Functionality ##
  * [Mathematical operators](MathOperators.md)
  * [Assignment operators](AssignmentOperators.md)
  * [Logical operators](LogicalOperators.md)
  * [Bitwise operators](BitwiseOperators.md) (not fully implemented)
  * [Built-in mathematical functions](MathFunctions.md)
  * [If statements](if.md)
  * [While](while.md), [until](until.md) and [for](for.md) loops
  * [User-defined functions](Function.md) and function calls from within expressions (not fully implemented)

## Concepts ##
  * [Expression evaluation](Expression.md)
  * [Branching](if.md)
  * [Loops](Loops.md)
  * [Functions](Function.md) (not fully implemented)
  * [Lazy evaluation](LazyEvaluation.md) (not fully implemented)
  * [Constant expression](ConstantExpressions.md) evaluation at compile-time (not fully implemented)
  * Symbolic optimisation and out-of-order execution (not fully implemented)