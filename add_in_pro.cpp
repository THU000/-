#include "add_in_pro.h" //׷�����ݺ��� ͷ�ļ�
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addInPro(double v_x, double x, double a_x, double v_y, double y, double a_y, double n,int choice)
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

	//���ж��ļ��Ƿ����
	ifstream file(fname);
	if (!file.is_open())
	{
		cout << "�ļ������ڻ��ߴ򲻿���" << endl;
	}
	else
	{
		file.close();//�����ȹر��ļ���ſ�д��

		ofstream outFile(fname, ios::app);

		// ********д����������*********
		outFile << to_string(v_x) << ','
			<< to_string(x) << ','
			<< to_string(a_x) << ','
			<< to_string(v_y) << ','
			<< to_string(y) << ','
			<< to_string(a_y) << ','
			<< to_string(sqrt(v_x * v_x + v_y * v_y)) << ','
			<< to_string(sqrt(a_x * a_x  + a_y * a_y)) << ','
			<< to_string(n) << endl;

		outFile.close();
	}
}

