CFLAGS=-Werror -Wextra -Isrc
VPATH=src/
SRC=$(wildcard src/*.c)

all: bin/nikumaru

bin/:
	mkdir -p bin/

bin/nikumaru: $(SRC) | bin/
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -r bin/

.PHONY: install
install: bin/nikumaru
	cp bin/nikumaru /usr/local/bin/nikumaru
