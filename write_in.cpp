#include "write_in.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//数据写入函数
void writeIn(double v_0, int choice)
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

	ofstream outFile(fname, ios::out);

	if (outFile.is_open())  // 检查文件是否打开成功
	{
		// 写入标题行
		outFile << "v" << ','
			<< "y" << ','
			<< "a" << ','
			<< "n" << endl;

		// ********写入两行数据*********

		outFile << to_string(v_0) << ','
			<< "0" << ','
			<< "9.8" << ','
			<< "0" << endl;

		outFile.close();
	}

	else
	{
		cout << "文件无法打开！" << endl;
	}
}
