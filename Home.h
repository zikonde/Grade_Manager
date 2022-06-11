//---------------------------------------------------------------------------

#ifndef HomeH
#define HomeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Effects.hpp>
#include <FMX.Filter.Effects.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class THomeForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *SignoutButton;
	TButton *ViewButton;
	TLabel *Label1;
	TLabel  *NameLabel;
	TButton *AddButton;
	TShapeTransitionEffect *ShapeTransitionEffect1;
	TButton *EditButton;
	TButton *DeleteStudentButton;
	TButton *SearchButton;
	TButton *SortButton;
	TButton *AveragesButton;
	TImage *Image1;
	TImage *Image2;
	void __fastcall SignoutButtonClick(TObject *Sender);
	void __fastcall ViewButtonClick(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall EditButtonClick(TObject *Sender);
	void __fastcall DeleteStudentButtonClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall SortButtonClick(TObject *Sender);
	void __fastcall AveragesButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall THomeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THomeForm *HomeForm;
//---------------------------------------------------------------------------
#endif
