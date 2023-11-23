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
	cout<<"\nû�����ݣ���ѡ \"����ѧ����¼\" \n";
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
	cout<<setw(name) <<left<<"����"
	    <<setw(emp) <<left<<" "
	    <<setw(id_no) <<left<<"ѧ��"
	    <<setw(emp) <<left<<" "
	    <<setw(course) <<left<<"רҵ"
	    <<setw(emp) <<left<<" "
	    <<setw(_class) <<left<<"�༶"
	    <<setw(emp) <<left<<" "
	    <<setw(math) <<left<<"��ѧ"
	    <<setw(emp) <<left<<" "
	    <<setw(eng) <<left<<"Ӣ��"
	    <<setw(emp) <<left<<" "
	    <<setw(lang) <<left<<"����"
	    <<setw(emp) <<left<<" "
	    <<setw(ave) <<left<<"ƽ����";
	cout<<setw(total)<<"\n--------------------------------------------------------------------------------\n";
	for (i = 0; i < dd.count; i++) {
		cout<<dd.stu[i]<<endl;
	}
	cout<<setw(total)<<"\n--------------------------------------------------------------------------------\n";
}


// ����ѧ����¼
void add_data() {
	int b;
	int k = dd.count;
	while (k < MAX) {
		cin>>dd.stu[k];

		ofstream file("s.dat",ios::app);
		file<<dd.stu[k]<<endl;

		dd.count++; //��Ҫ��ǰ��0�����������С�
		k = dd.count;
		cout<<"\n\n�������ѧ����Ϣ[��1�س����� 0�س����أ������س��˳�]:";

		file.close();

		cin >> b;
		if (b != 1) {
			cin.clear();
			break;
		}

	}

}


// �޸�ѧ����¼
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

	cout<<"\n������Ҫ�޸�ѧ����ѧ��:";
	valid_numeral(xuehao);

	cout<<endl;
	flag=qurey_data_xuehao(xuehao);


	if (flag != -1) {
		cin>>dd.stu[flag];

		cout<<"���棿����/�� ";
		cin>>shifou;
		if(shifou=="��") {
			ofstream file_out("s.dat");
			for (i = 0; i < dd.count; i++) { //��kλ�õ����ݱ�k+1λ�õ���Ϣ����
				file_out<<dd.stu[i];
			}
		}

		cout<<"\n\n�޸�ѧ����¼(ѧ��-"<< xuehao <<")�ɹ�!";
	}
}

//ɾ����¼
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

	cout << "\n������Ҫ�޸�ѧ����ѧ�ţ�����0������м�¼��:";
	valid_numeral(xuehao);
	if(xuehao==0) {
		cout<<"ȷ��������м�¼������/�� ";
		ofstream clear_file("s.dat");
		cin>>shifou;
		if(shifou=="��") {
			clear_file<<"";
			cout<<"\n\t~�ɹ�!"<<endl;
			return;
		}
	}
	cout<<endl;
	flag=qurey_data_xuehao(xuehao);

	if (flag != -1) {
		cout<<"ȷ���Ƿ�ɾ����ѧ��������/�� ";
		cin>>shifou;
		{
			for (i = flag; i < dd.count - 1; i++) { //��kλ�õ����ݱ�k+1λ�õ���Ϣ����
				dd.stu[i] = dd.stu[i + 1];
			}
			dd.count--;
			ofstream file_out("s.dat");
			for (i = 0; i < dd.count; i++) { //��kλ�õ����ݱ�k+1λ�õ���Ϣ����
				file_out<<dd.stu[i];
			}
			cout << "\n\nɾ��ѧ����¼(ѧ��-" << xuehao << ")�ɹ�!";
		}
	}
}

//ѧ�Ų�ѯ�ɼ� //��Ҫѧ��������ģ���Ȼʵ�ֲ����۰��ѯ
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
	cout << "\n������Ҫ�޸�ѧ����ѧ��:";
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
	if(flag==-1)cout << "\nû���ҵ���ѧ��(ѧ��-" << xuehao << ")!";
	else {
		cout<<endl;
		cout<<setw(name) <<left<<"����"
		    <<setw(emp) <<left<<" "
		    <<setw(id_no) <<left<<"ѧ��"
		    <<setw(emp) <<left<<" "
		    <<setw(course) <<left<<"רҵ"
		    <<setw(emp) <<left<<" "
		    <<setw(_class) <<left<<"�༶"
		    <<setw(emp) <<left<<" "
		    <<setw(math) <<left<<"��ѧ"
		    <<setw(emp) <<left<<" "
		    <<setw(eng) <<left<<"Ӣ��"
		    <<setw(emp) <<left<<" "
		    <<setw(lang) <<left<<"����"
		    <<setw(emp) <<left<<" "
		    <<setw(ave) <<left<<"ƽ����";
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
	cout<<setw(math) <<left<<"��ѧƽ����"
	    <<setw(emp) <<left<<" "
	    <<setw(eng) <<left<<"Ӣ��ƽ����"
	    <<setw(emp) <<left<<" "
	    <<setw(lang) <<left<<"����ƽ����"
	    <<setw(emp) <<left<<" "
	    <<setw(ave) <<left<<"Totalƽ����";
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

//���� ����ƽ��ֵ����
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
				student tmp; //��ʱ����
				tmp = dd.stu[j]; //����
				dd.stu[j] = dd.stu[j + 1];
				dd.stu[j + 1] = tmp;
			}
		}

	}
	ofstream file_out("s.dat");
	for (i = 0; i < dd.count; i++) { //��kλ�õ����ݱ�k+1λ�õ���Ϣ����
		file_out<<dd.stu[i];
	}
	file_out.close();

	view_data();
}

void bye() {
	int a=100;

	PlaySound(TEXT("sounds\\slow-typing.wav"),NULL,SND_FILENAME|SND_LOOP|SND_ASYNC);

	Sleep(700);
	cout<<"��";
	Sleep(a);
	cout<<"л";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"ʹ";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(1000);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";
	Sleep(a);
	cout<<"��";

	PlaySound(0,0,0);
}






#endif
