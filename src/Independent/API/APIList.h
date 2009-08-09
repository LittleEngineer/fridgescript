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

struct APIEntry
{
    union
    {
        // we use stdcall because it requires stack cleaning by the callee
        // which is safer and helps reduce code size
        float ( FRIDGE_API * m_pfnCallback0f )();
        float ( FRIDGE_API * m_pfnCallback1f )( float );
        float ( FRIDGE_API * m_pfnCallback2f )( float, float );
        float ( FRIDGE_API * m_pfnCallback3f )( float, float, float );
        float ( FRIDGE_API * m_pfnCallback4f )( float, float, float, float );

        const void* m_pCallback;
    };

    char m_szName[64];
    unsigned int m_uNumParams;

    APIEntry() : m_pCallback( 0 ), m_uNumParams( 0 ) { m_szName[0] = 0; }
    APIEntry( const char* const szName, const void* const pCallback, const u_int uNumParams );

    APIEntry& operator =( const APIEntry& xEntry );
};

class APIList
{
    
public:

    APIList() : m_xAPIEntries() {}
    virtual ~APIList() {}

    void RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback0f )() );
    void RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback1f )( float ) );
    void RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback2f )( float, float ) );
    void RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback3f )( float, float, float ) );
    void RegisterFunction( const char* const szName, float ( FRIDGE_API * pfnCallback4f )( float, float, float, float ) );
    // void RegisterFunction( const char* const szName, void* pCallback, u_int uNumParams );

    APIEntry* FindEntry( const char* const szName );
    const APIEntry* FindEntry( const char* const szName ) const;

protected:

    Simple::Array< APIEntry > m_xAPIEntries;

};