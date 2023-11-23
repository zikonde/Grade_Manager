//---------------------------------------------------------------------------

#ifndef AddStudentH
#define AddStudentH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Filter.Effects.hpp>
//---------------------------------------------------------------------------
class TAddStudentForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ReturnButton;
	TEdit *NameEdit;
	TLabel *Label1;
	TButton *SaveButton;
	TShapeTransitionEffect *ShapeTransitionEffect1;
	TEdit *StudentIdEdit;
	TLabel *Label2;
	TEdit *MathEdit;
	TLabel *Label3;
	TEdit *EnglishEdit;
	TLabel *Label4;
	TEdit *MajorEdit;
	TLabel *Label5;
	TEdit *ChineseEdit;
	TLabel *Label6;
	TEdit *BanjiEdit;
	TLabel *Label7;
	TLabel *ProgressLabel;
	TButton *ContinueButton;
	void __fastcall ReturnButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall ContinueButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddStudentForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddStudentForm *AddStudentForm;
//---------------------------------------------------------------------------
#endif
