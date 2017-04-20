# make sure to use \t instead of spaces
# set the name of the project
PROG_NAME = singly_list

# set the compiler
CC = gcc

# set the compiler flags
CFLAGS = -Wall

# set the output object files directory
ODIR = obj

# set external libraries directory
LDIR = ../lib

# link the libraries (e.g. -lm for math.h)
LIBS = -lm

# set dependencies (e.g. util.h)
DEPS = list.h

# set expected object files (e.g. main.o util.o (from main.c and util.c))
_OBJ = main.o list.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# compile to object files
$(ODIR)/%.o : %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

# link the object files in an executable
all : $(OBJ)
	$(CC) -o $(PROG_NAME) $^ $(CFLAGS) $(LIBS)

.PHONY: clean

# clean up after you're done
clean :
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
