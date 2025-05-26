CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -O2 -Iinclude
VERSION=1
SRC = src/uuid.c
OBJ = $(SRC:.c=.o)
TARGET = libuuid$(VERSION).a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
