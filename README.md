# qBigInt

C library for Big Interger KDB+ Arithmetic

Functions: add, sub, mul, div, cmp

Inputs: pass in x and y as strings of large numbers in base 2, 10 or 16

Outputs: string number in specified base

## Setup:

Compile C bigint libraries (examples)

- Windows dll compilation using VS: cl /LD /DKXVER=3 bigint.c bigint.def q.lib
- Linux so compilation using gcc: gcc -m32 -D KXVER=3 -Wall -fno-strict-aliasing -Wno-parentheses -g -O2 -shared -fPIC -o bigint.so bigint.c
- Mac so compilation using gcc: gcc -bundle -undefined dynamic_lookup bigint.c -o bigint.so

## Load function in kdb

bigAdd:`bigint 2:(`add;3)

bigSub:`bigint 2:(`sub;3)

bigMul:`bigint 2:(`mul;3)

bigDiv:`bigint 2:(`div;3)

bigCmp:`bigint 2:(`cmp;3)

## Use in kdb
