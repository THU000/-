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

int main()
{
	int xuanze;
	cout << "����1ѡ�����Ϊ0ƽ�ף�������2ѡ�����Ϊ10ƽ�ף�" << endl;
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