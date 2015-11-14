# Introduction #

A for [loop](Loops.md) uses 3 little pieces of code together to iterate. A starting condition like `i = 0`, a test like `i < foo` and an iterator like `++i`.


# Details #

As of [revision 60](https://code.google.com/p/fridgescript/source/detail?r=60) (i.e. versions later than 0.1.0b) the first and last pieces of code can be lists of [expressions](Expression.md) separated by commas, in previous versions only single expressions are permitted. Unlike C++ all three expressions must be provided... a null expression is insufficient and will generate a compiler error.

e.g.

```
// ok
loop for( i = 0; i < limit; ++i )
{
    // ...
}


// not ok
loop for( ; i < limit; ++i )
{
    // ...
}


// ok
loop for( i = 0, j = 1; i < limit; ++i, j *= 2 )
{
    // ...
}


// not ok
loop for( i = 0, j = 1; i < limit, j < otherLimit; ++i, j *= 2 )
{
    // ...
}
```