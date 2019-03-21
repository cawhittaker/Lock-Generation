#include "in_locked.h"
#include "Header.h"
#include "Lock_vaildate.h"

using namespace std;

int Root_all_LN[6][4];
int UHF_LHF[4];
int UHF_LHF_blanked[4];
int UHF_locked[4];
int LHF_locked[4];
int PHF_locked[4];
int CN0_locked[4];
int CN1_locked[4];
int CN2_locked[4];
int CN3_locked[4];
int CN4_locked[4];
char arr[4];

int min_pos(int x, int y) {
	if ((x - y) < 0) {
		return 10 + (x - y);
	}
	else {
		return (x - y);
	}
}

int add_pos(int x, int y) {
	if ((x + y) < 0) {
		return abs(x + y);
	}
	else return (x + y);
}

string n_to_string(int i) {
	if (i < 0) return to_string(i);
	else return '+' + to_string(i);
}

void Print_new_Key(std::string *key_format) {

	*key_format += "Root " + to_string(Root_all_LN[0][0]) + to_string(Root_all_LN[0][1]) + to_string(Root_all_LN[0][2]) + to_string(Root_all_LN[0][3]) + "\n";
	*key_format += "UHF " + n_to_string(UHF_locked[0]) + "," + n_to_string(UHF_locked[1]) + "," + n_to_string(UHF_locked[2]) + "," + n_to_string(UHF_locked[3]) + "\n";
	*key_format += "LHF " + n_to_string(LHF_locked[0]) + "," + n_to_string(LHF_locked[1]) + "," + n_to_string(LHF_locked[2]) + "," + n_to_string(LHF_locked[3]) + "\n";
	*key_format += "PHF " + n_to_string(PHF_locked[0]) + "," + n_to_string(PHF_locked[1]) + "," + n_to_string(PHF_locked[2]) + "," + n_to_string(PHF_locked[3]) + "\n";

}

in_locked::in_locked()
{
}


in_locked::~in_locked()
{
}

void in_locked::root_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[0][i] = (arr[i] - 48);
	}
}

void in_locked::LN0_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[1][i] = (arr[i] - 48);
	}
}

void in_locked::LN1_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[2][i] = (arr[i] - 48);
	}
}

void in_locked::LN2_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[3][i] = (arr[i] - 48);
	}
}

void in_locked::LN3_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[4][i] = (arr[i] - 48);
	}
}

void in_locked::LN4_to_array() {
	for (int i = 0; i < 4; i++) {
		Root_all_LN[5][i] = (arr[i] - 48);
	}
}

void in_locked::PHF_to_arr() {
	for (int i = 0; i < 4; i++) {
		PHF_locked[i] = min_pos((min_pos(Root_all_LN[2][i], Root_all_LN[1][i])), (UHF_LHF[i]));
	}
}

void in_locked::UHF_LHF_to_arr() {
	for (int i = 0; i < 4; i++) {
		UHF_LHF[i] = min_pos(Root_all_LN[1][i], Root_all_LN[0][i]);
	}
}

void in_locked::LN_S_to_char_arr(std::string x) {
	std::string some = x;

	int j = 0; // position in hase;
	for (int i = 0;i < some.size();i++) {

		if (some[i] < 58 && some[i]> 47)
		{
			arr[j] = (some[i]);
			j++;
		}

	}
}

void in_locked::Print_root_all_LN() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4;j++) {
			cout << Root_all_LN[i][j] << " ";
		}
		cout << "\n";
	}
}

void in_locked::create_range(int x) {


	ofstream newkeyfile;

	newkeyfile.open("Key file.txt");

	newkeyfile << "NS " << x << "\n";

	while (x < 1000000) {
		for (int i = 0; i < UHF_LHF[0] + 1; i++) {
			for (int j = 0; j < UHF_LHF[1] + 1; j++) {
				for (int k = 0; k < UHF_LHF[2] + 1; k++) {
					for (int l = 0; l < UHF_LHF[3] + 1; l++) {

						int UHF_LHF_blanked[4] = { i,j,k,l };

						UHF_locked[0] = UHF_LHF_blanked[i];
						UHF_locked[1] = UHF_LHF_blanked[j];
						UHF_locked[2] = UHF_LHF_blanked[k];
						UHF_locked[3] = UHF_LHF_blanked[l];
						LHF_locked[0] = UHF_LHF[0] - UHF_locked[0];
						LHF_locked[1] = UHF_LHF[1] - UHF_locked[1];
						LHF_locked[2] = UHF_LHF[2] - UHF_locked[2];
						LHF_locked[3] = UHF_LHF[3] - UHF_locked[3];

						for (int m = 0; m < 4; m++) {
							CN0_locked[m] = min_pos(Root_all_LN[1][m], LHF_locked[m]);
							CN1_locked[m] = min_pos(Root_all_LN[2][m], LHF_locked[m]);
							CN2_locked[m] = min_pos(Root_all_LN[3][m], LHF_locked[m]);
							CN3_locked[m] = min_pos(Root_all_LN[4][m], LHF_locked[m]);
							CN4_locked[m] = min_pos(Root_all_LN[5][m], LHF_locked[m]);
						}

						Lock_vaildate v1;



						if (v1.f_validate(CN0_locked) && v1.f_validate(CN1_locked) && v1.f_validate(CN2_locked) && v1.f_validate(CN3_locked) && v1.f_validate(CN4_locked) && v1.E_validate(CN0_locked, CN1_locked, CN2_locked, CN3_locked, CN4_locked) && v1.l_r_validate(CN0_locked, CN1_locked, CN2_locked, CN3_locked, CN4_locked) == 0)
						{

							string new_key_format;
							Print_new_Key(&new_key_format);
							newkeyfile << new_key_format.c_str();

							x = 1000001;
						}

						else {


							x++;
						}





					}
				}
			}
		}
	}

	newkeyfile.close();



}


