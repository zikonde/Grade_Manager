#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include "course.h"
#include "data.h"
#include "student.h"

void view_data();
void add_data();
void edit_data();
void delete_data();
void qurey_data_xuehao();
int qurey_data_xuehao(float xuehao);
void qurey_data_average();
void sort_data();
void bye();

inline void nill_data() {
	cout<<"\n没有数据，请选 \"输入学生记录\" \n";
}

void view_data() {
	int i=0;
	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	if(dd.count<1) {
		nill_data();
		return;
	}

	int emp=2,name=15,id_no=15,course,_class,math,eng,lang,ave;
	course=_class=math=eng=lang=ave=6;
	int total=emp*7+name+id_no+course*6;
	cout<<endl;
	cout<<setw(name) <<left<<"姓名"
	    <<setw(emp) <<left<<" "
	    <<setw(id_no) <<left<<"学号"
	    <<setw(emp) <<left<<" "
	    <<setw(course) <<left<<"专业"
	    <<setw(emp) <<left<<" "
	    <<setw(_class) <<left<<"班级"
	    <<setw(emp) <<left<<" "
	    <<setw(math) <<left<<"数学"
	    <<setw(emp) <<left<<" "
	    <<setw(eng) <<left<<"英语"
	    <<setw(emp) <<left<<" "
	    <<setw(lang) <<left<<"语文"
	    <<setw(emp) <<left<<" "
	    <<setw(ave) <<left<<"平均分";
	cout<<setw(total)<<"\n--------------------------------------------------------------------------------\n";
	for (i = 0; i < dd.count; i++) {
		cout<<dd.stu[i]<<endl;
	}
	cout<<setw(total)<<"\n--------------------------------------------------------------------------------\n";
}


// 输入学生记录
void add_data() {
	int b;
	int k = dd.count;
	while (k < MAX) {
		cin>>dd.stu[k];

		ofstream file("s.dat",ios::app);
		file<<dd.stu[k]<<endl;

		dd.count++; //需要提前置0，在主函数中。
		k = dd.count;
		cout<<"\n\n继续添加学生信息[按1回车继续 0回车返回，其他回车退出]:";

		file.close();

		cin >> b;
		if (b != 1) {
			cin.clear();
			break;
		}

	}

}


// 修改学生记录
void edit_data() {
	int i=0, flag=-1;
	float  xuehao;
	string shifou;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();

	if(dd.count<1) {
		nill_data();
		return;
	}

	cout<<"\n请输入要修改学生的学号:";
	valid_numeral(xuehao);

	cout<<endl;
	flag=qurey_data_xuehao(xuehao);


	if (flag != -1) {
		cin>>dd.stu[flag];

		cout<<"保存？（是/否） ";
		cin>>shifou;
		if(shifou=="是") {
			ofstream file_out("s.dat");
			for (i = 0; i < dd.count; i++) { //将k位置的数据被k+1位置的信息覆盖
				file_out<<dd.stu[i];
			}
		}

		cout<<"\n\n修改学生记录(学号-"<< xuehao <<")成功!";
	}
}

//删除记录
void delete_data() {
	int i=0, flag=-1;
	float  xuehao;
	string shifou;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();

	if(dd.count<1) {
		nill_data();
		return;
	}

	cout << "\n请输入要修改学生的学号（输入0清除所有记录）:";
	valid_numeral(xuehao);
	if(xuehao==0) {
		cout<<"确认清除所有记录？（是/否） ";
		ofstream clear_file("s.dat");
		cin>>shifou;
		if(shifou=="是") {
			clear_file<<"";
			cout<<"\n\t~成功!"<<endl;
			return;
		}
	}
	cout<<endl;
	flag=qurey_data_xuehao(xuehao);

	if (flag != -1) {
		cout<<"确定是否删除该学生？（是/否） ";
		cin>>shifou;
		{
			for (i = flag; i < dd.count - 1; i++) { //将k位置的数据被k+1位置的信息覆盖
				dd.stu[i] = dd.stu[i + 1];
			}
			dd.count--;
			ofstream file_out("s.dat");
			for (i = 0; i < dd.count; i++) { //将k位置的数据被k+1位置的信息覆盖
				file_out<<dd.stu[i];
			}
			cout << "\n\n删除学生记录(学号-" << xuehao << ")成功!";
		}
	}
}

//学号查询成绩 //需要学号是有序的，不然实现不了折半查询
void qurey_data_xuehao() {
	int i=0;
	float  xuehao;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();

	if(dd.count<1) {
		nill_data();
		return;
	}
	cout << "\n请输入要修改学生的学号:";
	valid_numeral(xuehao);

	qurey_data_xuehao(xuehao);
}

