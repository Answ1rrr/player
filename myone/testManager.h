#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"player.h"
#include<deque>
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
	int m_index;   //��¼�ڼ��ֱ���

	//����
	speechmanager();

	//�˵�
	void show_menu();

	//�˳�����
	void exittest();

	//��ʼ��ʼ������
	void initspeech();  //��Ա����

	//��ʼ������ѡ��
	void createplayer();
	
	//��ʼ����
	void start();

	//��ǩ
	void draw();

	//��������
	void concest();

	//��ʾ�������
	void showscore();

	//�������
	void save();

	//�鿴��¼ ����3
	void loadrecord();
	bool fileempty;   
	map<int, vector<string>> record;                //�����¼
	
	void showrecord();

	//��ռ�¼ ����4
	void clearrecord();
	
	//����
	~speechmanager();

};


//���ӳ�Ա����

