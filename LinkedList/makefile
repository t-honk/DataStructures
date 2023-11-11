SHELL = /bin/sh
CC = gcc
CFLAGS = -O3 -Wall -I$(SRCDIR)/include
SRCDIR = ./src
BUILDDIR = build
BINDIR = bin
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SOURCES))
RM = rm -f

.PHONY: all windows linux clean

all: windows

directories:
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BINDIR)

$(BUILDDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

windows: directories $(BINDIR)/LinkedList.exe

$(BINDIR)/LinkedList.exe: $(OBJECTS)
	$(CC) -o $@ $^

linux: directories $(BINDIR)/LinkedList-linux

$(BINDIR)/LinkedList-linux: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	$(RM) -r $(BUILDDIR) $(BINDIR)