//---------------------------------------------------------------------------

#ifndef NavigacijaH
#define NavigacijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TNavigacijaForma : public TForm
{
__published:	// IDE-managed Components
	TButton *BrojButton;
	TButton *SpajanjeButton;
	TButton *AsocijacijeButton;
	TButton *VjesalaButton;
	TButton *ZaokruziButton;
	TText *UkupniBodovi;
	void __fastcall BrojButtonClick(TObject *Sender);
	void __fastcall SpajanjeButtonClick(TObject *Sender);
	void __fastcall AsocijacijeButtonClick(TObject *Sender);
	void __fastcall VjesalaButtonClick(TObject *Sender);
	void __fastcall ZaokruziButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TNavigacijaForma(TComponent* Owner);
    int ukupni_bodovi;
};
//---------------------------------------------------------------------------
extern PACKAGE TNavigacijaForma *NavigacijaForma;
//---------------------------------------------------------------------------
#endif
