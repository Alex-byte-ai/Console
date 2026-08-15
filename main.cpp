#include "CommandLineArguments.h"
#include "Exception.h"
#include "Console.h"
#include "Window.h"

#include "RandomNumber.h"

#include <string>
#include <vector>

#include <stack>

int main()
{
    try
    {
        Console console;

        // Argument #0 is a path to this application.
        auto arguments = commandLineArguments();
        for( size_t i = 1; i < arguments.size(); ++i )
            console.command( arguments[i] );

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
