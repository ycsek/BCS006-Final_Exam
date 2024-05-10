/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:23:37
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 08-05-2024 23:46:52
 */

/*
 * 信息查询：
 * 1. 顾客信息：输入顾客姓名或ID后可进行预定或入住信息查询
 * 2. 房间信息：展示房间预定和入住情况
 */

#include <iostream>
#include <string>
#include "Inquire.h"
#include "Customer.h"
#include "Room.h"
#include "Initial_room.h"
#include "Room.cpp"
#include "Global.h"

using namespace std;

void inquire()
{
	// 选择查询信息
	cout << "Please choose the information you want to inquire: " << endl;
	cout << "1->Customer informatiom  2->Room information" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	//查询顾客信息，若找到输出相关信息，若未找到输出未找到相关顾客
	case 1:
		char name2[10], id2[17];
		int room_number;
		int days;
		int prepaid;
		cout << "Please enter your name and ID: " << endl;
		cin >> name2 >> id2;
		// 遍历已有的顾客信息，查找匹配对象
		for (int j = 0; j < i; j++)
		{
			if ((strcmp(customer[j]->get_name(), name2) == 0) && (strcmp(customer[j]->get_ID(), id2) == 0))
			{
				room_number = customer[j]->get_room_number();
				days = customer[j]->get_days();
				prepaid = customer[j]->get_prepaid();
				cout << "Name: " << customer[j]->get_name() << endl;
				cout << "ID: " << customer[j]->get_ID() << endl;
				cout << "Room number: " << customer[j]->get_room_number() << endl;
				cout << "Booked Days: " << customer[j]->get_days() << endl;
				//输出顾客的预付金额，预付金额为预定的房间天数乘以按照不同房间等级所对应的价格进行计算
				cout << "Prepaid: " << customer[j]->get_prepaid() << endl;
			}
			else
			{
				cout << "No such customer!" << endl;
			}
			
		}
		break;
		
	//查询客房信息
	case 2:
		int j, k = 0;

		cout << endl;

		cout << "UNBOOKED AND UNOCCUPIED：" << endl;

		// 从100个房间中遍历，找到房间状态为0的房间，并输出其房间号
		for (j = 0; j < 100; j++)
		{
			if (room[j].state == 0)
			{
				if (k % 10 == 0)
					cout << endl;
				cout << room[j].number << '\t';
				k++;
			}
		}
		k = 0;

		cout << endl;

		// 从100个房间中遍历，找到房间状态为1的房间，并输出其房间号
		cout <<"BOOKED：" << endl;
		for (j = 0; j < 100; j++)
		{
			if (room[j].state == 1)
			{
				if (k % 10 == 0)
					cout << endl;
				cout << room[j].number << '\t';
				k++;
			}
		}
		cout << endl;
		
		// 从100个房间中遍历，找到房间状态为2的房间，并输出其房间号
		cout << "OCCUPIED：" << endl;
		for (j = 0; j < 100; j++)
		{
			if (room[j].state == 2)
			{
				if (k % 10 == 0)
					cout << endl;
				cout << room[j].number << '\t';
				k++;
			}
		}
		cout << endl;
	}
}
