# Introduction #

Blocks are lists of statements or lists of function definitions which make up a program in FridgeScript.


# Example #

```
// this is the start of a block

value = pi - acos( 0.75 );

// this is the end of a block and the start of another block

a(b, c)
{
  return b + c;
}

// this is the end of a block and the start of another block

sum = a( value, pi );
--sum;

// this is the end of a block and the start of another block

sqr(x)
{
  return x * x;
}

cub(x)
{
  return sqr( x ) * x;
}

// this is the end of a block and the start of another block

sum = sqr( sum );
result - cub( sum + log10( value ) );

// this is the end of a block
```