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

void throw_10()
{
	//********抛体运动物理模拟********

	//常量声明 国际单位制
	const double g = 9.8;  //重力加速度
	const double k = 1e-4; //空气阻力系数
	const double m = 1e-2; //球体质量
	int N = 1000;        //执行步数 兼控制变量容量
	int n = 0;           //时间 dt 序数
	double dt = 0.5;       //时间步长 单位s

	//可输入执行步数和时间步长
	cout << "输入时间步长dt（秒）：" << endl;
	cin >> dt;
	cout << "输入执行步数N：" << endl;
	cin >> N;

	//变量数组声明 初始化为0 动态向量
	vector<double> v_x(N+10, 0); //水平速度
	vector<double> v_y(N+10, 0); //竖直速度
	vector<double> x(N+10, 0); //水平距离
	vector<double> y(N+10, 0); //下降高度
	vector<double> a_x(N+10, 0); //水平加速度
	vector<double> a_y(N+10, 0); //竖直加速度

	//变量初始值 时间序数 n = 0
	v_x[0] = 10;
	v_y[0] = 0;
	x[0] = 0;
	y[0] = 0;
	a_x[0] = 0.01;
	a_y[0] = 9.8;

	//选择数值方法
	int choice;
	cout << "输入1选择Euler方法，或者2选择Euler-Cromer方法：" << endl;
	cin >> choice;

	//先记录初始状态 速度，高度，加速度，序数
	writeInPro(v_x[0], choice);

	switch (choice)
	{
	case 1:
		//Euler方法 
		for (int n = 1; n < N; n++)
		{
			x[n] = x[n - 1] + v_x[n - 1] * dt;
			v_x[n] = v_x[n - 1] - a_x[n - 1] * dt;
			a_x[n] = (k / m) * v_x[n] * v_x[n];
			
			y[n] = y[n - 1] + v_y[n - 1] * dt;
			v_y[n] = v_y[n - 1] + a_y[n - 1] * dt;
			a_y[n] = g - (k / m) * v_y[n] * v_y[n];
			
			addInPro(v_x[n], x[n], a_x[n], v_y[n], y[n], a_y[n], n, choice);
			if (a_x[n - 1] >= 0 && a_x[n] <= 0 && a_y[n-1] >= 0 && a_y[n] <= 0)
			{
				break;
			}
		}
		cout << "Euler方法数据已写入！" << endl;
		break;
	case 2:
		//Euler-Cromer方法 
		for (int n = 1; n < N; n++)
		{
			v_x[n] = v_x[n - 1] - a_x[n - 1] * dt;
			x[n] = x[n - 1] + v_x[n] * dt;
			a_x[n] = (k / m) * v_x[n] * v_x[n];

			v_y[n] = v_y[n - 1] + a_y[n - 1] * dt;
			y[n] = y[n - 1] + v_y[n] * dt;
			a_y[n] = g - (k / m) * v_y[n] * v_y[n];

			addInPro(v_x[n], x[n], a_x[n], v_y[n], y[n], a_y[n], n, choice);
			if (a_x[n - 1] >= 0 && a_x[n] <= 0 && a_y[n - 1] >= 0 && a_y[n] <= 0)
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