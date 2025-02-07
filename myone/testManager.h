#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"player.h"

//管理类

class speechmanager
{
public:
	//增加几个容器
	vector<int> v1;   //12人
	vector<int> v2;   //6人
	vector<int> v3;    //胜利前三个
	//存编号 及选手的容器
	map<int, player> m_player;    //自定义选手类  map容器类似哈希表
	int m_index;

	//构造
	speechmanager();

	//菜单
	void show_menu();

	//退出功能
	void exittest();

	//开始比赛
	void initspeech();  //成员函数

	//初始化创建选手
	void createplayer();
	


	//析构
	~speechmanager();

};


//增加成员属性

