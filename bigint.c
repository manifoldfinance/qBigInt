
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
  char *xss, *yss, *zss;
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
  char *xss, *yss, *zss;
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
  char *xss, *yss, *zss;
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
  char *xss, *yss, *zss;
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
