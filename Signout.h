//---------------------------------------------------------------------------

#ifndef SignoutH
#define SignoutH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TSignoutForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *YesButton;
	TButton *NoButton;
	void __fastcall YesButtonClick(TObject *Sender);
	void __fastcall NoButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSignoutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSignoutForm *SignoutForm;
//---------------------------------------------------------------------------
#endif
