/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:23:13
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 30-04-2024 16:17:05
 */

/*
 *进入登录界面后选择功能（预定，入住，退房，查询,退出界面）
 */

#include <iostream>
#include "Enter.h"
#include "Book_room.h"
#include "Check_in.h"
#include "Check_out.h"
#include "Inquire.h"

using namespace std;

void enter()
{
    // 选择服务
    int kind_of_service;
    while (1)
    {
        cout << "Please enter the service you want? \n";
        cout << " 1->Book room 2->Check in  3->Check out  4->Inquire   5->Exit:  ";
        cin >> kind_of_service;
        if ((kind_of_service <= 5) && (kind_of_service >= 1))
        {

            switch (kind_of_service)
            {
                // 预定
            case 1:
                book_room();
                break;
                // 入住
            case 2:
                check_in();
                break;
                // 退房
            case 3:
                check_out();
                break;
                // 查询
            case 4:
                inquire();
                break;
                // 退出
            case 5:
                exit(0);
                break;
            }
        }
        else
        {
            cout << "Wrong! please input it again." << endl;
            continue;
        }
    }
}