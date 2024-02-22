%%
[[:alpha:]_][[:alnum:]_]*		printf("%s\n", yytext);
\n│.							;	/* discard other input */
