#pragma once

#include <iostream>

class Lock_vaildate
{
public:
	Lock_vaildate();
	~Lock_vaildate();
	int f_validate(int array_of[4]);
	int E_validate(int a[4], int b[4], int c[4], int d[4], int e[4]);
	int l_r_validate(int a[4], int b[4], int c[4], int d[4], int e[4]);
};
