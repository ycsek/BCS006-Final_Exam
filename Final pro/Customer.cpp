/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:26:39
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 15-05-2024 14:55:53
 */

#include "Customer.h"
#include "Global.h"
#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

// 构造函数
Customer::Customer()
{
	// 初始化顾客信息
	// 使用strcpy_s函数进行字符串赋值
	strcpy_s(name, "NULL");
	strcpy_s(ID, "NULL");
	room_number = 0;
	days = 0;
	prepaid = 0;

	// 登记姓名
	cout << "Please enter your name" << endl;
	cin >> name;

	// 登记ID
	cout << "please enter your ID" << endl;
	cin >> ID;

	// 输入入住天数
	cout << "Please enter the days you want to stay" << endl;
	cin >> days;
}

// 析构函数
Customer::~Customer()
{
	cout << "Check_out done!" << endl;
}

// 顾客姓名
void Customer::set_name(const char *_name)
{
	strcpy_s(name, _name);
}

// 顾客ID
void Customer::set_ID(const char *_ID)
{
	strcpy_s(ID, _ID);
}

// 入住天数
void Customer::set_days(int _days)
{
	days = _days;
}

// 房间号
void Customer::set_room_number(int n)
{
	room_number = n;
}

// 预付款
void Customer::set_prepaid(int p)
{

	prepaid = p;
}

// 获取顾客信息
char *Customer::get_name()
{
	return name;
}

// 获取顾客ID
char *Customer::get_ID()
{
	return ID;
}

// 获取房间号
int Customer::get_room_number()
{
	return room_number;
}

// 获取入住天数
int Customer::get_days()
{
	return days;
}

// 获取预付款
int Customer::get_prepaid()
{
	return prepaid;
}
