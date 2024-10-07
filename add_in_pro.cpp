#include "add_in_pro.h" //追加数据函数 头文件
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void addInPro(double v_x, double x, double a_x, double v_y, double y, double a_y, double n,int choice)
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

