CC ?= gcc
AR ?= ar
CFLAGS ?= -Wall -Wextra -std=c99 -O2
CFLAGS += -I.
ARFLAGS = rcs

PREFIX ?= /usr/local
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib

LIB_PARSE = libparsefunc.a
LIB_MATH = libmathobj.a

SRCS_PARSE = parse/parse.c parse/array.c parse/funcs.c
OBJS_PARSE = $(SRCS_PARSE:.c=.o)
DEPS_PARSE = $(OBJS_PARSE:.o=.d)

SRCS_MATH = mathobj/mathobj.c
OBJS_MATH = $(SRCS_MATH:.c=.o)
DEPS_MATH = $(OBJS_MATH:.o=.d)

LIBS = $(LIB_PARSE) $(LIB_MATH)

.PHONY: all clean install uninstall

all: $(LIBS)

$(LIB_PARSE): $(OBJS_PARSE)
	$(AR) $(ARFLAGS) $@ $^

$(LIB_MATH): $(OBJS_MATH)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS_PARSE) $(DEPS_MATH)

clean:
	rm -f $(OBJS_PARSE) $(DEPS_PARSE) $(OBJS_MATH) $(DEPS_MATH) $(LIBS)

install: $(LIBS)
	install -d $(DESTDIR)$(INCDIR)
	install -d $(DESTDIR)$(LIBDIR)
	install -m 644 parse/parsefunc.h parse/array.h parse/funcs.h mathobj/mathobj.h $(DESTDIR)$(INCDIR)/
	install -m 644 $(LIBS) $(DESTDIR)$(LIBDIR)/

uninstall:
	rm -f $(DESTDIR)$(INCDIR)/parsefunc.h $(DESTDIR)$(INCDIR)/array.h $(DESTDIR)$(INCDIR)/funcs.h $(DESTDIR)$(INCDIR)/mathobj.h
	rm -f $(DESTDIR)$(LIBDIR)/$(LIB_PARSE) $(DESTDIR)$(LIBDIR)/$(LIB_MATH)