#ifndef STUDENT_H
#define STUDENT_H
#include "course.h"
#include "person.h"
#include <string>

class Student:public Person{
	std::string major;
	std::string banji;
	Course *math;
	Course *eng;
	Course *chinese;
	double avg;
public:
	Student():Person(){}
	Student(std::string n,std::string _id,std::string m,std::string b,double _math,double _eng,double c)
		:Person(n,_id),major(m),banji(b){
			math=new Course("Math",_math);
			eng=new Course("English",_eng);
			chinese=new Course("Chinese",c);
			avg=(math->score+eng->score+chinese->score)/(Course::getCount());
	}
	Student(Student &student){
		setName(student.getName());
		setId(student.getId());
		math=new Course;
			math->name=student.math->name;
			math->score=student.getMath();
		eng=new Course;
			eng->name=student.eng->name;
			eng->score=student.getEng();
		chinese=new Course;
			chinese->name=student.chinese->name;
			chinese->score=student.getChinese();

		avg=student.avg;
	}
	~Student(){
	delete math;
	delete eng;
	delete chinese;
	}
	std::string getMajor(){return major;}
	std::string getBanji(){return banji;}
	double getMath(){return math->score;}
	double getEng(){return eng->score;}
	double getChinese(){return math->score;}
	double getAvg(){return avg;}
	friend std::ofstream &operator<<(std::ofstream &out,Student &student);
	friend std::ifstream &operator>>(std::ifstream &in,Student &student);
	Student &operator=(Student &student){
		setName(student.getName());
		setId(student.getId());
	  	math=new Course;
			math->name=student.math->name;
			math->score=student.getMath();
		eng=new Course;
			eng->name=student.eng->name;
			eng->score=student.getEng();
		chinese=new Course;
			chinese->name=student.chinese->name;
			chinese->score=student.getChinese();

		avg=student.avg;

		return *this;
	}
};

std::ofstream &operator<<(std::ofstream &out,Student &student){
	out<<student.getName()<<","<<student.getId()<<","<<student.getMajor()<<","
		<<student.getBanji()<<","<<student.getMath()<<","<<student.getEng()<<","
		<<student.getChinese()<<","<<student.getAvg()<<"\n";
	return out;
}

std::ifstream &operator>>(std::ifstream &in,Student &student){
	std::string name,id,major,banji;
	double math,eng,chi,avg;
	 in>>name>>id>>major>>banji>>math>>eng>>chi>>avg;

	 Student stu(name,id,major,banji,math,eng,chi);
     student=stu;
	 return in;
}

#endif
