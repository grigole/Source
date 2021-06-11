#include <string>
#include <map>
#include "bison.h"

class KaleidDriver;

//Tell Flex the lexer's prototype ...
#define YY_DECL \
  yy::KaleidDriver::symbol_type yylex (KaleidDriver& driver)
// ... and declare it for the parser's sake.
YY_DECL;

//Scans and parses Stone
class KaleidDriver
{
   public:
      //Constructor
      KaleidDriver();

      //Destructor
      virtual ~KaleidDriver();

  std::map<std::string, int> variables;

  int result;
  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;
  // Run the parser on file F.
  // Return 0 on success.
  int parse (const std::string& f);
  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  std::string file;
  // Whether parser traces should be generated.
  bool trace_parsing;
  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);
};//KaleidDriver

#endif