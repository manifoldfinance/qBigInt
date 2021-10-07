
#include "k.h"
#include <stdio.h>
//#include "include\gmp.h"
#include <stdlib.h>
#include <gmp.h>


/* C library for Big Interger KDB+ Arithmetic */

/* functions: add, sub, mul, div, cmp */
/* inputs: pass in x and y as strings of large numbers in base 2, 10 or 16  */
/* outputs: string number in specified base */

/* Author - Sandy Bradley  */
/* Organisation - Manifold Finance  */
/* Date - 2021-04-10  */

/* https://gmplib.org/manual/Integer-Arithmetic */
K add(K xxx, K yyy, K kbase)
{
  mpz_t x, y, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  int yyyl = yyy->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);
  char * yyss = malloc((yyyl+1) * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%c", kC(yyy)[pp]);
    yyss[pp] = kC(yyy)[pp];
  }
  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';
  yyss[yyyl]=L'\0';

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* setting the value of y in base */
  mpz_init_set_str(y, yyss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_add(z, x, y);

  /* print for debug */
  /* xss = mpz_get_str(NULL, base, x);
  yss = mpz_get_str(NULL, base, y);
  zss = mpz_get_str(NULL, base, z);
  printf("base = %i\n",base);
  printf("x = %s\ny = %s\nz = %s\n\n", xss, yss, zss);
  free(xss);
  free(yss);
  free(zss); */
  /* end debug */

  free(xxss);
  free(yyss);

  K retz = kp(mpz_get_str(NULL, base, z));

  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}

