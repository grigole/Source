#
# Compile hello.c under the various C stdandards
#
# Nov 13 2020 - Greg Rigole
# - created

all:	hello_c89 hello_c99 hello_c11 hello_c17
	exit;

hello_c89: hello.c
	$(CC) -o $@ -std=c89 $<

hello_c99: hello.c
	$(CC) -o $@ -std=c99 $<

hello_c11: hello.c
	$(CC) -o $@ -std=c11 $<

hello_c17: hello.c
	$(CC) -o $@ -std=c17 $<

clean:	hello_c89 hello_c99 hello_c11 hello_c17
	@rm $^
