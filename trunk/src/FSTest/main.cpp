#include "FridgeScript.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>

char test[] =
"a = func( 2.0, 3.0, 1.0, 4.0, 5.0, 6.0 );\r\n"
;

static float FRIDGE_API func( float x, float y, float a, float b, float s, float t )
{
    return x / y + a / b + s / t;
}

float cppTest()
{
	return func( 2.0f, 3.0f, 1.0f, 4.0f, 5.0f, 6.0f );
}

int main(int iParameterCount, char** pszParameters)
{
    unsigned int SC = FSCreateContext();

    FSRegisterAPI( SC, "func", func, 6 );
    
    float a = 0.0f;

    unsigned int CH = FSCompile(SC, test);

    if( !CH ) goto end;

    unsigned int hA = FSGetVariableHandle( SC, CH, "a" );
    FSSetVariableValue( hA, a );

    if( CH ) FSExecute( SC, CH ) ;

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