K sub(K xxx, K yyy, K kbase)
{
  mpz_t x, y, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  int yyyl = yyy->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);
  char * yyss = malloc((yyyl+1) * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%c", kC(yyy)[pp]);
    yyss[pp] = kC(yyy)[pp];
  }
  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';
  yyss[yyyl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* setting the value of y in base */
  mpz_init_set_str(y, yyss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_sub(z, x, y);

  /* print for debug */
  /* xss = mpz_get_str(NULL, base, x);
  yss = mpz_get_str(NULL, base, y);
  zss = mpz_get_str(NULL, base, z);
  printf("base = %i\n",base);
  printf("x = %s\ny = %s\nz = %s\n\n", xss, yss, zss);
  free(xss);
  free(yss);
  free(zss); */
  /* end debug */

  free(xxss);
  free(yyss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}

K mul(K xxx, K yyy, K kbase)
{
  mpz_t x, y, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  int yyyl = yyy->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);
  char * yyss = malloc((yyyl+1) * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%c", kC(yyy)[pp]);
    yyss[pp] = kC(yyy)[pp];
  }
  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';
  yyss[yyyl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* setting the value of y in base */
  mpz_init_set_str(y, yyss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_mul(z, x, y);

  /* print for debug */
  /* xss = mpz_get_str(NULL, base, x);
  yss = mpz_get_str(NULL, base, y);
  zss = mpz_get_str(NULL, base, z);
  printf("base = %i\n",base);
  printf("x = %s\ny = %s\nz = %s\n\n", xss, yss, zss);
  free(xss);
  free(yss);
  free(zss); */
  /* end debug */

  free(xxss);
  free(yyss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}

/* https://gmplib.org/manual/Integer-Division */
K divy(K xxx, K yyy, K kbase)
{
  mpz_t x, y, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  int yyyl = yyy->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);
  char * yyss = malloc((yyyl+1) * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%c", kC(yyy)[pp]);
    yyss[pp] = kC(yyy)[pp];
  }
  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';
  yyss[yyyl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* setting the value of y in base */
  mpz_init_set_str(y, yyss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  /* rounds q (z) towards zero, ignores remainder*/
  mpz_tdiv_q(z, x, y);

  /* print for debug */
  /*xss = mpz_get_str(NULL, base, x);
  yss = mpz_get_str(NULL, base, y);
  zss = mpz_get_str(NULL, base, z);
  printf("base = %i\n",base);
  printf("x = %s\ny = %s\nz = %s\n\n", xss, yss, zss);
  free(xss);
  free(yss);
  free(zss); */
  /* end debug */

  free(xxss);
  free(yyss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}

/* https://gmplib.org/manual/Integer-Comparisons */
/* returns position value if x > y; 0 if x=y and negative if x < y */
K cmp(K xxx, K yyy, K kbase)
{
  mpz_t x, y;
  int base = kbase->i;
  int xxxl = xxx->n;
  int yyyl = yyy->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);
  char * yyss = malloc((yyyl+1) * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%c", kC(yyy)[pp]);
    yyss[pp] = kC(yyy)[pp];
  }
  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';
  yyss[yyyl]=L'\0';

  int cmpy;

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* setting the value of y in base */
  mpz_init_set_str(y, yyss, base);

  /* rounds q (z) towards zero, ignores remainder*/
  cmpy = mpz_cmp(x, y);

  free(xxss);
  free(yyss);
  mpz_clear(x);
  mpz_clear(y);
  
  return ki(cmpy);
}

/* https://gmplib.org/manual/Integer-Roots */
K sqroot(K xxx, K kbase)
{
  mpz_t x, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the square root */
  mpz_sqrt(z, x);

  free(xxss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}

/* https://gmplib.org/manual/Integer-Roots */
K cuberoot(K xxx, K kbase)
{
  mpz_t x, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int xxxl = xxx->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the cube root */
  mpz_root(z, x, 3);

  free(xxss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}

/* https://gmplib.org/manual/Integer-Exponentiation */
K power(K xxx, K kbase, K kexp)
{
  mpz_t x, z;
  //char *xss, *yss, *zss;
  int base = kbase->i;
  int expo = kexp->i;
  int xxxl = xxx->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, base);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the square root */
  mpz_pow_ui(z, x, expo);

  free(xxss);

  K retz = kp(mpz_get_str(NULL, base, z));
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}


/* https://gmplib.org/manual/Converting-Integers */
K convert(K xxx, K k1base, K k2base)
{
  mpz_t x;
  int frombase = k1base->i;
  int tobase = k2base->i;
  int xxxl = xxx->n;
  char * xxss = malloc((xxxl+1) * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kC(xxx)[pp];
  }

  /* Ensure null terminated string */
  xxss[xxxl]=L'\0';

  /* setting the value of x in base */
  mpz_init_set_str(x, xxss, frombase);

  free(xxss);

  K retz = kp(mpz_get_str(NULL, tobase, x));
  mpz_clear(x);
  return retz;
}


K addRaw(K xxx, K xxl, K yyy, K yyl)
{
  mpz_t x, y, z;
  int xxxl = xxl->i;
  int yyyl = yyl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);
  unsigned char * yyss = malloc(yyyl * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%x", kG(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%x", kG(yyy)[pp]);
    yyss[pp] = kG(yyy)[pp];
  }

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* setting the value of y in base */
  mpz_init(y);
  mpz_import(y, yyyl, 1, 1, 0, 0, yyss);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_add(z, x, y);

  free(xxss);
  free(yyss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);

  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}


K subRaw(K xxx, K xxl, K yyy, K yyl)
{
  mpz_t x, y, z;
  int xxxl = xxl->i;
  int yyyl = yyl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);
  unsigned char * yyss = malloc(yyyl * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%x", kG(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%x", kG(yyy)[pp]);
    yyss[pp] = kG(yyy)[pp];
  }

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* setting the value of y in base */
  mpz_init(y);
  mpz_import(y, yyyl, 1, 1, 0, 0, yyss);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_sub(z, x, y);

  free(xxss);
  free(yyss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);

  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}

K mulRaw(K xxx, K xxl, K yyy, K yyl)
{
  mpz_t x, y, z;
  int xxxl = xxl->i;
  int yyyl = yyl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);
  unsigned char * yyss = malloc(yyyl * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%x", kG(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%x", kG(yyy)[pp]);
    yyss[pp] = kG(yyy)[pp];
  }

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* setting the value of y in base */
  mpz_init(y);
  mpz_import(y, yyyl, 1, 1, 0, 0, yyss);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_mul(z, x, y);

  free(xxss);
  free(yyss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);

  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}


