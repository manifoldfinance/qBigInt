# [`qBigInt`](#)

> a C library for Big Interger KDB+ Arithmetic


## Overview

**Function**: add, sub, mul, div, cmp

**Inputs**: pass in x and y as strings of large numbers in base 2, 10 or 16 ... 62

**Outputs**: string number in specified base

## Setup:

Install GMP library with `get_gmp.sh`

> [GMP library website](https://gmplib.org/)

Compile C bigint libraries (examples for 64 bit kdb)

- Windows dll compilation using VS: `
```bash
    cl /LD /DKXVER=3 bigint.c bigint.def q.lib -lgmp
```
- Linux so compilation using gcc: 
```bash
    gcc -D KXVER=3 -Wall -fno-strict-aliasing -Wno-parentheses -g -O2 -shared -fPIC -o bigint.so bigint.c -lgmp
```
- Mac so compilation using gcc:
```bash
    gcc -bundle -undefined dynamic_lookup bigint.c -o bigint.so -lgmp
```
## Load function in kdb

```console
bigAdd:`bigint 2:(`add;3)

bigSub:`bigint 2:(`sub;3)

bigMul:`bigint 2:(`mul;3)

bigDiv:`bigint 2:(`divy;3)

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

q)bigMul[x;y;base]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4e93f3fd41a2a2742917f00000000

"4e93f3fd41a2a2742917f00000000"

q)bigDiv[x;y;base]
base = 16
x = 4ee2d6d415b85acef8100000000
y = ff
z = 4f3208dcf2ab05d4ccdcdcdcd

"4f3208dcf2ab05d4ccdcdcdcd"

q)bigCmp[x;y;base]
3i
q)bigCmp[y;x;base]
-3i
q)bigCmp[y;y;base]
0i

```

## License
 
 Licensed under either of

 * Universal Permissive License 1.0
   ([LICENSE-UPL](LICENSE-UPL) or https://opensource.org/licenses/UPL)

 * Apache License, Version 2.0
   ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
 
 at your option.

 ### Contribution

Unless you explicitly state otherwise, any contribution intentionally submitted
for inclusion in the work by you, as defined in the Universal Permissive License v 1.0 
license, shall be dual licensed as above, without any additional terms or conditions.
