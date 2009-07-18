#include "FridgeScript.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>

char test[] =
"function(x, y)\r\n"
"{\r\n"
"    return x - y;\r\n"
"}\r\n"
"\r\n"
"for( i = 0, j = 1; i < 10; ++i, j *= 2 )\r\n"
"{\r\n"
"    a = i - j;\r\n"
"}\r\n"
"\r\n"
"a = abs( a );\r\n"
"a = sin( a * pi + 2 );\r\n"
"until( a > 3 )\r\n"
"{\r\n"
"    ++a;\r\n"
"}\r\n"
"while( a < 10 )\r\n"
"{\r\n"
"    a = a * 2 + 3;\r\n"
"}\r\n"
;

double cppTest()
{
    double a, i, j;

    for( i = 0, j = 1; i < 10; ++i, j *= 2 )
    {
        a = i - j;
    }

    a = abs( a );
    a = sin( a * 3.14159265358979323 + 2 );

    while( a <= 3 )
    {
        ++a;
    }

    while( a < 10 )
    {
        a = a * 2 + 3;
    }

    return a;
}

int main(int iParameterCount, char** pszParameters)
{
    unsigned int SC = FSCreateContext();
    
    double a = 0.5;

    unsigned int CH = FSCompile(SC, test);

    if(!CH) goto end;

    unsigned int hA = FSGetVariableHandle(SC, CH, "a");
    FSSetVariableValue(hA, a);

    if(CH) FSExecute(SC, CH);

    a = FSGetVariableValue(hA);
    
    printf( "a: %.15g\r\n", a );
    printf( " = 0x%I64X\r\n", a );
    printf( "c++ test function: %.15g\r\n", cppTest() );

end:
    FSDestroyContext(SC);

    printf( "\r\n\r\n\r\n\r\nPress any key to continue...\r\n" );
    while(!_kbhit());
    return 0;
}