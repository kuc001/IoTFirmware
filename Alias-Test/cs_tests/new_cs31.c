#include "aliascheck.h"

struct s{
	int *a;
	int b;
};

void foo(struct s *p, struct s *q){
	int *x, *y, *z;
	x = p->a;
	y = p->a;
	z = q->a;
	MAYALIAS(x, y);
	NOALIAS(x, z);
}

int main(){

	int **a,**b,*x,*y,*m,*n;
	if(a){
		a = &x;
		b = &y;
	}
	else{
		a = &m;
		b = &n;
	}
	return 0;
}



