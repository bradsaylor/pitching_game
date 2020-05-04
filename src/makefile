#taken from tutorial @ http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

IDIR =../include
CC=gcc
CFLAGS=-g -I$(IDIR)

ODIR=../obj
LDIR=../lib

LIBS=-lm


_DEPS = pitching_game.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o calcs.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) #-DENABLE_MEDIA

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	rm -f TAGS
	find . -name "*.[ch]" -print | xargs etags -a

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
