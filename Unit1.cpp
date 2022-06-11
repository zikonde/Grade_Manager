//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "path.h"
#include <sstream>
#include <string>
#include <vector>
#include "student.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

std::vector<std::string> NameSortStudents(std::vector<std::string> &students){
	int i;
	std::vector<std::string> names;
	for(i=0;i<students.size();i++){
		std::string substr;
		std::stringstream s_stream(students[i]);
		getline(s_stream,substr,',');
		names.push_back(substr);
	}

	for (i = 0; i < students.size()-1; i++) {
		int min=i;
		for (int j = i+1; j < students.size(); j++) {
			if (std::strcmp(names[j].c_str(),names[min].c_str())<0)
				min=j;
			if(min!=i){
				std::string tmp,tmp2;
				tmp=students[i];
				students[i]=students[min];
				students[min] = tmp;
				tmp2=names[i];
				names[i]=names[min];
				names[min]=tmp2;
			}
		}

	}
		  return students;
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

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ReturnButtonClick(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NameSortButtonClick(TObject *Sender)
{
	std::ifstream teacherStudents(getPath()+getCurrentUsername()+".txt");
	Student student;
	int n=0;
	std::vector<Student> students;

    int i=0;
	while(teacherStudents>>student){
		students[i++]=student;
	}
	teacherStudents.close();

  /*	students=NameSortStudents(students);

	for(int i=0;i<students.size()*2;i++)StudentListBox->Items->Delete(0);

	for(int i=0;i<students.size();i++){
		changeStudentFormat(students[i]);
		if(i!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(students[i].c_str());
	}

	while(getline(teacherStudents,student)){
		students.push_back(student);
		if(n!=0) StudentListBox->Items->Add(" ");
		StudentListBox->Items->Add(student.c_str());
		n++;
	}
	*/
}
//---------------------------------------------------------------------------
