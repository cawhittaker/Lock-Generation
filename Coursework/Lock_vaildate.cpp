#include "Lock_vaildate.h"

using namespace std;

Lock_vaildate::Lock_vaildate()
{
}


Lock_vaildate::~Lock_vaildate()
{
}


int Lock_vaildate::f_validate(int array_of[4]) {

	if ((array_of[0] == array_of[1]) || (array_of[0] == array_of[2]) || (array_of[0] == array_of[3]) || (array_of[1] == array_of[2]) || (array_of[1] == array_of[3]) || (array_of[2] == array_of[3])) {
		return 1;
	}
	else {
		return 0;
	}
}


int Lock_vaildate::E_validate(int a[4], int b[4], int c[4], int d[4], int e[4]) {
	int sum;
	sum = a[0] + a[1] + a[2] + a[3] + b[0] + b[1] + b[2] + b[3] + c[0] + c[1] + c[2] + c[3] + d[0] + d[1] + d[2] + d[3] + e[0] + e[1] + e[2] + e[3];
	if ((sum % 2) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int Lock_vaildate::l_r_validate(int a[4], int b[4], int c[4], int d[4], int e[4]) {
	int asum, bsum, csum, dsum, esum;
	asum = a[0] + a[1] + a[2] + a[3];
	bsum = b[0] + b[1] + b[2] + b[3];
	csum = c[0] + c[1] + c[2] + c[3];
	dsum = d[0] + d[1] + d[2] + d[3];
	esum = e[0] + e[1] + e[2] + e[3];
	if (asum < bsum < csum <dsum < esum) {
		return 0;
	}
	else {
		return 1;
	}
}