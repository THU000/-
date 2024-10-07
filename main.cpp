#include "write_in.h" //数据写入函数 头文件
#include "add_in.h" //追加数据函数 头文件
#include "write_in_pro.h" //有初速数据写入函数 头文件
#include "add_in_pro.h" //有初速追加数据函数 头文件
#include "throw_0.h" //平抛初速为0部分 头文件
#include "throw_10.h" //平抛初速为10部分 头文件
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int xuanze;
	cout << "输入1选择初速为0平抛，或输入2选择初速为10平抛：" << endl;
	cin >> xuanze;
	if (xuanze == 1)
	{
		throw_0();
	}
	else
	{
		throw_10();
	}
	return 0;
}