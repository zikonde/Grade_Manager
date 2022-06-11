//---------------------------------------------------------------------------

#ifndef SortH
#define SortH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TSortForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TButton *ReturnButton;
	TListBox *StudentListBox;
	TLabel *Label9;
	TButton *NameSortButton;
	TButton *StudentIdSortButton;
	TButton *AvgSortButton;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	void __fastcall ReturnButtonClick(TObject *Sender);
	void __fastcall NameSortButtonClick(TObject *Sender);
	void __fastcall StudentIdSortButtonClick(TObject *Sender);
	void __fastcall AvgSortButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSortForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSortForm *SortForm;
//---------------------------------------------------------------------------
#endif
