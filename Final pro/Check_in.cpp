/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:24:09
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 11-05-2024 13:45:36
 */

/*
 * 入住管理：
 * 已预定：输入姓名和ID后确定房间号，以及支付费用，房间状态由已预定未入住转变为已预定已入住
 * 未预定：记录姓名和ID,选择客房等级，输入入住天数，查询可供选择的房间和支付费用，房间状态由未预定未入住转为已预定已入住
 */

#include <iostream>
#include <string>
#include "Check_in.h"
#include "Room.h"
#include "Customer.h"
#include "Initial_room.h"
#include "Global.h"

using namespace std;

void check_in()
{
    // 询问是否预定，若已经预定，在输入姓名和ID后，直接显示信息，若未预定，则进入选择客房
    cout << "Have you booked the room? 1->Yes  2->No\n";
    int choice;
    cin >> choice;

    // 如果已预定，则显示相关预定信息，但输入姓名和ID后，若无匹配对象则显示无预定信息
    if (choice == 1)
    {
        char name2[10], id2[17];
        int room_number;
        int days;
        int prepaid;
        // 输入姓名和ID
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
                cout << "Room number: " << room_number << endl;
                cout << "Days: " << days << endl;
                cout << "Prepaid: " << prepaid << "mop" << endl;
                // 根据房间号判断对应的房间等级，遍历房间信息找到房间等级
                int rank = 0;
                for (int k = 0; k < 100; k++)
                {
                    if (room[k].number == room_number)
                    {
                        rank = room[k].rank;
                        break;
                    }
                }

                // 根据房间等级找到房间价格并乘以入住天数得到房间总价
                int price = 0;
                switch (rank)
                {
                case 1:
                    price = 700 * days;
                    break;
                case 2:
                    price = 1000 * days;
                    break;
                case 3:
                    price = 1500 * days;
                    break;
                case 4:
                    price = 2500 * days;
                    break;
                }

                cout << "Price: " << price << "mop" << endl;

                // 房间状态由已预定未入住转变为已预定已入住
                for (int k = 0; k < 100; k++)
                {
                    if (room[k].number == customer[j]->get_room_number())
                        room[k].state = 2;
                }
            }
            else
            {
                cout << "No booking information found" << endl;
            }
        }
    }

    // 没有预定则进入选择客房
    else
    {
        // 创建新的顾客对象
        customer[i] = new Customer;
        int rank_room;

        // 选择客房等级
        cout << "Please choose your room rank:\n";
        cout << "1\n2\n3\n4\n";
        cin >> rank_room;

        switch (rank_room)
        {
            int n;

        // 选择单人房
        case 1:
            for (n = 0; n < 30; n++)
            {
                if (room[n].state == 0)
                {
                    cout << "入住房间号码为: " << room[n].number << endl;
                    room[n].state = 2;
                    customer[i]->set_room_number(room[n].number);
                    cout << "Days: " << customer[i]->get_days() << endl;
                    customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
                    cout << "prepaid: " << customer[i]->get_prepaid() << "mop" << endl;

                    break;
                }
            }
            break;

        // 选择双人房
        case 2:
            for (n = 30; n < 60; n++)
            {
                if (room[n].state == 0)
                {
                    cout << "入住房间号码为: " << room[n].number << endl;
                    room[n].state = 2;
                    customer[i]->set_room_number(room[n].number);
                    cout << "Days: " << customer[i]->get_days() << endl;
                    customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
                    cout << "prepaid: " << customer[i]->get_prepaid() << "mop" << endl;
                    break;
                }
            }
            break;

        // 选择豪华房
        case 3:
            for (n = 60; n < 90; n++)
            {
                if (room[n].state == 0)
                {
                    cout << "入住房间号码为: " << room[n].number << endl;
                    room[n].state = 2;
                    customer[i]->set_room_number(room[n].number);
                    cout << "Days: " << customer[i]->get_days() << endl;
                    customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
                    cout << "prepaid: " << customer[i]->get_prepaid() << "mop" << endl;

                    break;
                }
            }
            break;

        // 选择总统套房
        case 4:
            for (n = 90; n < 100; n++)
            {
                if (room[n].state == 0)
                {
                    cout << "入住房间号码为: " << room[n].number << endl;
                    room[n].state = 2;
                    customer[i]->set_room_number(room[n].number);
                    cout << "Days: " << customer[i]->get_days() << endl;
                    customer[i]->set_prepaid(room[n].price * customer[i]->get_days());
                    cout << "prepaid: " << customer[i]->get_prepaid() << "mop" << endl;
                    break;
                }
            }
            break;
        }
        i++;
    }
}