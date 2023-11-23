//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "path.h"
#include "View.h"
#include <fstream>
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TViewForm *ViewForm;
//---------------------------------------------------------------------------
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
__fastcall TViewForm::TViewForm(TComponent* Owner)
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
void __fastcall TViewForm::ReturnButtonClick(TObject *Sender)
{
	   ViewForm->Close();
}
//---------------------------------------------------------------------------
