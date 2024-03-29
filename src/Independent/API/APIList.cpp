/*
    This file is part of FridgeScript.

    FridgeScript is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FridgeScript is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FridgeScript.  If not, see <http://www.gnu.org/licenses/>
*/

// main header
#include <Core/FridgeScript.h>

// This file's header
#include <API/APIList.h>

// C/C++ headers
#include <string.h>

APIEntry::APIEntry( const char* const szName, const void* const pCallback, const u_int uNumParams )
: m_pCallback( pCallback )
, m_uNumParams( uNumParams )
, m_pIndirectCaller( NULL )
{
    strcpy_s( m_szName, 64, szName );
}

APIList::~APIList()
{
    for( u_int u = 0; u < m_xAPIEntries.GetCount(); ++u )
    {
        delete m_xIndirectReferences[ u ];
    }
}

APIEntry& APIEntry::operator =( const APIEntry& xEntry )
{
    m_pCallback = xEntry.m_pCallback;
    m_uNumParams = xEntry.m_uNumParams;
    strcpy_s( m_szName, 64, xEntry.m_szName );

    return *this;
}

void APIList::RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback0f)() )
{
    m_xAPIEntries.Append( APIEntry( szName, pfnCallback0f, 0 ) );
    m_xIndirectReferences.Append( new void*( pfnCallback0f ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

void APIList::RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback1f )( float ) )
{
    m_xAPIEntries.Append( APIEntry( szName, pfnCallback1f, 1 ) );
    m_xIndirectReferences.Append( new void*( pfnCallback1f ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

void APIList::RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback2f )( float, float ) )
{
    m_xAPIEntries.Append( APIEntry( szName, pfnCallback2f, 2 ) );
    m_xIndirectReferences.Append( new void*( pfnCallback2f ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

void APIList::RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback3f )( float, float, float ) )
{
    m_xAPIEntries.Append( APIEntry( szName, pfnCallback3f, 3 ) );
    m_xIndirectReferences.Append( new void*( pfnCallback3f ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

void APIList::RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback4f )( float, float, float, float ) )
{
    m_xAPIEntries.Append( APIEntry( szName, pfnCallback4f, 4 ) );
    m_xIndirectReferences.Append( new void*( pfnCallback4f ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

void APIList::RegisterFunction( const char* const szName, void* pCallback, u_int uNumParams )
{
    m_xAPIEntries.Append( APIEntry( szName, pCallback, uNumParams ) );
    m_xIndirectReferences.Append( new void*( pCallback ) );
    m_xAPIEntries.End().m_pIndirectCaller = m_xIndirectReferences.End();
}

APIEntry* APIList::FindEntry( const char* const szName )
{
    for( u_int u = 0; u < m_xAPIEntries.GetCount(); ++u )
    {
        if( !strcmp( m_xAPIEntries[ u ].m_szName, szName ) )
        {
            return &( m_xAPIEntries[ u ] );
        }
    }

    return NULL;
}

const APIEntry* APIList::FindEntry( const char* const szName ) const
{
    for( u_int u = 0; u < m_xAPIEntries.GetCount(); ++u )
    {
        if( !strcmp( m_xAPIEntries[ u ].m_szName, szName ) )
        {
            return &( m_xAPIEntries[ u ] );
        }
    }

    return NULL;
}
