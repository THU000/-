#include "add_in.h" //追加数据函数 头文件
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addIn(double v_n,double y_n,double a_n,double n,int choice)
{
	string fname;
	if (choice == 1)
	{
		fname = "Euler方法.csv";
	}
	else
	{
		fname = "Euler_Cromer方法.csv";
	}

	//先判断文件是否存在
	ifstream file(fname);
	if (!file.is_open()) 
	{
		cout << "文件不存在或者打不开！" << endl;
	}
	else 
	{
		file.close();//必须先关闭文件后才可写入

		ofstream outFile(fname, ios::app);

		// ********写入两行数据*********
		outFile << to_string(v_n) << ','
			<< to_string(y_n) << ','
			<< to_string(a_n) << ','
			<< to_string(n) << endl;

		outFile.close();
	}
}

