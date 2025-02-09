#include "testManager.h"
#include "player.h"
#include <random>
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
	for (int i = 0; i<nameseed.size(); i++)
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


//��ʼ����
void speechmanager::start()
{
	//��������
	//��һ�ֱ���
	//��ǩ   ʵ��
	draw();
	//���� ����
	concest();
	//��ʾ�����Ľ��

	m_index++;
	//�ڶ���
	//��ǩ
	draw();
	//����
	concest();

	//��ʾ���ս��
	//�������


}

//��ǩ    �����ѡ�ֱ�ŵ����� m_player  ���Ҵ���    map�������   �Ž�vector�м�v1 ���ѡ�ֱ��     ����ȫ��ʵ��    �����������ôm_indexҪ++
void speechmanager::draw()
{
	cout << "��" << this->m_index << "�ֱ������ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (m_index == 1) {
		//����������  ÿ�δ��ҽ����һ��

		//����
		random_shuffle(v1.begin(), v1.end());    //���Ͽ����� random_shuffle(v1.begin(), v1.end())����   ���ַ���c14��̭��
		for (auto it = v1.begin(); it != v1.end(); it++)   //it�ǵ�����
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (auto it = v2.begin(); it != v2.end(); it++)   //it�ǵ�����
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	system("pause");
	cout << endl;
}


//����������
void speechmanager::concest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;
	//����������� ��ѡ�ֱ��
	//map<int, int> m2;   
	multimap<double, int, greater<int>> mp;    //// �Լ�greater<int>������   ���ں�  ��Ϊ����Ĳο�    ��������       ��ʹ�õĻ�Ĭ����������
	//�����map������    ��������ͬ�ļ����������ظ��ļ���map�������ظ���key����  ������ͬ�ļ����������б������е�ֵ�� ��map�����Ѿ����ڵļ����µ�ֵ�Ḳ�Ǿɵģ� 
	 
	int num=0;//����

	vector<int> vc;    //cur����
	if (this->m_index==1)
	{
		vc = v1;   //��һ�ֽ���v1����   12��
	}
	else
	{
		vc = v2;   //6��
	}

	//����ѡ��

	//���  ÿ��ѡ�ָ���һ��������ί���������� deque     10����ί  ֮��ȥȥ�������ͷ� ��ƽ����

	//���� ��ֵ��ѡ���� �ķ�������  sm.player.score

	//����һ��   ��Ϣ������  �Ž�mp������


}
