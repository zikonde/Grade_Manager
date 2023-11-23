#ifndef STUDENT_H
#define STUDENT_H

#include "root.h"
#include "course.h"
#include "data.h"

void valid_numeral(int &a);
void valid_numeral(float &a);
void valid_numeral(double &a);

struct student {
	std::string xingming,  zhuanye, banji;

	float xuehao;
	Course shuxue;
	Course yingyu;
	Course yuwen;
	float avg;//ƽ��ֵ
};

ostream &operator <<(ostream &out,student &stu) {
	int emp=2,name=15,id_no=15,course,_class,math,eng,lang,ave;
	course=_class=math=eng=lang=ave=6;
	int tot=emp*7+name+id_no+course*6;

	out<<endl;
	out<<setw(name)<< stu.xingming
	   <<setw(emp) <<left<<" "
	   <<setw(id_no) << stu.xuehao
	   <<setw(emp) <<left<<" "
	   <<setw(course) << stu.zhuanye
	   <<setw(emp) <<left<<" "
	   <<setw(_class) << stu.banji
	   <<setw(emp) <<left<<" "
	   <<setw(math)<< stu.shuxue.score
	   <<setw(emp) <<left<<" "
	   <<setw(eng) << stu.yingyu.score
	   <<setw(emp) <<left<<" "
	   <<setw(lang) << stu.yuwen.score
	   <<setw(emp) <<left<<" "
	   <<setw(ave) << stu.avg << "\n";

	return out;
}
istream &operator >>(istream &in,student &stu) {
	cout<<endl;
	cout << "������ѧ��������";
	cin>>stu.xingming;
	cout << "������ѧ��ѧ�ţ�";

	valid_numeral(stu.xuehao);

	cout << "������ѧ��רҵ��";
	cin >> stu.zhuanye;
	cout << "������ѧ���༶��";
	cin >> stu.banji;


	cout << "������ѧ����ѧ��";
	valid_numeral(stu.shuxue.score);

	cout << "������ѧ��Ӣ�";
	valid_numeral(stu.yingyu.score);

	cout << "������ѧ�����ģ�";
	valid_numeral(stu.yuwen.score);


	stu.avg =(stu.shuxue.score+stu.yingyu.score+stu.yuwen.score)/(Course::count/MAX);

	return in;
}

ofstream &operator <<(ofstream &out,student &stu) {
	out<< stu.xingming <<" "<<stu.xuehao<<" "<<stu.zhuanye<<" "<<" "<<stu.banji<<" "<<stu.shuxue.score<<" "<< stu.yingyu.score
	   <<" "<< stu.yuwen.score<<" "<< stu.avg << "\n";

	return out;
}
ifstream &operator >>(ifstream &in,student &stu) {
	in>>stu.xingming>>stu.xuehao>>stu.zhuanye>>stu.banji>>stu.shuxue.score>>stu.yingyu.score
	  >>stu.yuwen.score>>stu.avg;
	return in;
}

//��ȡ��Чint������
void valid_numeral(int &a) {
	double tmp;
	valid_numeral(tmp);
	a=tmp;
}
void valid_numeral(float &a) {
	double tmp;
	valid_numeral(tmp);
	a=tmp;
}
void valid_numeral(double &a) {
	double tmp;
	string wuxiao="��Ч�ַ�������������: ";
	cin >> tmp;
	while (!cin) {
		char ch;
		while ((ch = getchar()) != '\n')
			continue;
		cout <<wuxiao;
		cin.clear();
		cin >> tmp;
	}
	a = tmp;
}

#endif
