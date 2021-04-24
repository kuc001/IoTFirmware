/*
 * Heap
 * Author: Sen Ye
 * Date: 12/10/2013
 * Description: heap objects are identified according to their
 *		allocation sites.
 */
#include "aliascheck.h"

struct s{
	int *a;
	int b;
};

// return one malloc object
struct s * my_alloc() {
	struct s * p = (struct s *) malloc(sizeof(struct s));
	return p;
}


struct s * foo() {
	struct s * q;
	q = my_alloc();
	q->a = (int *) malloc(sizeof(int));
	q->b = 100;
	return q;
}


int main() {
	int * o1 = foo();
	int * o2 = foo();
	NOALIAS(o1, o2);
	return 0;
}
