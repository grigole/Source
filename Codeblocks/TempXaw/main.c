#include <stdio.h>
#include <stdlib.h>

#include <X11/StringDefs.h>
#include <X11/Intrinsic.h>
#include <X11/Xaw/Command.h>
//#include <X11/Xaw/Form.h>

void quit( Widget w, XtPointer client, XtPointer call )
{
   exit(0);
}

int main( int argc, char** argv )
{
    Widget toplevel;
    Widget command;

    toplevel = XtInitialize( argv[0], "Temp Converter", NULL, 0,
                            &argc, argv );

    command = XtCreateManagedWidget( "press and die",
                commandWidgetClass, toplevel, NULL, 0 );

    XtAddCallback( command, XtNcallback, quit, NULL );

    XtRealizeWidget( toplevel );

    XtMainLoop();

    return 0;
}