int qurey_data_xuehao(float xuehao) {
	int i=0,emp=2,name=15,id_no=15,course,_class,math,eng,lang,ave;
	course=_class=math=eng=lang=ave=6;
	int tot=emp*7+name+id_no+course*6;
	int flag=-1;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();

	for(i=0; i<dd.count; i++) {
		if(dd.stu[i].xuehao==xuehao) {
			flag=i;
			break;
		}
	}
	if(flag==-1)cout << "\n没有找到该学生(学号-" << xuehao << ")!";
	else {
		cout<<endl;
		cout<<setw(name) <<left<<"姓名"
		    <<setw(emp) <<left<<" "
		    <<setw(id_no) <<left<<"学号"
		    <<setw(emp) <<left<<" "
		    <<setw(course) <<left<<"专业"
		    <<setw(emp) <<left<<" "
		    <<setw(_class) <<left<<"班级"
		    <<setw(emp) <<left<<" "
		    <<setw(math) <<left<<"数学"
		    <<setw(emp) <<left<<" "
		    <<setw(eng) <<left<<"英语"
		    <<setw(emp) <<left<<" "
		    <<setw(lang) <<left<<"语文"
		    <<setw(emp) <<left<<" "
		    <<setw(ave) <<left<<"平均分";
		cout<<setw(tot)<<"\n--------------------------------------------------------------------------------\n\n";
		cout<<dd.stu[flag]<< "\n";
		cout<<setw(tot)<<"\n--------------------------------------------------------------------------------\n";
	}

	return flag;
}

void qurey_data_average() {
	int i,emp=2,math,eng,lang,ave;
	math=eng=lang=ave=10;
	int tot=emp*3+math*4;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();

	if(dd.count<1) {
		nill_data();
		return;
	}

	float avg_shuxue=0,avg_yingyu=0,avg_yuwen=0,total_avg;
	cout<<endl;
	cout<<setw(math) <<left<<"数学平均分"
	    <<setw(emp) <<left<<" "
	    <<setw(eng) <<left<<"英语平均分"
	    <<setw(emp) <<left<<" "
	    <<setw(lang) <<left<<"语文平均分"
	    <<setw(emp) <<left<<" "
	    <<setw(ave) <<left<<"Total平均分";
	for (int i = 0; i < dd.count; i++) {
		avg_shuxue+=dd.stu[i].shuxue.score;
		avg_yingyu+=dd.stu[i].yingyu.score;
		avg_yuwen+=dd.stu[i].yuwen.score;
	}
	avg_shuxue/=dd.count;
	avg_yingyu/=dd.count;
	avg_yuwen/=dd.count;
	total_avg=(avg_shuxue+avg_yingyu+avg_yuwen)/((Course::count/MAX));

	cout<<setw(tot)<<"\n-------------------------------------------------\n\n";
	cout<<setw(math)<<avg_shuxue
	    <<setw(emp) <<left<<" "
	    <<setw(eng) <<avg_yingyu
	    <<setw(emp) <<left<<" "
	    <<setw(lang) <<avg_yuwen
	    <<setw(emp) <<left<<" "
	    <<setw(ave) << total_avg<< "\n";
	cout<<setw(tot)<<"\n-------------------------------------------------\n";

}

//排序 根据平均值排序
void sort_data() {
	int i=0, j, N;

	dd.count=0;
	ifstream file("s.dat");
	while(file>>dd.stu[i++]) {
		dd.count++;
	}
	file.close();
	if(dd.count<1) {
		nill_data();
		return;
	}
	N = dd.count;
	for (i = 0; i < N - 1; i++) {
		for (j = 0; j < N - 1 - i; j++) {
			if (dd.stu[j].avg < dd.stu[j + 1].avg) {
				student tmp; //临时变量
				tmp = dd.stu[j]; //交换
				dd.stu[j] = dd.stu[j + 1];
				dd.stu[j + 1] = tmp;
			}
		}

	}
	ofstream file_out("s.dat");
	for (i = 0; i < dd.count; i++) { //将k位置的数据被k+1位置的信息覆盖
		file_out<<dd.stu[i];
	}
	file_out.close();

	view_data();
}

void bye() {
	int a=100;

	PlaySound(TEXT("sounds\\slow-typing.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

	Sleep(700);
	cout<<"感";
	Sleep(a);
	cout<<"谢";
	Sleep(a);
	cout<<"您";
	Sleep(a);
	cout<<"本";
	Sleep(a);
	cout<<"次";
	Sleep(a);
	cout<<"使";
	Sleep(a);
	cout<<"用";
	Sleep(a);
	cout<<"我";
	Sleep(a);
	cout<<"们";
	Sleep(a);
	cout<<"的";
	Sleep(a);
	cout<<"程";
	Sleep(a);
	cout<<"序";
	Sleep(a);
	cout<<"。";
	Sleep(1000);
	cout<<"下";
	Sleep(a);
	cout<<"次";
	Sleep(a);
	cout<<"再";
	Sleep(a);
	cout<<"见";
	Sleep(a);
	cout<<"！";

	PlaySound(0,0,0);
}






#endif
