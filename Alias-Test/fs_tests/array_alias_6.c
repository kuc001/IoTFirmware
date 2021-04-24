/*
 * Array alias in flow-sensitive analysis.
 * Author: Sen Ye
 * Date: 08/11/2013
 */

#include "aliascheck.h"

struct MyStruct {
	int *f1;
	int *f2;
};

int main() {
	struct MyStruct s[2];
	int x, y, i, j;
	s[0].f1 = &x;
	s[1].f2 = &y;

	// Arrays are treated as a single element.
	// Different fields have its own points-to set.
	// Same fields have same points-to set, even they belong
	// to different elements.
	// NOALIAS(s[0].f1, s[0].f2);
	// NOALIAS(s[0].f1, s[1].f2);
	MAYALIAS(s[i].f1, s[j].f1);

	s[0].f1 = &y;
	MUSTALIAS(s[0].f1, s[1].f2);
	return 0;
}
