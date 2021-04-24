#include "aliascheck.h"

void foo(int **p, int **q){
	*p = *q;
}

int main(){

	int **a,**b,*x,*y,*m,*n;
	if(a){
		a = &x;
		b = &y;
		foo(a, b);
	}
	else{
		a = &m;
		b = &n;
		foo(a, b);
	}
    MAYALIAS(*a,y);
    MAYALIAS(*a,n);
}
