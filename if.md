# Introduction #

If statements provide a branching mechanism in FridgeScript and are very similar to those found in languages like C++ and Java.


# Details #

If statements use the syntax `if` ( [Expression](Expression.md) ) { `[`[Statement](Statement.md)`]` } followed by an optional else block: `else` { `[`[Statement](Statement.md)`]` }.

# Example #
```
// is a greater than zero?
if( a > 0 )
{
  // a is greater than zero
  b = -a; // do something
}
else
{
  // a is not greater than zero
  b = 2 * a; // do something else
}
```