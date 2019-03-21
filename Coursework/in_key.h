#pragma once
#include <iostream>
#include <string>

class in_key
{
public:
	in_key();
	~in_key();
	void number_to_array(int a);
	void UHF_to_array();
	void LHF_to_array();
	void PHF_to_array();
	void string_to_char_arr(std::string x);
	void Fill_ikey();
	void Print_ikey();
	void set_key_to_ikey();


};

