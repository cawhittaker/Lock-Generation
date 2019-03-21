#include "in_key.h"
#include "Header.h"

using namespace std;

int ikey[4][4];
int root[4];
int UHF[4];
int LHF[4];
int PHF[4];
char hase[8];





in_key::in_key() {

}

in_key::~in_key()
{
}

void in_key::number_to_array(int a) {
	int x = a;


	root[3] = x % 10;
	root[2] = x / 10 % 10;
	root[1] = x / 100 % 10;
	root[0] = x / 1000 % 10;
}

void in_key::UHF_to_array() {

	if (hase[0] == 43) {
		UHF[0] = hase[1] - 48;
	}
	else if (hase[0] == 45) {
		UHF[0] = 0 - (hase[1] - 48);
	}

	if (hase[2] == 43) {
		UHF[1] = hase[3] - 48;
	}
	else if (hase[2] == 45) {
		UHF[1] = 0 - (hase[3] - 48);
	}


	if (hase[4] == 43) {
		UHF[2] = hase[5] - 48;
	}
	else if (hase[4] == 45) {
		UHF[2] = 0 - (hase[5] - 48);
	}


	if (hase[6] == 43) {
		UHF[3] = hase[7] - 48;
	}
	else if (hase[6] == 45) {
		UHF[3] = 0 - (hase[7] - 48);
	}

}

void in_key::LHF_to_array() {

	if (hase[0] == 43) {
		LHF[0] = hase[1] - 48;
	}
	else if (hase[0] == 45) {
		LHF[0] = 0 - (hase[1] - 48);
	}

	if (hase[2] == 43) {
		LHF[1] = hase[3] - 48;
	}
	else if (hase[2] == 45) {
		LHF[1] = 0 - (hase[3] - 48);
	}


	if (hase[4] == 43) {
		LHF[2] = hase[5] - 48;
	}
	else if (hase[4] == 45) {
		LHF[2] = 0 - (hase[5] - 48);
	}


	if (hase[6] == 43) {
		LHF[3] = hase[7] - 48;
	}
	else if (hase[6] == 45) {
		LHF[3] = 0 - (hase[7] - 48);
	}

}

void in_key::PHF_to_array() {

	if (hase[0] == 43) {
		PHF[0] = hase[1] - 48;
	}
	else if (hase[0] == 45) {
		PHF[0] = 0 - (hase[1] - 48);
	}

	if (hase[2] == 43) {
		PHF[1] = hase[3] - 48;
	}
	else if (hase[2] == 45) {
		PHF[1] = 0 - (hase[3] - 48);
	}


	if (hase[4] == 43) {
		PHF[2] = hase[5] - 48;
	}
	else if (hase[4] == 45) {
		PHF[2] = 0 - (hase[5] - 48);
	}


	if (hase[6] == 43) {
		PHF[3] = hase[7] - 48;
	}
	else if (hase[6] == 45) {
		PHF[3] = 0 - (hase[7] - 48);
	}

}

void in_key::string_to_char_arr(std::string x) {
	std::string some = x;

	int j = 0; // position in hase;
	for (int i = 0;i < some.size();i++) {

		if (some[i] < 58 && some[i]> 47)
		{
			hase[j] = (some[i]);
			j++;
		}

		else if (some[i] == '-')
		{
			hase[j] = some[i];
			j++;
		}
		else if (some[i] == '+')
		{
			hase[j] = some[i];
			j++;
		}
	}

}

void in_key::Fill_ikey() {

	for (int i = 0; i < 4; i++) {
		ikey[0][i] = root[i];
	}

	for (int i = 0; i < 4; i++) {
		ikey[1][i] = UHF[i];
	}

	for (int i = 0; i < 4; i++) {
		ikey[2][i] = LHF[i];
	}

	for (int i = 0; i < 4; i++) {
		ikey[3][i] = PHF[i];
	}


}

void in_key::Print_ikey() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;j++) {
			cout << ikey[i][j] << " ";
		}
		cout << "\n";
	}

}

void in_key::set_key_to_ikey() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4;j++) {
			key[i][j] = ikey[i][j];
		}
	}
}

