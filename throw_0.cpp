#include "write_in.h" //数据写入函数 头文件
#include "add_in.h" //追加数据函数 头文件
#include "write_in_pro.h" //有初速数据写入函数 头文件
#include "add_in_pro.h" //有初速追加数据函数 头文件
#include "throw_0.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void throw_0()
{
	//********Euler方法模拟落体运动********

	//常量声明 国际单位制
	const double g = 9.8;  //重力加速度
	const double k = 1e-4; //空气阻力系数
	const double m = 1e-2; //球体质量
	int N = 30;       //执行步数
	int n = 0;        //时间 dt 序数
	double dt = 2;    //时间步长

	//可输入执行步数和时间步长
	cout << "输入时间步长dt（秒）：" << endl;
	cin >> dt;
	cout << "输入执行步数N：" << endl;
	cin >> N;

	//变量数组声明 初始化为0 动态向量
	vector<double> v(N + 10, 0); //速度
	vector<double> y(N + 10, 0); //下降高度
	vector<double> a(N + 10, 0); //加速度

	//变量初始值 时间序数 n = 0
	v[0] = 0;
	y[0] = 0;
	a[0] = g - (k / m) * v[0] * v[0];

	//选择数值方法
	int choice;
	cout << "输入1选择Euler方法，或者2选择Euler-Cromer方法：" << endl;
	cin >> choice;

	//先记录初始状态 速度，高度，加速度，序数
	writeIn(v[0], choice);

	switch (choice)
	{
	case 1:
		//Euler方法 先距离，后速度，再加速度
		for (int n = 1; n < N; n++)
		{
			y[n] = y[n - 1] + v[n - 1] * dt;
			v[n] = v[n - 1] + a[n - 1] * dt;
			a[n] = g - (k / m) * v[n] * v[n];
			addIn(v[n], y[n], a[n], n,choice);
			if (a[n - 1] >= 0 && a[n] <= 0)
			{
				break;
			}
		}
		cout << "Euler方法数据已写入！" << endl;
		break;
	case 2:
		//Euler-Cromer方法 先速度，后距离，再加速度
		for (int n = 1; n < N; n++)
		{
			v[n] = v[n - 1] + a[n - 1] * dt;
			y[n] = y[n - 1] + v[n] * dt;
			a[n] = g - (k / m) * v[n] * v[n];
			addIn(v[n], y[n], a[n], n,choice);
			if (a[n - 1] >= 0 && a[n] <= 0)
			{
				break;
			}
		}
		cout << "Euler-Cromer方法数据已写入！" << endl;
		break;
	default:
		break;
	}
}