#include "Locks_Matrix.h"
#include "in_key.h"
#include "Header.h"
#include "in_locked.h"
#include "Lock_vaildate.h"


using namespace std;

int add(int x, int y) {

	if (x + y < 0) {
		return 10 - (abs(x + y) % 10);
	}

	else return ((x + y) % 10);

}

void Key_Initialize()
{


	/* root_generate */

	for (int i = 0; i<4; i++) {

		key[0][i] = rand() % 10;

	}


	/*UHF_generate*/

	for (int i = 0; i < 4; i++) {

		key[1][i] = (rand() % 19 - 9);
	}


	/*LHF_generate*/

	for (int i = 0; i < 4; i++) {

		key[2][i] = (rand() % 19 - 9);
	}


	/*PHF_generate*/

	for (int i = 0; i < 4; i++) {

		key[3][i] = (rand() % 19 - 9);
	}
}

string number_to_string(int i) {
	if (i < 0) return to_string(i);
	else return '+' + to_string(i);
}

Locks_Matrix::Locks_Matrix()
{

	for (int i = 0; i<4;i++)
		lock[0][i] = add((key[0][i]), (key[1][i]));

	for (int i = 1; i < 3;i++)
		for (int j = 0; j < 4;j++)
			lock[i][j] = add((key[i + 1][j]), (lock[i - 1][j]));

}

Locks_Matrix::Locks_Matrix(int new_root[4])
{

	for (int i = 0; i<4;i++)
		lock[0][i] = add((new_root[i]), (key[1][i]));


	for (int i = 1; i < 3;i++)
		for (int j = 0; j < 4;j++)
			lock[i][j] = add((key[i + 1][j]), (lock[i - 1][j]));

}


Locks_Matrix::~Locks_Matrix()
{
}


void Locks_Matrix::Print_lock() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4;j++) {
			cout << lock[i][j] << " ";
		}
		cout << "\n";
	}
}

int* Locks_Matrix::get_root() {
	return lock[2];
}

int* Locks_Matrix::get_CN() {
	return lock[0];
}

int Locks_Matrix::S_validate() {

	if ((lock[0][0] == lock[0][1]) || (lock[0][1] == lock[0][2]) || (lock[0][2] == lock[0][3]) || (lock[0][1] == lock[0][2]) || (lock[0][1] == lock[0][3]) || (lock[0][2] == lock[0][3])) {
		return 1;
	}
	else {
		return 0;
	}
}


