//---------------------------------------------------------------------------

#ifndef SpajanjeH
#define SpajanjeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TSpajanjeForma : public TForm
{
__published:	// IDE-managed Components
	TButton *IzlazButton;
	void __fastcall IzlazButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSpajanjeForma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSpajanjeForma *SpajanjeForma;
//---------------------------------------------------------------------------
#endif
