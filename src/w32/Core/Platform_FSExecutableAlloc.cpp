#include <windows.h>

unsigned char* Platform_FSExecutableAlloc( unsigned char* pcPointer, unsigned int uSize )
{
    return static_cast<unsigned char*>( VirtualAlloc( pcPointer, uSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) );
}

void Platform_FSExecutableFree( unsigned char* pcPointer, unsigned int uSize )
{
    VirtualFree( pcPointer, uSize, MEM_RELEASE );
}