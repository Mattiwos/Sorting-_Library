CC = clang
CFLAGS = -Wall -Wextra -Werror -Wpedantic -g

SOURCE = $(wildcard *.c)
OBJECT = $(wildcard *.o)
EXEC = sorting

all: $(EXEC)

$(EXEC): sorting.o bubble.o shell.o quick.o stack.o set.o stats.o queue.o
	$(CC) -o $(EXEC) sorting.o bubble.o shell.o quick.o stack.o set.o stats.o queue.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<



clean:
	rm -f $(OBJECT)

scan-build: clean
	scan-build make
format:
	clang-format -i -style=file *.c *.h
