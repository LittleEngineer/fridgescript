# Introduction #

An until [loop](Loops.md) runs until a test succeeds.


# Details #

Until loops run until their condition, defined by an [expression](Expression.md), evaluates to a non-zero value. Although they enclose code with what looks like a C++ style scope, this simply acts to contain code and doesn't clean up variables at its end.

# Example #

```
i = 0;

loop until( i >= 10 )
{
    ++i;
    j = i + 1;
}

// i == 10
// j == 11 and can be accessed and altered here:
++j;
// j == 12
```