#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Locks_Matrix.h"
#include "in_key.h"
#include <fstream>
#include "Header.h"
#include "in_locked.h"


using namespace std;

int key[4][4];

void root_generate() {

	for (int i = 0; i<4; i++) {

		key[0][i] = rand() % 10;

	}
}

void UHF_generate()
{
	for (int i = 0; i < 4; i++) {

		key[1][i] = (rand() % 19 - 9);
	}
}

void LHF_generate()
{
	for (int i = 0; i < 4; i++) {

		key[2][i] = (rand() % 19 - 9);
	}
}

void PHF_generate()
{
	for (int i = 0; i < 4; i++) {

		key[3][i] = (rand() % 19 - 9);
	}
}


int main() {
	srand(time(NULL));

	UHF_generate();
	LHF_generate();
	PHF_generate();

	ofstream keyfile;
	keyfile.open("Key file.txt");

	cout << "Welcome to Safe Maker 3000 " << "\n" << "\n";
	cout << "Press 0 for single locks" << "\n" << "Press 1 for multi locks" << "\n" << "Press 2 to input a key file" << "\n" << "Press 3 to input a locked safe file" << "\n";
	int x, b;
	cin >> x;

	if (x == 0) {

		ofstream safefile;
		safefile.open("S_safes.txt");

		cout << "How many locks would you like to make?" << "\n";
		int y;
		cin >> y;
		b = y;

		keyfile << "NS " << y << "\n";


		for (int i = 0; i < b; i++) {

			root_generate();

			Locks_Matrix  K1 = Locks_Matrix();

			if (K1.S_validate() == 0) {


				std::string key_format;
				std::string lock_format;
				K1.Print_Key(&key_format);
				keyfile << key_format.c_str() << "\n";
				K1.Print_labled_lock0(&lock_format);
				safefile << "Lock Number " << (i + 1) << "\n";
				safefile << lock_format.c_str() << "\n";

				b = b;
			}
			else {
				b = b + 1;
			}

		}
		keyfile.close();
		safefile.close();
	}

	else if (x == 1)
	{
		ofstream lockedfile;
		lockedfile.open("locked safe file.txt");



		cout << "How many valid multi locks would you like to make?" << "\n";
		int y, a;
		cin >> y;
		a = y;

		keyfile << "NS " << y << "\n";
		lockedfile << "NS " << y << "\n";

		for (int i = 0; i < a; i++) {


			root_generate();

			Locks_Matrix  K1 = Locks_Matrix();

			Locks_Matrix  K2(K1.get_root());

			Locks_Matrix  K3(K2.get_root());

			Locks_Matrix  K4(K3.get_root());

			Locks_Matrix  K5(K4.get_root());


			if ((K1.S_validate() == 0 && K2.S_validate() == 0 && K3.S_validate() == 0 && K4.S_validate() == 0 && K5.S_validate() == 0) && K1.Even_validate(K1.get_CN(), K2.get_CN(), K3.get_CN(), K4.get_CN(), K5.get_CN()) == 0 && K1.left_right_validate(K1.get_CN(), K2.get_CN(), K3.get_CN(), K4.get_CN(), K5.get_CN()) == 0)
			{
				a = a;

				std::string key_format1;
				std::string LN_format;
				K1.Print_Key(&key_format1);
				keyfile << key_format1.c_str();
				K1.Print_LN0(&LN_format);
				lockedfile << LN_format.c_str();
				K2.Print_LN1(&LN_format);
				lockedfile << LN_format.c_str();
				K3.Print_LN2(&LN_format);
				lockedfile << LN_format.c_str();
				K4.Print_LN3(&LN_format);
				lockedfile << LN_format.c_str();
				K5.Print_LN4(&LN_format);
				lockedfile << LN_format.c_str();
			}
			else {

				a = a + 1;
			}

		}
		keyfile.close();
		lockedfile.close();

		cout << "Would you like to input the key file y/n?" << "\n";
		char w;
		cin >> w;
		if (w == 121) {
			goto in_keyed;
		}
		else {
			goto end;
		}
	}

	else if (x == 2) {
	in_keyed:
		Locks_Matrix R1 = Locks_Matrix();

		R1.Read_key_file();

	}

	else if (x == 3) {

		Locks_Matrix R2 = Locks_Matrix();

		R2.Read_locked_file();

		cout << "Would you like to input new key file?" << "\n";
		char q;
		cin >> q;
		if (q == 121) {
			goto in_keyed;
		}
		else {
			goto end;
		}
	}


end:
	cout << "Thank you for using Safe Maker 3000 " << "\n" << "\n" << "Please open up Key file, muti-safe file and locked safe text files for your unique Muti-safe solutions" << "\n" << "\n" << "Or open up Key file and S_safes, text files for you unique single lock solution" << "\n";

	system("pause");
	return 0;
}

