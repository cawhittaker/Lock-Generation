#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <fstream>


class in_locked
{
public:
	in_locked();
	~in_locked();
	void root_to_array();
	void LN0_to_array();
	void LN1_to_array();
	void LN2_to_array();
	void LN3_to_array();
	void LN4_to_array();
	void PHF_to_arr();
	void UHF_LHF_to_arr();
	void LN_S_to_char_arr(std::string x);
	void Print_root_all_LN();
	void create_range(int x);
};

