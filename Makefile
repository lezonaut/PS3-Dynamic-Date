CC = clang
CFLAGS = -Wall -Wextra -O2 -Iinclude
TARGET = date_test
SOURCES = src/main.c src/clock.c

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
