//#include "write_in.h" //����д�뺯�� ͷ�ļ�
//#include "add_in.h" //׷�����ݺ��� ͷ�ļ�
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//
//
//int main()
//{
//	//********Euler����ģ�������˶�********
//
//	//�������� ���ʵ�λ��
//	const double g = 9.8;  //�������ٶ�
//	const double k = 1e-4; //��������ϵ��
//	const double m = 1e-2; //��������
//
//	//������������ ��ʼ��Ϊ0 ��̬����
//	vector<double> v(500, 0); //�ٶ�
//	vector<double> y(500, 0); //�½��߶�
//	vector<double> a(500, 0); //���ٶ�
//	int n = 0;        //ʱ�� dt ����
//	double dt = 0.1;    //ʱ�䲽��
//
//	//������ʼֵ ʱ������ n = 0
//	v[0] = 0;
//	y[0] = 0;
//	a[0] = g - (k / m) * v[0] * v[0];
//
//	//�ȼ�¼��ʼ״̬ �ٶȣ��߶ȣ����ٶȣ�����
//	writeIn();
//
//	int choice;
//	cout << "����1ѡ��Euler����������2ѡ��Euler-Cromer������" << endl;
//	cin >> choice;
//	switch (choice)
//	{
//	case 1:
//		//Euler���� �Ⱦ��룬���ٶȣ��ټ��ٶ�
//		for (int n = 1; n < 150; n++)
//		{
//			y[n] = y[n - 1] + v[n - 1] * dt;
//			v[n] = v[n - 1] + a[n - 1] * dt;
//			a[n] = g - (k / m) * v[n] * v[n];
//			addIn(v[n], y[n], a[n], n);
//			if (a[n - 1] >= 0 && a[n] <= 0)
//			{
//				break;
//			}
//		}
//		cout << "Euler����������д�룡" << endl;
//		break;
//	case 2:
//		//Euler-Cromer���� ���ٶȣ�����룬�ټ��ٶ�
//		for (int n = 1; n < 150; n++)
//		{
//			v[n] = v[n - 1] + a[n - 1] * dt;
//			y[n] = y[n - 1] + v[n] * dt;
//			a[n] = g - (k / m) * v[n] * v[n];
//			addIn(v[n], y[n], a[n], n);
//			if (a[n - 1] >= 0 && a[n] <= 0)
//			{
//				break;
//			}
//		}
//		cout << "Euler-Cromer����������д�룡" << endl;
//		break;
//	default:
//		break;
//	}
//
//	return 0;
//}