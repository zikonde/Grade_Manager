//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "path.h"
#include "Home.h"
#include "Signout.h"
#include "View.h"
#include "Edit.h"
#include "DeleteStudent.h"
#include "SearchStudent.h"
#include "Unit1.h"
#include "Sort.h"
#include "Averages.h"
#include "AddStudent.h"
#include <fstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
THomeForm *HomeForm;
//---------------------------------------------------------------------------
__fastcall THomeForm::THomeForm(TComponent* Owner)
	: TForm(Owner)
{
	std::string usernameString;
	std::ifstream temp_file(getPath()+"temp.txt");
	temp_file>>usernameString;
	usernameString+=" ÀÏÊ¦";
	temp_file.close();
	NameLabel->Text=usernameString.c_str();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::SignoutButtonClick(TObject *Sender)
{
	Application->CreateForm(__classid(TSignoutForm), &SignoutForm);
	SignoutForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall THomeForm::ViewButtonClick(TObject *Sender)
{
	Application->CreateForm(__classid(TViewForm), &ViewForm);
	ViewForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::AddButtonClick(TObject *Sender)
{
	Application->CreateForm(__classid(TAddStudentForm), &AddStudentForm);
	AddStudentForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall THomeForm::EditButtonClick(TObject *Sender)
{
    EditForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall THomeForm::DeleteStudentButtonClick(TObject *Sender)
{
	DeleteStudentForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::SearchButtonClick(TObject *Sender)
{
    SearchStudentForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::AveragesButtonClick(TObject *Sender)
{
	 AveragesForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall THomeForm::SortButtonClick(TObject *Sender)
{
//	Application->CreateForm(__classid(TSortForm), &SortForm);
	Form1->Show();
//     SortForm->Show();
}
//---------------------------------------------------------------------------