K divyRaw(K xxx, K xxl, K yyy, K yyl)
{
  mpz_t x, y, z;
  int xxxl = xxl->i;
  int yyyl = yyl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);
  unsigned char * yyss = malloc(yyyl * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%x", kG(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%x", kG(yyy)[pp]);
    yyss[pp] = kG(yyy)[pp];
  }

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* setting the value of y in base */
  mpz_init(y);
  mpz_import(y, yyyl, 1, 1, 0, 0, yyss);

  /* just initalizing the result variable */
  mpz_init(z);

  mpz_tdiv_q(z, x, y);

  free(xxss);
  free(yyss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);

  mpz_clear(x);
  mpz_clear(y);
  mpz_clear(z);
  return retz;
}


K cmpRaw(K xxx, K xxl, K yyy, K yyl)
{
  mpz_t x, y;
  int xxxl = xxl->i;
  int yyyl = yyl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);
  unsigned char * yyss = malloc(yyyl * sizeof *yyss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%x", kG(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  //const char yyarr[lyy] = kp(yyy->s);
  for (int pp = 0;pp<yyyl;pp++){
    //printf("%x", kG(yyy)[pp]);
    yyss[pp] = kG(yyy)[pp];
  }

  //printf("x = %s\ny = %s\n\n", xxss, yyss);
  //printf("xt = %i\nyt = %i\n\n", xxx->t, yyy->t);

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* setting the value of y in base */
  mpz_init(y);
  mpz_import(y, yyyl, 1, 1, 0, 0, yyss);

  int cmpy = mpz_cmp(x, y);

  free(xxss);
  free(yyss);
  mpz_clear(x);
  mpz_clear(y);
  
  return ki(cmpy);
}

K sqrootRaw(K xxx, K xxl)
{
  mpz_t x, z;
  int xxxl = xxl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the square root */
  mpz_sqrt(z, x);

  free(xxss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}

K cuberootRaw(K xxx, K xxl)
{
  mpz_t x, z;
  int xxxl = xxl->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the cube root */
  mpz_root(z, x, 3);

  free(xxss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}

K powerRaw(K xxx, K xxl, K kexp)
{
  mpz_t x, z;
  int xxxl = xxl->i;
  int expo = kexp->i;
  unsigned char * xxss = malloc(xxxl * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  /* just initalizing the result variable */
  mpz_init(z);

  /* truncated integer part of the cube root */
  mpz_pow_ui(z, x, expo);

  free(xxss);

  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, z);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);
  mpz_clear(x);
  mpz_clear(z);
  return retz;
}


/* https://gmplib.org/manual/Converting-Integers */
K convertRaw(K xxx, K xxl, K k2base)
{
  mpz_t x;
  int tobase = k2base->i;
  int xxxl = xxl->i;
  unsigned char * xxss = malloc((xxxl+1) * sizeof *xxss);

  for (int pp = 0;pp<xxxl;pp++){
    //printf("%c", kC(xxx)[pp]);
    xxss[pp] = kG(xxx)[pp];
  }

  /* setting the value of x in base */
  mpz_init(x);
  mpz_import(x, xxxl, 1, 1, 0, 0, xxss);

  free(xxss);

  K retz = kp(mpz_get_str(NULL, tobase, x));
  mpz_clear(x);
  return retz;
}


/* https://gmplib.org/manual/Converting-Integers */
K convertFloatToHexStr(K xxx)
{
  mpz_t x;
  double xxxf = xxx->f;
  mpz_init_set_d(x, xxxf);
  
  K retz = kp(mpz_get_str(NULL, 16, x));
  mpz_clear(x);
  return retz;
}

/* https://gmplib.org/manual/Converting-Integers */
K convertFloatToHex(K xxx)
{
  mpz_t x;
  double xxxf = xxx->f;
  mpz_init_set_d(x, xxxf);
  
  unsigned char* buf;
	size_t len;

	buf = (unsigned char*) mpz_export(0, &len, 1, 1, 0, 0, x);

  K retz = ktn(KG,len);
  for (int pp = 0;pp<len;pp++){
    kG(retz)[pp]=buf[pp];
  }

  free(buf);
  mpz_clear(x);
  return retz;
}