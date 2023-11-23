#ifndef DATA_H
#define DATA_H

#define MAX 200

#include "root.h"
#include "course.h"
#include "student.h"

struct data
{
    static int count; // 当前学生数组中学生的个数
    struct student stu[MAX]; // 学生数组
}dd;

int data::count=0;

#endif
