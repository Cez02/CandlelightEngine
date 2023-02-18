CC = g++
CFLAGS = -Wall -g -Werror

OBJS = src/main.o

all: candlelight

build: $(OBJS)
	$(CC) $(CFLAGS) -o candlelight $(OBJS)

src/main.o:
	$(MAKE) -C src/ build

clean:
	find . -name *.o -type f -delete
	rm candlelight

