all: k.h
	$(CC) bigint.c -D KXVER=3 -Wall -fno-strict-aliasing -Wno-parentheses -g -O2 -shared -fPIC -o bigint.so -lgmp

clean:
	rm -f bigint.so
