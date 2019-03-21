#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>




class Locks_Matrix
{
public:

	Locks_Matrix();
	Locks_Matrix(int new_root[4]);
	~Locks_Matrix();
	void Print_lock();
	int* get_root();
	int* get_CN();
	int lock[3][4];
	int S_validate();
	int Even_validate(int x[4], int y[4], int z[4], int xx[4], int yy[4]);
	int left_right_validate(int x[4], int y[4], int z[4], int xx[4], int yy[4]);
	void Print_Key(std::string *key_format);
	void Print_labled_lock0(std::string *x);
	void Print_labled_lock1(std::string *x);
	void Print_labled_lock2(std::string *x);
	void Print_labled_lock3(std::string *x);
	void Print_labled_lock4(std::string *x);
	void Print_LN0(std::string *x);
	void Print_LN1(std::string *x);
	void Print_LN2(std::string *x);
	void Print_LN3(std::string *x);
	void Print_LN4(std::string *x);
	void Read_key_file();
	void Read_locked_file();
	int key_input[4][4];
};

