#include "testManager.h"
#include "player.h"
#include <random>
//补全  构造和析构

speechmanager::speechmanager()
{
	//初始化属性
	this->initspeech();   //表明是当前对象的成员函数
	this->createplayer();
}

speechmanager::~speechmanager()
{

}


//实现菜单展示

void speechmanager::show_menu()   //都要继承
{
	cout << "************************" << endl;
	cout << "***** 欢迎参加比赛 *****" << endl;
	cout << "*****  1.开始比赛  *****" << endl;
	cout << "*****  2.查看记录  *****" << endl;
	cout << "*****  3.清空记录  *****" << endl;
	cout << "*****  0.退出程序  *****" << endl;
	cout << "************************" << endl;
	cout << endl;
}


//退出

void speechmanager::exittest()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);  //自带的  避免重名

}

//初始化
void speechmanager::initspeech() 
{
	//初始化 确保容器是空的
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_player.clear();
	//初始化比赛轮数
	this->m_index = 1;    
}
//实现创建
void speechmanager::createplayer()
{
	string nameseed = "ABCDEFGHIJKL";  //12个
	for (int i = 0; i<nameseed.size(); i++)
	{
		string name = "选手";   //局部变量name
		name += nameseed[i];   //实现 选手A 选手B

		player pl;   //创建对象
		pl.name = name;   //
		for (int i = 0; i < 2; i++)
		{
			pl.score[i] = 0;   //两轮分数都初始化为0
		}
		//选手编号
		this->v1.push_back(i + 10000);// 10000 ~ 10012

		//选手编号 以及对应选手 放到容器 
		this->m_player.insert(make_pair(i+10000,pl));  //直接放对象   作为键值k    val

	}
}


//开始比赛
void speechmanager::start()
{
	//比赛流程
	//第一轮比赛
	//抽签   实现
	draw();
	//比赛 赋分
	
	//显示晋级的结果
	
	m_index++;
	//第二轮
	//抽签
	draw();

	//比赛
	

	//显示最终结果
	//保存分数


}

//抽签    将存放选手编号的容器 m_player  打乱次序    map是有序的   放进vector中即v1 存放选手编号     两轮全部实现    如果更多轮那么m_index要++
void speechmanager::draw()
{
	cout << "第" << this->m_index << "轮比赛正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (m_index == 1) {
		//添加随机种子  每次打乱结果不一样

		//打乱
		random_shuffle(v1.begin(), v1.end());    //以上可以用 random_shuffle(v1.begin(), v1.end())代替   此种方法c14淘汰了
		for (auto it = v1.begin(); it != v1.end(); it++)   //it是迭代器
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (auto it = v2.begin(); it != v2.end(); it++)   //it是迭代器
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	system("pause");
	cout << endl;
}


//比赛及赋分