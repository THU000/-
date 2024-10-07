#include "write_in.h" //����д�뺯�� ͷ�ļ�
#include "add_in.h" //׷�����ݺ��� ͷ�ļ�
#include "write_in_pro.h" //�г�������д�뺯�� ͷ�ļ�
#include "add_in_pro.h" //�г���׷�����ݺ��� ͷ�ļ�
#include "throw_0.h" //ƽ�׳���Ϊ0���� ͷ�ļ�
#include "throw_10.h" //ƽ�׳���Ϊ10���� ͷ�ļ�
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

void throw_10()
{
	//********�����˶�����ģ��********

	//�������� ���ʵ�λ��
	const double g = 9.8;  //�������ٶ�
	const double k = 1e-4; //��������ϵ��
	const double m = 1e-2; //��������
	int N = 1000;        //ִ�в��� ����Ʊ�������
	int n = 0;           //ʱ�� dt ����
	double dt = 0.5;       //ʱ�䲽�� ��λs

	//������ִ�в�����ʱ�䲽��
	cout << "����ʱ�䲽��dt���룩��" << endl;
	cin >> dt;
	cout << "����ִ�в���N��" << endl;
	cin >> N;

	//������������ ��ʼ��Ϊ0 ��̬����
	vector<double> v_x(N+10, 0); //ˮƽ�ٶ�
	vector<double> v_y(N+10, 0); //��ֱ�ٶ�
	vector<double> x(N+10, 0); //ˮƽ����
	vector<double> y(N+10, 0); //�½��߶�
	vector<double> a_x(N+10, 0); //ˮƽ���ٶ�
	vector<double> a_y(N+10, 0); //��ֱ���ٶ�

	//������ʼֵ ʱ������ n = 0
	v_x[0] = 10;
	v_y[0] = 0;
	x[0] = 0;
	y[0] = 0;
	a_x[0] = 0.01;
	a_y[0] = 9.8;

	//ѡ����ֵ����
	int choice;
	cout << "����1ѡ��Euler����������2ѡ��Euler-Cromer������" << endl;
	cin >> choice;

	//�ȼ�¼��ʼ״̬ �ٶȣ��߶ȣ����ٶȣ�����
	writeInPro(v_x[0], choice);

	switch (choice)
	{
	case 1:
		//Euler���� 
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
		cout << "Euler����������д�룡" << endl;
		break;
	case 2:
		//Euler-Cromer���� 
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
		cout << "Euler-Cromer����������д�룡" << endl;
		break;
	default:
		break;
	}
}