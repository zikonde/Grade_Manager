//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Sort.h"
#include "path.h"
#include <sstream>
#include <string>
#include <vector>
#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSortForm *SortForm;
//---------------------------------------------------------------------------
void NameSortStudents(std::vector<Student> &students){
	int i;

	for (i = 0; i < students.size()-1; i++) {
		int min=i;
		for (int j = i+1; j < students.size(); j++) {
			if (std::strcmp(students[j].getName().c_str(),students[min].getName().c_str())<0)
				min=j;
			if(min!=i){
				std::string tmp,tmp2;
				tmp=students[i].getName();
				students[i].getName()=students[min].getName();
				students[min].getName() = tmp;
			}
		}

	}
}

void StudentIdSortStudents(std::vector<Student> &students){
	int i;
	for (i = 0; i < students.size()-1; i++) {
		int min=i;
		for (int j = i+1; j < students.size(); j++) {
			if (students[min].getAvg()<students[j].getAvg())
				min=j;
			if(min!=i){
				Student tmp;
				tmp=students[i];
				students[i]=students[min];
				students[min] = tmp;
			}
		}

	}
}

void StudentAvgSortStudents(std::vector<Student> &students){
	int i;

	for (i = 0; i < students.size()-1; i++) {
		int min=i;
		for (int j = i+1; j < students.size(); j++) {
			if (students[min].getAvg()<students[j].getAvg())
				min=j;
			if(min!=i){
				Student tmp;
				tmp=students[i];
				students[i]=students[min];
				students[min] = tmp;
			}
		}

	}
}

std::vector <std::string> changeStudentFormat(std::vector <Student> &students){
	std::vector <std::string> result;
	for(int i=0;i<students.size();i++){
		std::string line;
		line.append("\t"+students[i].getName());
		line.append("\t\t"+students[i].getId());
		line.append("\t\t"+students[i].getMajor());
		line.append("\t\t"+students[i].getBanji());
		line.append("\t"+std::to_string(students[i].getMath()));
		line.append("\t"+std::to_string(students[i].getEng()));
		line.append("\t"+std::to_string(students[i].getChinese()));
		line.append("\t"+std::to_string(students[i].getAvg()));
		result[i]=line;
	}

	return result;
}

void changeStudentFormat(std::string &line){
	std::stringstream s_stream(line);
	std::string result;
	int n=0;
	while(s_stream.good()){
		std::string substr;
		getline(s_stream,substr,',');
		if(n==0)result+=("\t"+substr);
		else if(n>0&&n<4) result+=("\t\t"+substr);
		else result+=("\t"+substr);
		n++;
	}
	line=result;
}

__fastcall TSortForm::TSortForm(TComponent* Owner)
	: TForm(Owner)
{
	std::ifstream teacherStudents(getPath()+getCurrentUsername()+".txt");
	std::string student;
	int n=0;
	while(getline(teacherStudents,student)){
		changeStudentFormat(student);
		if(n!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(student.c_str());
		n++;
	}
	teacherStudents.close();
}
//---------------------------------------------------------------------------
void __fastcall TSortForm::ReturnButtonClick(TObject *Sender)
{
	SortForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::NameSortButtonClick(TObject *Sender)
{
	std::ifstream teacherStudents(getPath()+getCurrentUsername()+".txt");
	Student student;
	int n=0;
	std::vector<Student> students;

	int i=0;
	/*while(teacherStudents>>student){
		students[i++]=student;
	} */
	teacherStudents.close();

	NameSortStudents(students);

	for(int i=0;i<students.size()*2;i++)StudentListBox->Items->Delete(0);

	std::vector <std::string> StringStudents=changeStudentFormat(students);
	for(int i=0;i<students.size();i++){
		if(i!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(StringStudents[i].c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::StudentIdSortButtonClick(TObject *Sender)
{
	std::ifstream teacherStudents(getPath()+getCurrentUsername()+".txt");
	Student student;
	int n=0;
	std::vector<Student> students;

	int i=0;
	/*while(teacherStudents>>student){
		students[i++]=student;
	} */
	teacherStudents.close();

	StudentIdSortStudents(students);

	for(int i=0;i<students.size()*2;i++)StudentListBox->Items->Delete(0);


	std::vector <std::string> StringStudents=changeStudentFormat(students);

	for(int i=0;i<students.size();i++){
		if(i!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(StringStudents[i].c_str());
	}
}
//---------------------------------------------------------------------------

void __fastcall TSortForm::AvgSortButtonClick(TObject *Sender)
{
	std::ifstream teacherStudents(getPath()+getCurrentUsername()+".txt");
	teacherStudents.close();
	Student student;
	int n=0;
	std::vector<Student> students;

	int i=0;
	while(teacherStudents>>student){
		students[i++]=student;
	}
	teacherStudents.close();
	/*StudentAvgSortStudents(students);

	for(int i=0;i<students.size()*2;i++)StudentListBox->Items->Delete(0);

	std::vector <std::string> StringStudents=changeStudentFormat(students);

	for(int i=0;i<students.size();i++){
		if(i!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(StringStudents[i].c_str());
	} */
}
//---------------------------------------------------------------------------

