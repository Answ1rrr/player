#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"player.h"

//������

class speechmanager
{
public:
	//���Ӽ�������
	vector<int> v1;   //12��
	vector<int> v2;   //6��
	vector<int> v3;    //ʤ��ǰ����
	//���� ��ѡ�ֵ�����
	map<int, player> m_player;    //�Զ���ѡ����  map�������ƹ�ϣ��
	int m_index;

	//����
	speechmanager();

	//�˵�
	void show_menu();

	//�˳�����
	void exittest();

	//��ʼ����
	void initspeech();  //��Ա����

	//��ʼ������ѡ��
	void createplayer();
	


	//����
	~speechmanager();

};


//���ӳ�Ա����

