#pragma once
#include<iostream>
using namespace std;



class player    //头文件只做声明
{
public:
	string name;  //姓名
	double score[2];   //分数    最多两轮得分
	//player(string name,int score)
	//{
	//	this->name = name;
	//	this->score = score;
	//};
};