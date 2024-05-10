/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:26:21
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 08-05-2024 23:55:50
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer
{

	// 声明私有成员变量
private:
	char name[10], ID[17];
	int room_number;
	int days;
	int prepaid;
	// 声明公有成员函数
public:
		Customer();	 // 声明构造函数
	~Customer(); // 声明析构函数

	void set_name(const char *_name);
	void set_ID(const char *_ID);
	void set_days(int _days);
	void set_room_number(int n);
	void set_prepaid(int p);

	char *get_name();
	char *get_ID();
	int get_room_number();
	int get_days();
	int get_prepaid();
};

#endif // CUSTOMER_H
