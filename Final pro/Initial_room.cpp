/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 21:08:40
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 30-04-2024 16:17:55
 */

/*
 * 初始化100个不同等级的房间
 */

#include <iostream>
#include "Initial_room.h"
#include "Room.h"
#include "Global.h"

using namespace std;

void initial_room()
{
    int j, k = 501;
    for (j = 0; j < 30; j++)
    {
        room[j].number = k++;
        room[j].rank = 1;
        room[j].state = 0;
        room[j].price = 700;
    }
    k = 601;
    for (j = 30; j < 60; j++)
    {
        room[j].number = k++;
        room[j].rank = 2;
        room[j].state = 0;
        room[j].price = 1000;
    }
    k = 701;
    for (j = 60; j < 90; j++)
    {
        room[j].number = k++;
        room[j].rank = 3;
        room[j].state = 0;
        room[j].price = 1500;
    }
    k = 801;
    for (j = 90; j < 100; j++)
    {
        room[j].number = k++;
        room[j].rank = 4;
        room[j].state = 0;
        room[j].price = 2500;
    }
}