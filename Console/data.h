#ifndef DATA_H
#define DATA_H

#define MAX 200

#include "root.h"
#include "course.h"
#include "student.h"

struct data
{
    static int count; // ��ǰѧ��������ѧ���ĸ���
    struct student stu[MAX]; // ѧ������
}dd;

int data::count=0;

#endif
