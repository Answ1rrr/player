#include<iostream>
using namespace std;
#include "testManager.h"  //baohan
#include<string>




int main()
{
	//实例类   管理对象
	speechmanager sm;
	
	////测试选手初始状态
	//
	//for (auto it =sm.m_player.begin(); it != sm.m_player.end(); ++it)
	//{
	//	cout << "序号："<<it->first << " 姓名：" << it->second.name<<" 分数：" << it->second.score[0] << endl;
	//}

	//测试菜单
	


	//提供分支选择 ，每个功能不同接口
	int choice;   //定义选择
	//这里为什么套一个while   为了重新显示菜单 不用重新启动程序  多次进行不同的操作
	while (true)  
	{
	sm.show_menu();
	cout << "请输入你的选择：" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		//开始比赛   比赛接口
		sm.start();
		break;
	case 2:
	//查看记录

		break;
	case 3:
	//清空记录

		break;
	case 0:
	//退出   提供接口
		sm.exittest();
		break;

	default:
	system("cls");  //清屏
	break;
}
	}


	

	system("pause");
	return 0;
}