int Locks_Matrix::Even_validate(int x[4], int y[4], int z[4], int xx[4], int yy[4]) {
	int sum;
	sum = x[0] + x[1] + x[2] + x[3] + y[0] + y[1] + y[2] + y[3] + z[0] + z[1] + z[2] + z[3] + xx[0] + xx[1] + xx[2] + xx[3] + yy[0] + yy[1] + yy[2] + yy[3];
	if ((sum % 2) == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int Locks_Matrix::left_right_validate(int x[4], int y[4], int z[4], int xx[4], int yy[4]) {
	int xsum, ysum, zsum, xxsum, yysum;
	xsum = x[0] + x[1] + x[2] + x[3];
	ysum = y[0] + y[1] + y[2] + y[3];
	zsum = z[0] + z[1] + z[2] + z[3];
	xxsum = xx[0] + xx[1] + xx[2] + xx[3];
	yysum = yy[0] + yy[1] + yy[2] + yy[3];
	if (xsum < ysum < zsum < xxsum < yysum) {
		return 0;
	}
	else {
		return 1;
	}
}

void Locks_Matrix::Print_Key(std::string *key_format) {

	*key_format += "Root " + to_string(key[0][0]) + to_string(key[0][1]) + to_string(key[0][2]) + to_string(key[0][3]) + "\n";
	*key_format += "UHF " + number_to_string(key[1][0]) + "," + number_to_string(key[1][1]) + "," + number_to_string(key[1][2]) + "," + number_to_string(key[1][3]) + "\n";
	*key_format += "LHF " + number_to_string(key[2][0]) + "," + number_to_string(key[2][1]) + "," + number_to_string(key[2][2]) + "," + number_to_string(key[2][3]) + "\n";
	*key_format += "PHF " + number_to_string(key[3][0]) + "," + number_to_string(key[3][1]) + "," + number_to_string(key[3][2]) + "," + number_to_string(key[3][3]) + "\n";

}

void Locks_Matrix::Print_labled_lock0(std::string *x) {

	*x = "CN0 " + to_string(lock[0][0]) + to_string(lock[0][1]) + to_string(lock[0][2]) + to_string(lock[0][3]) + " , " + "LN0 " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + " , " + "HN0 " + to_string(lock[2][0]) + to_string(lock[2][1]) + to_string(lock[2][2]) + to_string(lock[2][3]) + "\n";
}

void Locks_Matrix::Print_labled_lock1(std::string *x) {

	*x = "CN1 " + to_string(lock[0][0]) + to_string(lock[0][1]) + to_string(lock[0][2]) + to_string(lock[0][3]) + " , " + "LN1 " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + " , " + "HN1 " + to_string(lock[2][0]) + to_string(lock[2][1]) + to_string(lock[2][2]) + to_string(lock[2][3]) + "\n";
}

void Locks_Matrix::Print_labled_lock2(std::string *x) {

	*x = "CN2 " + to_string(lock[0][0]) + to_string(lock[0][1]) + to_string(lock[0][2]) + to_string(lock[0][3]) + " , " + "LN2 " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + " , " + "HN2 " + to_string(lock[2][0]) + to_string(lock[2][1]) + to_string(lock[2][2]) + to_string(lock[2][3]) + "\n";
}

void Locks_Matrix::Print_labled_lock3(std::string *x) {

	*x = "CN3 " + to_string(lock[0][0]) + to_string(lock[0][1]) + to_string(lock[0][2]) + to_string(lock[0][3]) + " , " + "LN3 " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + " , " + "HN3 " + to_string(lock[2][0]) + to_string(lock[2][1]) + to_string(lock[2][2]) + to_string(lock[2][3]) + "\n";
}

void Locks_Matrix::Print_labled_lock4(std::string *x) {

	*x = "CN4 " + to_string(lock[0][0]) + to_string(lock[0][1]) + to_string(lock[0][2]) + to_string(lock[0][3]) + " , " + "LN4 " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + " , " + "HN4 " + to_string(lock[2][0]) + to_string(lock[2][1]) + to_string(lock[2][2]) + to_string(lock[2][3]) + "\n";
}

void Locks_Matrix::Print_LN0(std::string *x) {

	*x = "Root: " + to_string(key[0][0]) + to_string(key[0][1]) + to_string(key[0][2]) + to_string(key[0][3]) + "\n";
	*x += "LN0: " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + "\n";
}

void Locks_Matrix::Print_LN1(std::string *x) {

	*x = "LN1: " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + "\n";
}

void Locks_Matrix::Print_LN2(std::string *x) {

	*x = "LN2: " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + "\n";
}

void Locks_Matrix::Print_LN3(std::string *x) {

	*x = "LN3: " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + "\n";
}

void Locks_Matrix::Print_LN4(std::string *x) {

	*x = "LN4: " + to_string(lock[1][0]) + to_string(lock[1][1]) + to_string(lock[1][2]) + to_string(lock[1][3]) + "\n";
	*x += "\n";
}

void Locks_Matrix::Read_key_file() {
	string names, UHF, LHF, PHF;
	int total;


	ifstream infile;

	infile.open("Key file.txt");

	infile >> names >> total;

	in_key i1;

	ofstream outfile;

	outfile.open("Multi-safe file.txt");

	for (int i = 1; i < (total + 1); i++) {

		int root;
		infile >> names >> root;
		i1.number_to_array(root);
		infile >> names >> UHF;
		i1.string_to_char_arr(UHF);
		i1.UHF_to_array();
		infile >> names >> LHF;
		i1.string_to_char_arr(LHF);
		i1.LHF_to_array();
		infile >> names >> PHF;
		i1.string_to_char_arr(PHF);
		i1.PHF_to_array();


		i1.Fill_ikey();
		i1.set_key_to_ikey();

		Locks_Matrix  K1 = Locks_Matrix();

		Locks_Matrix  K2(K1.get_root());

		Locks_Matrix  K3(K2.get_root());

		Locks_Matrix  K4(K3.get_root());

		Locks_Matrix  K5(K4.get_root());


		if ((K1.S_validate() == 0 && K2.S_validate() == 0 && K3.S_validate() == 0 && K4.S_validate() == 0 && K5.S_validate() == 0) && K1.Even_validate(K1.get_CN(), K2.get_CN(), K3.get_CN(), K4.get_CN(), K5.get_CN()) == 0 && K1.left_right_validate(K1.get_CN(), K2.get_CN(), K3.get_CN(), K4.get_CN(), K5.get_CN()) == 0)
		{

			std::string key_format1;
			outfile << "Valid" << "\n";
			K1.Print_labled_lock0(&key_format1);
			outfile << key_format1.c_str();
			K2.Print_labled_lock1(&key_format1);
			outfile << key_format1.c_str();
			K3.Print_labled_lock2(&key_format1);
			outfile << key_format1.c_str();
			K4.Print_labled_lock3(&key_format1);
			outfile << key_format1.c_str();
			K5.Print_labled_lock4(&key_format1);
			outfile << key_format1.c_str();

		}
		else {

			std::string key_format1;
			outfile << " Not Valid" << "\n";
			K1.Print_labled_lock0(&key_format1);
			outfile << key_format1.c_str();
			K2.Print_labled_lock1(&key_format1);
			outfile << key_format1.c_str();
			K3.Print_labled_lock2(&key_format1);
			outfile << key_format1.c_str();
			K4.Print_labled_lock3(&key_format1);
			outfile << key_format1.c_str();
			K5.Print_labled_lock4(&key_format1);
			outfile << key_format1.c_str();


		}

	}


	outfile.close();
	infile.close();
}

void Locks_Matrix::Read_locked_file() {
	string name, LN0, LN1, LN2, LN3, LN4, root;
	int total;


	ifstream lockedfile;

	lockedfile.open("locked safe file.txt");

	lockedfile >> name >> total;

	in_locked LF;



	for (int i = 0; i < (total + 1); i++) {

		lockedfile >> name >> root;
		LF.LN_S_to_char_arr(root);
		LF.root_to_array();

		lockedfile >> name >> LN0;
		LF.LN_S_to_char_arr(LN0);
		LF.LN0_to_array();

		lockedfile >> name >> LN1;
		LF.LN_S_to_char_arr(LN1);
		LF.LN1_to_array();

		lockedfile >> name >> LN2;
		LF.LN_S_to_char_arr(LN2);
		LF.LN2_to_array();

		lockedfile >> name >> LN3;
		LF.LN_S_to_char_arr(LN3);
		LF.LN3_to_array();

		lockedfile >> name >> LN4;
		LF.LN_S_to_char_arr(LN4);
		LF.LN4_to_array();

		LF.UHF_LHF_to_arr();
		LF.PHF_to_arr();

		LF.create_range(total);

	}

	lockedfile.close();
}