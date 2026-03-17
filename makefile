CC = gcc
CFLAGS = -Wall -std=c99 -O2
LIB = libparsefunc.a
SRCS = parse.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $@ $^
	ranlib $@

%.o: %.c parsefunc.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

install: $(LIB)
	sudo mkdir -p /usr/local/include /usr/local/lib
	sudo cp parsefunc.h /usr/local/include/
	sudo cp $(LIB) /usr/local/lib/
	sudo ldconfig

uninstall:
	sudo rm -f /usr/local/include/parsefunc.h /usr/local/lib/$(LIB)
	sudo ldconfig
