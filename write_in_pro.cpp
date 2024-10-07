#include "write_in_pro.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//����д�뺯��
void writeInPro(double v_0,int choice)
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
		outFile << "v_x" << ','
			<< "x" << ','
			<< "a_x" << ','
			<< "v_y" << ','
			<< "y" << ','
			<< "a_y" << ','
			<< "v" << ','
			<< "a" << ','
			<< "n" << endl;

		// ********д����������*********

		outFile << to_string(v_0) << ','
			<< "0" << ','
			<< "0.01" << ','
			<< "0" << ','
			<< "0" << ','
			<< "9.8" << ',' 
			<< "10.0" << ','
			<< "9.8509" << ','
			<< "0" <<endl;

		outFile.close();
	}

	else
	{
		cout << "�ļ��޷��򿪣�" << endl;
	}
}
