/*
 * Struct assignment.
 * Author: Sen Ye
 * Date: 28/04/2014
 */
#include "aliascheck.h"

struct InnerArrayStruct {
	int* in1[10];
	int* in2[20];
	char in3;
};

struct MidArrayStruct {
	char mid1[10];
	struct InnerArrayStruct mid2[5];
};

struct ArrayStruct {
	char out2;
	struct MidArrayStruct out3;
	int* out4;
};

int main() {
	struct ArrayStruct* p;
	struct ArrayStruct s1, s2;
	int x, y, i, *m;

	s1.out4 = &x;
	p = &s1;
	p->out3.mid2[3].in1[3] = &y;

	s2 = s1;

	m = &y;

	MUSTALIAS(s2.out4, &x);

	s1.out4 = &y;

	MUSTALIAS(s2.out3.mid2[3].in1[3], m);
	MUSTALIAS(s2.out3.mid2[3].in1[3], s2.out4);
	NOALIAS(s2.out3.mid2[3].in1[20], &y);

	MAYALIAS(s2.out3.mid2[3].in1[i], &y);
	
	return 0;
}
