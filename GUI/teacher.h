#ifndef TEACHER_H
#define TEACHER_H
#include "person.h"
#include <string>
#include <fstream>
#include <stdbool.h>
#include "Home.h"

class Teacher:public Person{
	std::string password;
public:
	Teacher():Person(){}
	Teacher(std::string n,std::string id,std::string p):Person(n,id),password(p){	}
	std::string &getPassword(){return password;	}
	void setPassword(std::string p){ password=p;	}
	friend std::ofstream &operator<<(std::ofstream &out,Teacher &teacher);
};
   /*
	friend bool operator()(Teacher teacher, bool n){
	}   */

	std::ofstream &operator<<(std::ofstream &out,Teacher &teacher){
		std::string ss;
		out<<teacher.getName()<<","<<teacher.getId()<<","<<teacher.getPassword()<<"\n";

		return out;
	}
	//
#endif
