/*
 ============================================================================
 Name        : Motif.c
 Author      : Greg Rigole
 Version     :
 Copyright   : Copyright (c) 2019 - GVR Software Solutions Inc.
 Description : Sample X/Motif Program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* General header for the motif library */
#include <Xm/Xm.h>

/* Header for the Push Button Widget */
#include <Xm/PushB.h>

/* Prototype Callback function */
void pushedButton ( Widget , XtPointer , XtPointer );

/* Main function */
int main( int argc, char **argv )
{
   Widget topWidget, button;

   XtAppContext  app;
   topWidget = XtVaAppInitialize( &app,
     "Push", NULL, 0, &argc, argv, NULL, NULL );

   button = XmCreatePushButton( topWidget,
     "Hello World! Push me!", NULL, 0 );

   /* tell Xt to manage button */
   XtManageChild( button );

   /* Add a callback to the button widget */
   XtAddCallback( button, XmNactivateCallback,
      &pushedButton, NULL );

   XtRealizeWidget( topWidget ); /* display widget hierarchy */

   /* enter processing loop */
   XtAppMainLoop( app );
}

void pushedButton (Widget w, XtPointer client_data, XtPointer cbs)
{
    printf("Hello to you too!\n");
}
