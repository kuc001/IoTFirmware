#include "aliascheck.h"

#include <stdlib.h>
#include <stdio.h>

void f(int *p, int *q) { MAYALIAS(p, q); }
void g(int *p, int *q) { MAYALIAS(p, q); }
void (*p)(int *m, int *n);

void fake_fun (void (*a)()) {
  int *m, *n, x, y;
  m = &x;
  n = &y;
  p = a;
  p(m, n);
}

void real_fun (void (*a)()) {
  int *m, *n, x, y;
  m = &x;
  n = &x;
  p = a;
  p(m, n);
}

void (*fptr)(void (*p)());

void set(void (*src)()) {
  fptr = src;
}

int main(int argc, char **argv)
{
  set(&fake_fun);
  set(&real_fun);

  fptr(&f);

  fptr(&g);

  return 0;
}
