/*
 * @Author: Yuchen Shi
 * @Date: 27-04-2024 20:22:48
 * @LastEditors: Jason
 * @Contact LastEditors: yuchenshi327@outlook.com
 * @LastEditTime: 04-05-2024 19:54:46
 */

/*
 * 程序运行主体
 */

#include <iostream>
#include <string>
#include <cstdlib>

// 自定义的头文件
#include "Initial_room.h"
#include "Room.h"
#include "Customer.h"
#include "Enter.h"
#include "Book_room.h"
#include "Check_in.h"
#include "Check_out.h"
#include "Inquire.h"
#include "Global.h"

using namespace std;

int main()
{
	// 初始化房间
   initial_room();
   //验证信息界面
   void welcome();
   {
	   string username = "admin";		 // 设定用户名
	   string password = "admin123456"; // 设定密码
	   string input_username, input_password;
	   cout << "Please enter your username: " << endl;
	   cin >> input_username;
	   cout << "Please enter your password: " << endl;
	   cin >> input_password;
	   if (input_username == username && input_password == password) // 判断用户名和密码是否正确
	   {
		   cout << "Welcome, admin!" << endl;

		   // 登录欢迎界面
		   cout << endl;
		   cout << endl;
		   cout << "                      ***************************\n";
		   cout << "                      Hotel Management System\n";
		   cout << "                      ***************************\n";
		   cout << endl;
		   cout << endl;
	   }
	   // 如果用户名或密码错误，重新输入
	   else
	   {
		   cout << "Invalid username or password. Please try again." << endl;
		   cout << "Please enter your username: " << endl;
		   cin >> input_username;
		   cout << "Please enter your password: " << endl;
		   cin >> input_password;

	   }
	   // 如果用户名和密码正确，进入服务选择界面
	   while (input_username == username && input_password == password)
	   {
		   enter();
	   }
   }
    return 0;
}