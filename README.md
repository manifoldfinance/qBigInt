# qBigInt

C library for Big Interger KDB+ Arithmetic

Functions: add, sub, mul, div, cmp

Inputs: pass in x and y as strings of large numbers in base 2, 10 or 16 ... 62

Outputs: string number in specified base

## Setup:
Install GMP library with get_gmp.sh

[GMP library website](https://gmplib.org/)

Compile C bigint libraries (examples for 64 bit kdb)

- Windows dll compilation using VS: cl /LD /DKXVER=3 bigint.c bigint.def q.lib -lgmp
- Linux so compilation using gcc: gcc -D KXVER=3 -Wall -fno-strict-aliasing -Wno-parentheses -g -O2 -shared -fPIC -o bigint.so bigint.c -lgmp
- Mac so compilation using gcc: gcc -bundle -undefined dynamic_lookup bigint.c -o bigint.so -lgmp

## Load function in kdb
```
bigAdd:`bigint 2:(`add;3)

bigSub:`bigint 2:(`sub;3)

bigMul:`bigint 2:(`mul;3)

bigDiv:`bigint 2:(`div;3)

bigCmp:`bigint 2:(`cmp;3)
```

## Use in kdb

```
q)bigAdd:`bigint 2:(`add;3)
q)bigSub:`bigint 2:(`sub;3)
q)bigMul:`bigint 2:(`mul;3)
q)bigDiv:`bigint 2:(`divy;3)
q)bigCmp:`bigint 2:(`cmp;3)

q)base:16;
q)x:"4ee2d6d415b85acef8100000000";
q)y:"ff";

q)bigAdd[x;y;base]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4ee2d6d415b85acef81000000ff

"4ee2d6d415b85acef81000000ff"

q)bigSub[x;y;base]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4ee2d6d415b85acef80ffffff01

"4ee2d6d415b85acef80ffffff01"

q)bigMul[x;y;16]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4e93f3fd41a2a2742917f00000000

"4e93f3fd41a2a2742917f00000000"

q)bigDiv[x;y;16]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4f3208dcf2ab05d4ccdcdcdcd

"4f3208dcf2ab05d4ccdcdcdcd"

q)bigCmp[x;y;16]
3i
q)bigCmp[y;x;16]
-3i
q)bigCmp[y;y;16]
0i

```
