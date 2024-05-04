/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:24:22
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 04-05-2024 18:57:30
 */

#include <iostream>
#include <string>
#include "Check_out.h"
#include "Room.h"
#include "Customer.h"
#include "Global.h"
using namespace std;

void check_out()
{
    char name2[10], id2[17];
    int room_number;
    int days;

    // 输入姓名和ID
    cout << "Please enter your name and ID: " << endl;
    cin >> name2 >> id2;
    // 询问实际入住天数
    cout << "Please enter the actual days you stay: " << endl;
    int actual_days;
    cin >> actual_days;

    // 遍历已有的顾客信息，查找匹配对象
    for (int j = 0; j < i; j++)
    {
        if ((strcmp(customer[j]->get_name(), name2) == 0) && (strcmp(customer[j]->get_ID(), id2) == 0))
        {
            room_number = customer[j]->get_room_number();
            days = customer[j]->get_days();
            int rank = 0;
            for (int k = 0; k < 100; k++)
            {
                if (room[k].number == room_number)
                {
                    rank = room[k].rank;
                    break;
                }
            }
            // 根据房间等级找到房间价格并乘以实际入住天数得到实际房间总价
            int price = 0;
            switch (rank)
            {
            case 1:
                price = 700 * actual_days;
                break;
            case 2:
                price = 1000 * actual_days;
                break;
            case 3:
                price = 1500 * actual_days;
                break;
            case 4:
                price = 2500 * actual_days;
                break;
            }
            // 输出顾客信息
            cout << "Name: " << customer[j]->get_name() << endl;
            cout << "ID: " << customer[j]->get_ID() << endl;
            cout << "Room number: " << customer[j]->get_room_number() << endl;
            cout << "Booked Days: " << customer[j]->get_days() << endl;
            cout << "Prepaid: " << customer[j]->get_prepaid() << "mop" << endl;
            cout << "Actual Days: " << actual_days << endl;
            cout << "Actual payment: " << price << "mop" << endl;

            //实现退房结算，若预付金额大于实际房间总价，则输出找零金额（多退少补）
            cout << "You need to pay:" << price - customer[j]->get_prepaid() << "mop" << endl;

            // 确认退房环节
            cout << "Confirm checkour enter 1 " << endl;
            char account;
            cin >> account;
            if (account == '1')
            {
                // 若已确认退房，则还原房间信息，将房间状态变为0（未预定未入住），同时从顾客的指针数组（Customer *customer）中删除该顾客信息
                for (int k = 0; k < 100; k++)
                {
                    if (room[k].number == customer[j]->get_room_number())
                        room[k].state = 0;
                }
                i--;
                for (; j < i; j++)
                {
                    customer[j] = customer[j + 1];
                }
                delete customer[i];
            }
        }
        else
        {
            cout << "No information found" << endl;
        }
        cout << endl;
       
    }
}
