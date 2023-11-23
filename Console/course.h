#ifndef COURSE_H
#define COURSE_H

#include "root.h"

struct Course {
	float score;
	static int count;
	Course() {
		count++;
	}
	Course(float s):score(s) {
		count++;
	}
};

int Course::count=0;

#endif
