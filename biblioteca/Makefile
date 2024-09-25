BINARY=biblioteca
CODEDIRS=. ./src
INCDIRS=. ./include/

CC=gcc
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD
# automatically add the -I onto each include directory
CFLAGS=-Wno-implicit-function-declaration -Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)

# for-style iteration (foreach) and regular expression completions (wildcard)
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# regular expression replacement
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY)

#  $@ = regra   $^ = dependencia
$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# only want the .c file dependency here, thus $< instead of $^
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(BINARY) $(OBJECTS) $(DEPFILES)
