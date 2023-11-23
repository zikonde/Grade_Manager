//期末大作业
/*********
Program:  学生成绩管理.cpp
Description: 用于管理学生成绩
Authors:
		ZIKONDA NYIRENDA （2020521221001）
		email: 2819960965@qq.com 
		郭珂桢 （2020131210013）
		董镕涛 （2021141410384）
*********/

#include "functions.h"
#include "course.h"
#include "data.h"
#include "student.h"
void menu();

int main() {
	system("Color 3F");
	string tab="\t\t\t\t\t\t";
	string enter="\n\n\n\n\n\n\n\n\n\n\n\n\n";
	ifstream file("s.dat");
	int play;
	if(file.is_open()==0) {
		play=PlaySound(TEXT("sounds\\loginsound.wav"),NULL,SND_FILENAME|SND_ASYNC);

		ofstream file("s.dat");
		file.close();
		for(double i=0; i<=100; i+=2) {
			system("cls");
			cout<<enter<<tab<<"\t加载中。。。。["<<i<<"%]";
			if(i>=100) {
				cout<<endl<<endl<<tab;
			}
		}
	}

	system("cls");

	if(file.is_open()==0)
		cout<<enter<<tab<<" * 欢迎使用学生成绩管理程序 *";
	else cout<<enter<<tab<<" * 欢迎继续使用学生成绩管理程序 *";

	cout<<endl<<endl<<tab<<"\t";
	system("pause");
	PlaySound(0,0,0);
	system("cls");
	int a;


	do {
		system("Color f3");
		menu();
		cout<<tab;
		cin >> a;
		system("cls");
		cout<<"\n ["<<a<<"]"<<endl;

		switch (a) {
			case 1:
				view_data();
				break;
			case 2:
				add_data();
				break;
			case 3:
				edit_data();
				break;
			case 4:
				delete_data();
				break;
			case 5:
				qurey_data_xuehao();
				break;
			case 6:
				qurey_data_average();
				break;
			case 7:
				sort_data();
				break;
			default:
				break;
		}
	} while (a);



	system("cls");
	system("Color 3F");
	cout<<enter<<tab;
	bye();
	cout<<enter;

	system("pause");
	return 0;
}

// 显示主菜单
void menu() {
	int a=250;
	string tab="\t\t\t\t\t\t";
	cout<<"\n\n\n\n\n\n\n";
	cout<<tab<<" *******************************\n";
	cout<<endl;
	cout<<tab<<"  学生成绩管理系统  \n";
	cout<<endl;

	PlaySound(TEXT("sounds\\menu.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);
	for(int i=1; i<=7; i++) {
		Sleep(a);
		if(i==1)cout<<tab<<"[1] 查看所有学生信息  \n";
		if(i==2)cout<<tab<<"[2] 输入学生记录  \n";
		if(i==3)cout<<tab<<"[3] 修改学生记录   \n";
		if(i==4)cout<<tab<<"[4] 删除学生记录  \n";
		if(i==5)cout<<tab<<"[5] 查询学生成绩（学号）  \n";
		if(i==6)cout<<tab<<"[6] 计算学生平均成绩  \n";
		if(i==7) {
			cout<<tab<<"[7] 学生成绩排序  \n";
			i=-1;
		}
		if(i==0) {
			cout<<tab<<"[0] 退出     \n";
			break;
		}
	}
	Sleep(a);
	cout<<endl;
	PlaySound(0,0,0);
}


