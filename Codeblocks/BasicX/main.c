#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

// These are glogal to simplfy draw()

Window   win;
Display *dsp;
GC       gc;

void draw( void )
{
  XDrawLine(dsp, win, gc, 10, 10,190,190); //from-to
  XDrawLine(dsp, win, gc, 10,190,190, 10); //from-to
}

int main()
{
  dsp = XOpenDisplay( NULL );

  if( !dsp )
  {
     return 1;
  }

  int screenNumber = DefaultScreen(dsp);
  unsigned long white = WhitePixel( dsp,screenNumber );
  unsigned long black = BlackPixel( dsp,screenNumber );

  win = XCreateSimpleWindow( dsp,
                             DefaultRootWindow(dsp),
                             50, 50,   // origin
                             400, 400, // size
                             0, black, // border
                             white );  // backgd

  XMapWindow( dsp, win );

  long eventMask = StructureNotifyMask;
  XSelectInput( dsp, win, eventMask );

  XEvent evt;
  do
  {
    XNextEvent( dsp, &evt );   // calls XFlush
    printf( "evt.type = %d\n", evt.type );
  }
  while( evt.type != MapNotify );
  printf( "Mapnotify received\n" );

  XGCValues values;
  values.background = white;
  values.foreground = black;

  gc = XCreateGC( dsp, win,
                     GCBackground | GCForeground,       // mask of values
                     &values );            // array of values

  draw();

  eventMask = ButtonPressMask | ButtonReleaseMask | ExposureMask;
  XSelectInput(dsp,win,eventMask); // override prev

  do
  {
    XNextEvent( dsp, &evt );   // calls XFlush()
    printf( "evt.type = %d\n", evt.type );
    if ( evt.type == Expose )
    {
      printf( "Expose received - drawing\n" );
      draw();
    }
  }
  while( evt.type != ButtonRelease );
  printf( "ButtoneRelease received\n" );

  XDestroyWindow( dsp, win );
  XCloseDisplay( dsp );

  return 0;
}
