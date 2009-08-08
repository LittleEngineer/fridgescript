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

float cppTest()
{
    float a, i, j;

    for( i = 0, j = 1; i < 10.0f; ++i, j *= 2.0f )
    {
        a = i - j;
    }

    a = abs( a );
    a = sin( a * 3.14159265358979323f + 2.0f );

    while( a <= 3.0f )
    {
        ++a;
    }

    while( a < 10.0f )
    {
        a = a * 2.0f + 3.0f;
    }

    return a;
}

int main(int iParameterCount, char** pszParameters)
{
    unsigned int SC = FSCreateContext();
    
    float a = 0.5f;

    unsigned int CH = FSCompile(SC, test);

    if( !CH ) goto end;

    unsigned int hA = FSGetVariableHandle( SC, CH, "a" );
    FSSetVariableValue( hA, a );

    if( CH ) FSExecute( SC, CH) ;

    a = FSGetVariableValue( hA );
    
    printf( "a: %.15f\r\n", a );
    printf( " = 0x%X\r\n", *reinterpret_cast< unsigned int* >( &a ) );
    printf( "c++ test function: %.15f\r\n", cppTest() );

end:
    FSDestroyContext( SC );

    printf( "\r\n\r\n\r\n\r\nPress any key to continue...\r\n" );
    while( !_kbhit() );
    return 0;
}