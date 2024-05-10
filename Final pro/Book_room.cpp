/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:25:05
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 04-05-2024 18:50:24
 */

/*
 * 说明：此部分实现预定房间的功能，在选择客房等级，输入姓名、ID和预定天数后给出房间号，以及入住价格，房间状态改变为已预定(1)，
 */

#include <iostream>
#include <string>

#include "Book_room.h"
#include "Customer.h"
#include "Room.h"
#include "Initial_room.h"
#include "Global.h"

using namespace std;

void book_room()
{
	// 创建新顾客
	customer[i] = new Customer;
	int rank_room;

	// 选择客房等级
	cout << "Please choose your room rank: " << endl;
	cout << "1\n2\n3\n4\n";
	cout << endl;
	cin >> rank_room;

	// 根据客房等级选择房间，并安排房间号
	switch (rank_room)
	{
		int n;
		// 单人房

	case 1:
		for (n = 0; n < 30; n++)
		{
			if (room[n].state == 0)
			{
				cout << "Booked successfully, Your room numbr is: " << room[n].number << endl;
				room[n].state = 1;
				customer[i]->set_room_number(room[n].number);
				cout << "Days: " << customer[i]->get_days() << endl;
				cout << "Prepaid : " << room[n].price * customer[i]->get_days() << "mop" << endl;
				customer[i]->set_prepaid(room[n].price * customer[i]->get_days()); 
				break;
			}
		}
		break;
		// 双人房

	case 2:
		for (n = 30; n < 60; n++)
		{
			if (room[n].state == 0)
			{
				cout << "Booked successfully, Your room numbr is: " << room[n].number << endl;
				room[n].state = 1;
				customer[i]->set_room_number(room[n].number);
				cout << "Days: " << customer[i]->get_days() << endl;
				cout << "Prepaid: " << room[n].price * customer[i]->get_days() << "mop" << endl;
				customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
				break;
			}
		}
		break;

		// 商务房
	case 3:
		for (n = 60; n < 90; n++)
		{
			if (room[n].state == 0)
			{
				cout << "Booked successfully, Your room numbr is: " << room[n].number << endl;
				room[n].state = 1;
				customer[i]->set_room_number(room[n].number);
				cout << "Days: " << customer[i]->get_days() << endl;
				cout << "Prepaid: " << room[n].price * customer[i]->get_days() << "mop" << endl;
				customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
				break;
			}
		}
		break;

		// 总统套房
	case 4:
		for (n = 90; n < 100; n++)
		{
			if (room[n].state == 0)
			{
				cout << "Booked successfully, Your room numbr is: " << room[n].number << endl;
				room[n].state = 1;
				customer[i]->set_room_number(room[n].number);
				cout << "Days: " << customer[i]->get_days() << endl;
				cout << "Prepaid: " << room[n].price * customer[i]->get_days() << "mop" << endl;
				customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
				break;
			}
		}
		break;
	}
	i++;
}