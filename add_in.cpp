#include "add_in.h" //׷�����ݺ��� ͷ�ļ�
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addIn(double v_n,double y_n,double a_n,double n,int choice)
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
		outFile << to_string(v_n) << ','
			<< to_string(y_n) << ','
			<< to_string(a_n) << ','
			<< to_string(n) << endl;

		outFile.close();
	}
}

