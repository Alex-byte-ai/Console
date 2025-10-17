#include "Exception.h"
#include "Console.h"
#include "Window.h"

#include <string>
#include <vector>

int wmain( int argc, wchar_t *argv[] );

int wmain( int argc, wchar_t *argv[] )
{
    try
    {
        Console console;

        // Argument #0 is a path to this app, it seems to be relative.
        for( int i = 1; i < argc; ++i )
            console.command( argv[i] );

        console.run();
    }
    catch( const Exception &e )
    {
        Popup( Popup::Type::Error, L"Error", e.message() ).run();
    }
    catch( const std::exception &e )
    {
        Popup( Popup::Type::Error, L"Error", Exception::extract( e.what() ) ).run();
    }
    catch( ... )
    {
        Popup( Popup::Type::Error, L"Error", L"Program failed!" ).run();
    }

    return 0;
}
