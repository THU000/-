#include "write_in.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//����д�뺯��
void writeIn(double v_0, int choice)
{
	string fname;
	if (choice == 1)
	{
		fname = "Euler����.csv";
	}
	else
	{
		fname = "Euler_Cromer����.csv";
	}

	ofstream outFile(fname, ios::out);

	if (outFile.is_open())  // ����ļ��Ƿ�򿪳ɹ�
	{
		// д�������
		outFile << "v" << ','
			<< "y" << ','
			<< "a" << ','
			<< "n" << endl;

		// ********д����������*********

		outFile << to_string(v_0) << ','
			<< "0" << ','
			<< "9.8" << ','
			<< "0" << endl;

		outFile.close();
	}

	else
	{
		cout << "�ļ��޷��򿪣�" << endl;
	}
}
