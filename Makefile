# Makefile

SDIR = src
IDIR = include
ODIR = obj

_OBJ = pwdgen.o option_processing.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -I$(IDIR)

TARGET = pwdgen

_DIST = pwdgen.tar.gz
_DISTSRC = $(SDIR)/* $(IDIR)/* Makefile README.md

.PHONY: clean dist

build: $(TARGET)
default: $(TARGET)

debug: CFLAGS +=  -O0 -g -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -fsanitize=bounds
debug: default

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS) | ODIRCREATE
	$(CC) $(CFLAGS) -c -o $@ $<

ODIRCREATE:
	@mkdir -p $(ODIR)

clean:
	rm -rf $(ODIR)/ $(SDIR)/*~ $(IDIR)/*~ $(TARGET) *~ $(_DIST)

dist:
	tar -czvf $(_DIST) $(_DISTSRC)
