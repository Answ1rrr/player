#include<iostream>
using namespace std;
#include "testManager.h"  //baohan
#include<string>
#include <cstdlib> //����rand �� srand
#include<ctime>  //time



int main()
{
	srand((unsigned int)time(NULL));//�������
	//ʵ����   �������
	speechmanager sm;
	
	////����ѡ�ֳ�ʼ״̬
	//
	//for (auto it =sm.m_player.begin(); it != sm.m_player.end(); ++it)
	//{
	//	cout << "��ţ�"<<it->first << " ������" << it->second.name<<" ������" << it->second.score[0] << endl;
	//}

	//���Բ˵�
	
	//�ṩ��֧ѡ�� ��ÿ�����ܲ�ͬ�ӿ�
	int choice;   //����ѡ��
	//����Ϊʲô��һ��while   Ϊ��������ʾ�˵� ����������������  ��ν��в�ͬ�Ĳ���
	while (true)  
	{
	sm.show_menu();
	cout << "���������ѡ��" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		//��ʼ����   �����ӿ�
		sm.start();
		break;
	case 2:
	//�鿴��¼
		sm.showrecord();
		break;
	case 3:
	//��ռ�¼
		sm.clearrecord();
		break;
	case 0:
	//�˳�   �ṩ�ӿ�
		sm.exittest();
		break;

	default:
	system("cls");  //����
	break;
}
	}

	system("pause");
	return 0;
}
