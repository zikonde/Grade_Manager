//---------------------------------------------------------------------------

#include <fmx.h>
#include <string>
#include "teacher.h"
#include "student.h"
#include "path.h"
#include <fstream>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Sort.cpp", SortForm);
USEFORM("Signout.cpp", SignoutForm);
USEFORM("SearchStudent.cpp", SearchStudentForm);
USEFORM("View.cpp", ViewForm);
USEFORM("DeleteStudent.cpp", DeleteStudentForm);
USEFORM("Averages.cpp", AveragesForm);
USEFORM("AddStudent.cpp", AddStudentForm);
USEFORM("Login.cpp", LoginForm);
USEFORM("Home.cpp", HomeForm);
USEFORM("Edit.cpp", EditForm);
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	Student *stu;
	std::fstream m(getPath()+"Mark.txt");
	if(m.is_open()==0){
		std::ofstream mark(getPath()+"Mark.txt");
		stu=new Student("Ziko","10001","Ad","20",100,88.7,56);mark<<*stu;delete stu;
		stu=new Student("Racheal","10002","Ad","20",100,88.7,56);mark<<*stu;delete stu;
		stu=new Student("Ruth","10003","Ad","20",100,88.7,56);mark<<*stu;delete stu;
		stu=new Student("Peter","10004","Ad","20",100,88.7,56);mark<<*stu;delete stu;
		mark.close();
	} m.close();

	std::fstream j(getPath()+"John.txt");
	if(j.is_open()==0){
		std::ofstream john(getPath()+"John.txt");
		stu=new Student("ÀîÄ³","10005","Ad","20",100,88.7,56);john<<*stu;delete stu;
		stu=new Student("³ÂÄ³","10006","Ad","20",100,88.7,56);john<<*stu;delete stu;
		stu=new Student("Ruth","10007","Ad","20",100,88.7,56);john<<*stu;delete stu;
		stu=new Student("Brenda","10008","Ad","20",100,88.7,56);john<<*stu;delete stu;
		stu=new Student("Albert","10009","Ad","20",100,88.7,56);john<<*stu;delete stu;
		stu=new Student("Geff","10010","Ad","20",100,88.7,56);john<<*stu;delete stu;
		john.close();
	} j.close();

	Teacher*teach;
	std::fstream t(getPath()+"Teachers.txt");
	if(t.is_open()==0){
		std::ofstream teachers(getPath()+"Teachers.txt");
		teach=new Teacher("Mark","1001","mk1001");teachers<<*teach;delete teach;
		teach=new Teacher("John","1002","jn1002");teachers<<*teach;delete teach;
		teach=new Teacher("Mathew","1003","mt1003");teachers<<*teach;delete teach;
		teachers.close();
	} t.close();

	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TLoginForm), &LoginForm);
		Application->CreateForm(__classid(TDeleteStudentForm), &DeleteStudentForm);
		Application->CreateForm(__classid(TEditForm), &EditForm);
		Application->CreateForm(__classid(TSearchStudentForm), &SearchStudentForm);
		Application->CreateForm(__classid(TAveragesForm), &AveragesForm);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
