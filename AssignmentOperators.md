# Introduction #

Assignment operators in FridgeScript allow the manipulation of values stored in variables.


# Details #

FridgeScript provides the following assignment operators, similar to C++:
  * = assignment
  * += addition and assignment
  * -= subtraction and assignment
  * `*`= multiplication and assignment
  * /= division and assignment
  * %= division remainder and assignment
  * ^= bitwise xor and assignment (not fully implemented)
  * |= bitwise or and assignment (not fully implemented)
  * &= bitwise and and assignment (not fully implemented)
  * <<= binary left shift and assignment (not fully implemented)
  * >>= binary right shift and assignment (not fully implemented)

Assignment operators differ from the other kinds in two important ways.

## Assignments are impure ##

Assignments produce side effects and so they can not always be evaluated at compile time, unlike the other operators which will provided that they have constant operands. There are some exceptions, like when the assignment is inside of a function being called with constant parameters.

## Assignments only take variables as their first parameter ##

Assignments can only take a variable for the first (left hand side) parameter, and can not modify the temporary results of an expression. This protects the user from writing code which will be necessarily slower and more confusing to read.
Consider this example:
```
// this compiles fine, every assignment has a variable for its first parameter
// this is the same as a = ( b = ( c = ( d = pi / 2 ) ) );
a = b = c = d = pi / 2;

// this generates an error because b * 2 is not a variable
// besides that, what is it meant to do?
a = b * 2 = c = d = pi / 2;
```
If the second expression was considered valid then it is not immediately obvious what it should do, and further the compiler might have to generate more code to implement whichever interpretation it decides upon.