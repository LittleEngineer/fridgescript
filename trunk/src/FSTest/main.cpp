#include "FridgeScript.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>

char test[] =
"a = func( 2.0, 3.0 );\r\n"
;

static float FRIDGE_API func( float x, float y )
{
    return x / y;
}

float cppTest()
{
	return func( 2.0f, 3.0f );
}

int main(int iParameterCount, char** pszParameters)
{
    unsigned int SC = FSCreateContext();

    FSRegisterAPI2f( SC, "func", func );
    
    float a = 2;

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