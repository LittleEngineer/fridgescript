# Introduction #

FridgeScript provides C++ style mathematical operators for use in its [expressions](Expression.md).


# Operators #
  * + addition
  * - subtraction
  * `*` multiplication
  * / division
  * % remainder from division
  * () brackets

# Example #
```
// this works as it does in C++, from which FridgeScript inherits its operator precedence
a = ( b + c - d ) * ( ( e / f ) % g );
```