#include "testManager.h"
#include "player.h"

//��ȫ  ���������

speechmanager::speechmanager()
{
	//��ʼ������
	this->initspeech();   //�����ǵ�ǰ����ĳ�Ա����
	this->createplayer();
}

speechmanager::~speechmanager()
{

}


//ʵ�ֲ˵�չʾ

void speechmanager::show_menu()   //��Ҫ�̳�
{
	cout << "************************" << endl;
	cout << "***** ��ӭ�μӱ��� *****" << endl;
	cout << "*****  1.��ʼ����  *****" << endl;
	cout << "*****  2.�鿴��¼  *****" << endl;
	cout << "*****  3.��ռ�¼  *****" << endl;
	cout << "*****  0.�˳�����  *****" << endl;
	cout << "************************" << endl;
	cout << endl;
}


//�˳�

void speechmanager::exittest()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);  //�Դ���  ��������

}

//��ʼ��
void speechmanager::initspeech() 
{
	//��ʼ�� ȷ�������ǿյ�
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_player.clear();
	//��ʼ����������
	this->m_index = 1;
}
//ʵ�ִ���
void speechmanager::createplayer()
{
	string nameseed = "ABCDEFGHIJKL";  //12��
	for (int i = 0; i < nameseed.size(); i++)
	{
		string name = "ѡ��";   //�ֲ�����name
		name += nameseed[i];   //ʵ�� ѡ��A ѡ��B

		player pl;   //��������
		pl.name = name;   //
		for (int i = 0; i < 2; i++)
		{
			pl.score[i] = 0;   //���ַ�������ʼ��Ϊ0
		}
		//ѡ�ֱ��
		this->v1.push_back(i + 10000);// 10000 ~ 10012

		//ѡ�ֱ�� �Լ���Ӧѡ�� �ŵ����� 
		this->m_player.insert(make_pair(i+10000,pl));  //ֱ�ӷŶ���   ��Ϊ��ֵk    val

	}
}

