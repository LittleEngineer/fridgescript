# Introduction #

Expressions are the primary means of programming in FridgeScript.


# Details #

An expression contains variables, operators and function calls in a similar manner to languages like C++ and Java. The exact combinations permitted can be found in the [grammar](Grammar.md) for FridgeScript, although some simple examples are enough to get started.

# Examples #
```
// this function definition is not an expression
sqr(a)
{
  // this return statement is not an expression, but it does contain an expression
  return a * a;
}

// this assignment is an expression
a = cos( pi / 7 ) - 0.5;

// this if statement is not an expression, but the conditional it uses is
if ( b > 2 )
{
  // this multiply with assignment is an expression
  a *= sqr( b );

  // this bitwise operation is also an expression
  a = b | c;
}

// expressions can contain any of the different sorts of operators as long as the assignment operators are only used on variables
a ^= ( b && ( a == 0 ) ) ? 1 : 2;

// this generates a compiler error
(b + 1) += a;

// this does not generate an error, since each operand is just a variable, and not a generic expression
a = b = c = d;
```