/*
 * Simple program to test flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 12/11/2013
 */

#include "aliascheck.h"
#include <stdlib.h>

int * my_malloc(int * q) {
	int *p = malloc(*q);
	return p;
}

int main() {
	int *p1, *p2, q;
	q = 10;
	p1 = my_malloc(&q);
	q = 20;
	p2 = my_malloc(&q);
	NOALIAS(p1, p2);
	return 0;
}