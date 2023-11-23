//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AddStudent.h"
#include <fstream>
#include "path.h"
#include <string>
#include "student.h"
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TAddStudentForm *AddStudentForm;
//---------------------------------------------------------------------------
__fastcall TAddStudentForm::TAddStudentForm(TComponent* Owner)
	: TForm(Owner)
{
	ContinueButton->Enabled=false;
	SaveButton->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TAddStudentForm::ReturnButtonClick(TObject *Sender)
{
		 AddStudentForm->Close();
}
//---------------------------------------------------------------------------
double ToDouble(String SSS){
	AnsiString sss= SSS;
	return std::stod(sss.c_str());
}
std::string ToSString(String SSS){
	AnsiString sss= SSS;
	return sss.c_str();
}
void __fastcall TAddStudentForm::SaveButtonClick(TObject *Sender)
{
	if(NameEdit->Text==""||StudentIdEdit->Text==""||MajorEdit->Text==""
		||BanjiEdit->Text==""||MathEdit->Text==""||EnglishEdit->Text==""
		||ChineseEdit->Text==""){
		ProgressLabel->Text="*必须填完才能保存";
	}
	else{
		std::string name=ToSString(NameEdit->Text),id=ToSString(StudentIdEdit->Text),major=ToSString(MajorEdit->Text),banji=ToSString(BanjiEdit->Text);
		double  math=ToDouble(MathEdit->Text),eng=ToDouble(EnglishEdit->Text),chi=ToDouble(ChineseEdit->Text);
		Student student(name,id,major,banji,math,eng,chi);
		std::ofstream teacherStudents(getPath()+getCurrentUsername()+".txt",ios::app);
		teacherStudents<<student;
		//Student student();
		//teacherStudents<<student;
		teacherStudents.close();

		ProgressLabel->Text="保存完毕！";
		ContinueButton->Enabled=true;
		SaveButton->Enabled=false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TAddStudentForm::ContinueButtonClick(TObject *Sender)
{
		ProgressLabel->Text="";
		NameEdit->Text="";
		StudentIdEdit->Text="";
		MajorEdit->Text="";
		BanjiEdit->Text="";
		MathEdit->Text="";
		EnglishEdit->Text="";
		ChineseEdit->Text="";
		ContinueButton->Enabled=false;
		SaveButton->Enabled=true;
}
//---------------------------------------------------------------------------
