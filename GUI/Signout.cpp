//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Signout.h"
#include "Home.h"
#include "path.h"
#include "Login.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TSignoutForm *SignoutForm;
//---------------------------------------------------------------------------
__fastcall TSignoutForm::TSignoutForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSignoutForm::YesButtonClick(TObject *Sender)
{
		std::ofstream f(getPath()+"temp.txt");
		f<<"";
		f.close();
		HomeForm->Close();
		LoginForm->Show();
		SignoutForm->Close();
}
//---------------------------------------------------------------------------
void __fastcall TSignoutForm::NoButtonClick(TObject *Sender)
{
		SignoutForm->Close();
}
//---------------------------------------------------------------------------
