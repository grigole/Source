with Ada.Text_IO, Ada.Integer_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO;
procedure Main is

   a : Integer := 2**8;

begin

   Put( "a = " );
   Put( a, Width => 1, Base => 10 );
   New_Line;

end Main;
