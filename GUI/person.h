#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person{
	std::string name;
	std::string id;
public:
    Person(){}
	Person(std::string n,std::string _id):name(n),id(_id){	}
	std::string getName(){return name;	}
	std::string getId(){return id;	}
	void setName(std::string n){ name=n;	}
	void setId(std::string _id){ id=_id;	}
};
#endif 
