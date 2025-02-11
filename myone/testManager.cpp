#include "testManager.h"
#include "player.h"
#include <random>
#include<numeric> // accumulate
#include<fstream>
//补全  构造和析构


speechmanager::speechmanager()
{
	//初始化属性
	this->initspeech();   //表明是当前对象的成员函数
	//创建选手
	this->createplayer();
	//获取往届记录
	this->loadrecord();
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
	this->m_player.clear();  //容器
	//初始化比赛轮数
	this->m_index = 1;
	//初始化记录容器
	this->record.clear();
}
//实现创建
void speechmanager::createplayer()
{
	string nameseed = "ABCDEFGHIJKL";  //12个
	for (int i = 0; i < nameseed.size(); i++)
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
	concest();
	//显示晋级的结果
	showscore();
	this->m_index++;   //可以不用this
	//第二轮
	//抽签
	draw();
	//比赛
	concest();
	//显示最终结果
	showscore();
	//保存分数
	save();
	//初始化属性
	this->initspeech();
	this->createplayer();
	this->loadrecord();

	cout << "比赛结束" << endl;
	system("pause");
	system("cls");

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
void speechmanager::concest()
{
	cout << "------------- 第" << this->m_index << "轮正式比赛开始：------------- " << endl;
	//容器保存分数 和选手编号
	//map<int, int> m2;   
	multimap<double, int, greater<int>> mp;    //// 以及greater<int>的作用   大于号  作为排序的参考    降序排列       不使用的话默认升序排列
	//这个和map的区别    允许多个相同的键，可以有重复的键（map不能有重复的key）。  插入相同的键会在容器中保留所有的值。 （map插入已经存在的键，新的值会覆盖旧的） 
	 
	int num=0;//分组

	vector<int> vc;    //cur容器
	if (this->m_index==1)
	{
		vc = v1;   //第一轮接收v1容器   12人
	}
	else
	{
		vc = v2;   //6人
	}

	//遍历选手
	for (auto it = vc.begin(); it != vc.end(); it++)
	{
		num++;//这一步含义是什么

		//打分  每个选手给他一个接收评委分数的容器 deque（双端数组，可以对头端进行插入删除操作）     
		deque<double> d;
		for (int i = 0; i < 10; i++)  //生成十次  600-1000
		{
			double score = (rand()%401+600)/10.f;//随机赋分   /10.f 什么含义  除以10 并且保证float型
			d.push_back(score); //
		}

		//10个评委  之后去去除最高最低分 求平均分
		sort(d.begin(), d.end(),greater<double>()); //降序排列
		d.pop_back();
		d.pop_front();   //删除前后
		double sum = accumulate(d.begin(),d.end(),0.0f) ;    //求和   0.0f 在这里  第三位代表累加的初始值
		double avg = sum /(double)d.size();
		//每个人的平均分
		this->m_player[*it].score[this->m_index-1] = avg;   //这里*it 是vc容器中 即编号
		//m_player 是一个map容器 存放 player类，以及 编号 <int,player>
		// 
		//六人一组   信息带分数  放进mp容器中
		mp.insert(make_pair(avg, *it));//平均分和编号
		if (num % 6 == 0)  //6个人了 一组
		{
			cout << "第" << num / 6 << "组的名次如下" << endl;
			for (multimap<double, int, greater<int>> ::iterator it = mp.begin(); it != mp.end(); it++)
			{
				cout <<"编号：" << it->second <<" 姓名：" <<this->m_player[it->second].name << "分数"
					<<this->m_player[it->second].score[this->m_index-1] << endl;
			}
			//取前三名
			int count = 0;
			for (auto it = mp.begin(); it != mp.end() && count < 3; it++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*it).second);  //这里*it.second  指的是编号  把前三的编号放进v2中 两轮 v2装6个编号
				}
				else
				{
					v3.push_back((*it).second);  //也就是最终组
				}

			}

			mp.clear();
			cout << endl;

		}

	}
	cout << "------------- 第" << this->m_index << "轮比赛完毕  ------------- " << endl;
	system("pause");


}

//显示结果
void speechmanager::showscore()
{
	cout << "---------第" << this->m_index << "轮晋级选手信息如下：-----------" << endl;
	vector<int> v;
	if (this->m_index==1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}

	for (auto it = v.begin(); it != v.end();it++) //遍历获胜选手编号信息  
	{
		cout << "第" << this->m_index << "轮" << "选手编号：" << *it <<" 姓名：" << this->m_player[*it].name    //前面带编号
			<<this->m_player[*it].score[this->m_index-1]<< endl;    //为什么这里可以省略this指针
	}
	cout << endl;
	system("pause");
	system("cls");
	//继续操作就返回菜单
	this->show_menu();

}

//保存记录到文件里  路径默认到了Debug中
void speechmanager::save()   //
{
	//涉及读写文件
	ofstream ofs;
	ofs.open("game.csv", ios::out | ios::app); // 不停地写入 追加模式

	//覆盖上一次结果的写法   使用trunc标志
	//ofs.open("game.csv", ios::out | ios::trunc);
	
	//将数据写进去  只写获胜
	for (auto it = this->v3.begin(); it != v3.end(); it++)
	{		//
		ofs << *it << "," << m_player[*it].score[1] << ",";
	}
	ofs << endl;   //这里  要让文件换行  要不然会导致下面的问题  index永远只是1

	//关闭
	ofs.close();
	cout << "记录已经保存" << endl;
}
 
void speechmanager::loadrecord()  //读取记录     
{
	ifstream ifs("game.csv", ios::in);   
	if (!ifs.is_open())   //判断是否打开   返回true或flase    // 使用 !ofs 检查流状态
	{
		this->fileempty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;  //什么意思？？？
	if (ifs.eof())   //判断是否读到文件末尾
	{
		cout << "文件为空" << endl;
		this->fileempty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileempty = false;
	ifs.putback(ch);  //读取的单个字符放回去

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);  //从零开始查‘，’
			if (pos == -1)
			{
				break;  //找不到 就break
			}
			string tmp = data.substr(start,pos-start);//字符串分割出来一段  (起始位置，长度)
			v.push_back(tmp);
			start = pos + 1;
		}
		this->record.insert(make_pair(index, v));  
		index++;
	}
	//cout <<"index=" << index << endl;   //index=1   
	ifs.close();
	//cout << "记录保存好了" << endl;
	this->fileempty = false;   //不为空
}

//显示往届分数
void speechmanager::showrecord()
{
	//加提示
	if (this->fileempty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//这里可能有问题   这里record.size()为1
		//cout <<"size=" << this->record.size() << endl;   
		for (auto it = record.begin(); it!=record.end();it++)  //record 一个map容器 存放往届数据 遍历容器
		{
			cout << "第" << (it->first)+1<< "届" <<
				" 冠军选手编号：" << it->second[0] << " 分数:" << it->second[1] << " " <<
				" 亚军选手编号：" << it->second[2] << " 分数:" << it->second[3] << " " <<
				" 季军选手编号：" << it->second[4] << " 分数:" << it->second[5] << " " <<
				endl;
		}
		system("pause");
		system("cls");
	}
}


//清空
void speechmanager::clearrecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		//trunc 覆盖  如果存在 删除并重建
		ofstream ofs("game.csv", ios::trunc);
		ofs.close();
		this->initspeech();
		this->createplayer();
		this->loadrecord();

		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
