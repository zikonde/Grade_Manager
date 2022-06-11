#ifndef COURSES_H
#define COURSES_H
#include <string>
#include "person.h"

class Course{
public:
	static int count;
	std::string name;
	double score;
	Course(){	}
	Course(std::string n,double s=0):name(n){if(s>=0&&s<=100)score=s;else score=0;count++; 	}
	std::string getName(){return name;	}
    static int getCount(){return count;}
};

int Course::count=0;
#endif
