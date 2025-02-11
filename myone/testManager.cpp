#include "testManager.h"
#include "player.h"
#include <random>
#include<numeric> // accumulate
#include<fstream>
//��ȫ  ���������


speechmanager::speechmanager()
{
	//��ʼ������
	this->initspeech();   //�����ǵ�ǰ����ĳ�Ա����
	//����ѡ��
	this->createplayer();
	//��ȡ�����¼
	this->loadrecord();
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
	this->m_player.clear();  //����
	//��ʼ����������
	this->m_index = 1;
	//��ʼ����¼����
	this->record.clear();
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
	showscore();
	this->m_index++;   //���Բ���this
	//�ڶ���
	//��ǩ
	draw();
	//����
	concest();
	//��ʾ���ս��
	showscore();
	//�������
	save();
	//��ʼ������
	this->initspeech();
	this->createplayer();
	this->loadrecord();

	cout << "��������" << endl;
	system("pause");
	system("cls");

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
	cout << "------------- ��" << this->m_index << "����ʽ������ʼ��------------- " << endl;
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
	for (auto it = vc.begin(); it != vc.end(); it++)
	{
		num++;//��һ��������ʲô

		//���  ÿ��ѡ�ָ���һ��������ί���������� deque��˫�����飬���Զ�ͷ�˽��в���ɾ��������     
		deque<double> d;
		for (int i = 0; i < 10; i++)  //����ʮ��  600-1000
		{
			double score = (rand()%401+600)/10.f;//�������   /10.f ʲô����  ����10 ���ұ�֤float��
			d.push_back(score); //
		}

		//10����ί  ֮��ȥȥ�������ͷ� ��ƽ����
		sort(d.begin(), d.end(),greater<double>()); //��������
		d.pop_back();
		d.pop_front();   //ɾ��ǰ��
		double sum = accumulate(d.begin(),d.end(),0.0f) ;    //���   0.0f ������  ����λ�����ۼӵĳ�ʼֵ
		double avg = sum /(double)d.size();
		//ÿ���˵�ƽ����
		this->m_player[*it].score[this->m_index-1] = avg;   //����*it ��vc������ �����
		//m_player ��һ��map���� ��� player�࣬�Լ� ��� <int,player>
		// 
		//����һ��   ��Ϣ������  �Ž�mp������
		mp.insert(make_pair(avg, *it));//ƽ���ֺͱ��
		if (num % 6 == 0)  //6������ һ��
		{
			cout << "��" << num / 6 << "�����������" << endl;
			for (multimap<double, int, greater<int>> ::iterator it = mp.begin(); it != mp.end(); it++)
			{
				cout <<"��ţ�" << it->second <<" ������" <<this->m_player[it->second].name << "����"
					<<this->m_player[it->second].score[this->m_index-1] << endl;
			}
			//ȡǰ����
			int count = 0;
			for (auto it = mp.begin(); it != mp.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);  //����*it.second  ָ���Ǳ��  ��ǰ���ı�ŷŽ�v2�� ���� v2װ6�����
				}
				else
				{
					v3.push_back((*it).second);  //Ҳ����������
				}

			}

			mp.clear();
			cout << endl;

		}

	}
	cout << "------------- ��" << this->m_index << "�ֱ������  ------------- " << endl;
	system("pause");


}

//��ʾ���
void speechmanager::showscore()
{
	cout << "---------��" << this->m_index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int> v;
	if (this->m_index==1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}

	for (auto it = v.begin(); it != v.end();it++) //������ʤѡ�ֱ����Ϣ  
	{
		cout << "��" << this->m_index << "��" << "ѡ�ֱ�ţ�" << *it <<" ������" << this->m_player[*it].name    //ǰ������
			<<this->m_player[*it].score[this->m_index-1]<< endl;    //Ϊʲô�������ʡ��thisָ��
	}
	cout << endl;
	system("pause");
	system("cls");
	//���������ͷ��ز˵�
	this->show_menu();

}

//�����¼���ļ���  ·��Ĭ�ϵ���Debug��
void speechmanager::save()   //
{
	//�漰��д�ļ�
	ofstream ofs;
	ofs.open("game.csv", ios::out | ios::app); // ��ͣ��д�� ׷��ģʽ

	//������һ�ν����д��   ʹ��trunc��־
	//ofs.open("game.csv", ios::out | ios::trunc);
	
	//������д��ȥ  ֻд��ʤ
	for (auto it = this->v3.begin(); it != v3.end(); it++)
	{		//
		ofs << *it << "," << m_player[*it].score[1] << ",";
	}
	ofs << endl;   //����  Ҫ���ļ�����  Ҫ��Ȼ�ᵼ�����������  index��Զֻ��1

	//�ر�
	ofs.close();
	cout << "��¼�Ѿ�����" << endl;
}
 
void speechmanager::loadrecord()  //��ȡ��¼     
{
	ifstream ifs("game.csv", ios::in);   
	if (!ifs.is_open())   //�ж��Ƿ��   ����true��flase    // ʹ�� !ofs �����״̬
	{
		this->fileempty = true;
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;  //ʲô��˼������
	if (ifs.eof())   //�ж��Ƿ�����ļ�ĩβ
	{
		cout << "�ļ�Ϊ��" << endl;
		this->fileempty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileempty = false;
	ifs.putback(ch);  //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);  //���㿪ʼ�顮����
			if (pos == -1)
			{
				break;  //�Ҳ��� ��break
			}
			string tmp = data.substr(start,pos-start);//�ַ����ָ����һ��  (��ʼλ�ã�����)
			v.push_back(tmp);
			start = pos + 1;
		}
		this->record.insert(make_pair(index, v));  
		index++;
	}
	//cout <<"index=" << index << endl;   //index=1   
	ifs.close();
	//cout << "��¼�������" << endl;
	this->fileempty = false;   //��Ϊ��
}

//��ʾ�������
void speechmanager::showrecord()
{
	//����ʾ
	if (this->fileempty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//�������������   ����record.size()Ϊ1
		//cout <<"size=" << this->record.size() << endl;   
		for (auto it = record.begin(); it!=record.end();it++)  //record һ��map���� ����������� ��������
		{
			cout << "��" << (it->first)+1<< "��" <<
				" �ھ�ѡ�ֱ�ţ�" << it->second[0] << " ����:" << it->second[1] << " " <<
				" �Ǿ�ѡ�ֱ�ţ�" << it->second[2] << " ����:" << it->second[3] << " " <<
				" ����ѡ�ֱ�ţ�" << it->second[4] << " ����:" << it->second[5] << " " <<
				endl;
		}
		system("pause");
		system("cls");
	}
}


//���
void speechmanager::clearrecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		//trunc ����  ������� ɾ�����ؽ�
		ofstream ofs("game.csv", ios::trunc);
		ofs.close();
		this->initspeech();
		this->createplayer();
		this->loadrecord();

		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
